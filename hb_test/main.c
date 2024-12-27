#include <pspkernel.h>
#include <pspgu.h>
#include <pspctrl.h>
#include <pspdisplay.h>

#include "Hitbox.c"

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

    Hitbox* hb1 = newHitBox(100, 100, 50, 50, 0X0000FFAD);
    Hitbox* hb2 = newHitBox(200, 200, 50, 50, 0X00FF00AD);

    running = 1;
    
    while(running){
        startFrame();
        
        // setup controller sample 
        sceCtrlReadBufferPositive(&pad, 1);
        
        // screen draw order
        drawTestingArea(100);
        hbDraw(hb1);
        hbDraw(hb2);
        
        // switch between controlling hitboxes with circle
        if (pad.Buttons & PSP_CTRL_CIRCLE)
            checkInput(hb1, pad, hb2);
        else
            checkInput(hb2, pad, hb1);
        
        
        // check for player intersection 
            // green if intersecting
            // red if no intersection
        if(!isIntersect(hb1, hb2)) 
            drawRect(305, 100, 25, 50, 0xFF0000FF);
        else  
           drawRect(305, 100, 25, 50, 0xFF00FF00);

        endFrame();
    }
    
    free(hb1);
    free(hb2);
    return 0;
}
