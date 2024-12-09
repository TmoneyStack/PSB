#include <pspkernel.h>
#include <pspgu.h>
#include <pspctrl.h>
#include <pspdisplay.h>
#include "player.c"

PSP_MODULE_INFO("movement", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_VFPU | THREAD_ATTR_USER);

#define BUFFER_WIDTH 512
#define BUFFER_HEIGHT 272
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT BUFFER_HEIGHT

char list[0x20000] __attribute__((aligned(64)));
int running;

int exit_callback(int arg1, int arg2, void *common) {
    running = 0;
    return 0;
}

int callback_thread(SceSize args, void *argp) {
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);
    sceKernelSleepThreadCB();
    return 0;
}

int setup_callbacks(void) {
    int thid = sceKernelCreateThread("update_thread", callback_thread, 0x11, 0xFA0, 0, 0);
    if(thid >= 0)
        sceKernelStartThread(thid, 0, 0);
    return thid;
}

void initGu(){
    sceGuInit();

    //Set up buffers
    sceGuStart(GU_DIRECT, list);
    sceGuDrawBuffer(GU_PSM_8888,(void*)0,BUFFER_WIDTH);
    sceGuDispBuffer(SCREEN_WIDTH,SCREEN_HEIGHT,(void*)0x88000,BUFFER_WIDTH);
    sceGuDepthBuffer((void*)0x110000,BUFFER_WIDTH);

    //Set up viewport
    sceGuOffset(2048 - (SCREEN_WIDTH / 2), 2048 - (SCREEN_HEIGHT / 2));
    sceGuViewport(2048, 2048, SCREEN_WIDTH, SCREEN_HEIGHT);
    sceGuEnable(GU_SCISSOR_TEST);
    sceGuScissor(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    //Set some stuff
    sceGuDepthRange(65535, 0); //Use the full buffer for depth testing - buffer is reversed order

    sceGuDepthFunc(GU_GEQUAL); //Depth buffer is reversed, so GEQUAL instead of LEQUAL
    sceGuEnable(GU_DEPTH_TEST); //Enable depth testing

    sceGuFinish();
    sceGuDisplay(GU_TRUE);
}

void endGu(){
    sceGuDisplay(GU_FALSE);
    sceGuTerm();
}

void startFrame(){
    sceGuStart(GU_DIRECT, list);
    sceGuClearColor(0xFFFFFFFF); // White background
    sceGuClear(GU_COLOR_BUFFER_BIT);
}

void endFrame(){
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}


int main() {

    SceCtrlData pad;

    // Make exiting with the home button possible
    setup_callbacks();

    // Setup the library used for rendering
    initGu();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    Player* player = newPlayer(100, 100, 75, 5);

    running = 1;

    while(running){
        startFrame();

        sceCtrlReadBufferPositive(&pad, 1);

        if (pad.Buttons != 0)
        {
            if (pad.Buttons & PSP_CTRL_UP)
            {
		        player->y -= player->moveSpeed;
            }
            if (pad.Buttons & PSP_CTRL_DOWN)
            {
		        player->y += player->moveSpeed;
            }
            if (pad.Buttons & PSP_CTRL_LEFT)
            {
		        player->x -= player->moveSpeed;
            }
            if (pad.Buttons & PSP_CTRL_RIGHT)
            {
		        player->x += player->moveSpeed;
            }
            if (pad.Buttons & PSP_CTRL_CROSS)
            {
                
            }
            if (pad.Buttons & PSP_CTRL_CIRCLE)
            {
                
            }
            if (pad.Buttons & PSP_CTRL_TRIANGLE)
            {
                player->x = 100;
                player->y = 100;
                player->moveSpeed = 5;
            }
        }

        printPlayer(player);

        endFrame();
    }

    return 0;
}
