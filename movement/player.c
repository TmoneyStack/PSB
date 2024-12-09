#include <pspkernel.h>
#include <pspgu.h>
#include <pspctrl.h>
#include <pspdisplay.h>

typedef struct {
    //position info
    int x, y;
    int size, moveSpeed;

} Player;

typedef struct {
    unsigned short u, v;
    short x, y, z;
} Vertex;

Player* newPlayer(int Px, int Py, int Psize, int Pspeed){
    Player* player = (Player*)sceGuGetMemory(sizeof(Player));
    player->size = Psize;
    player->x = Px; 
    player->y = Py;
    player->moveSpeed = Pspeed;
    return player;
}

void drawRect(float x, float y, float w, float h) {

    Vertex* vertices = (Vertex*)sceGuGetMemory(2 * sizeof(Vertex));

    vertices[0].x = x;
    vertices[0].y = y;

    vertices[1].x = x + w;
    vertices[1].y = y + h;

    sceGuColor(0xFF0FFF0A); // Red, colors are ABGR
    sceGuDrawArray(GU_SPRITES, GU_TEXTURE_16BIT | GU_VERTEX_16BIT | GU_TRANSFORM_2D, 2, 0, vertices);
}

int printPlayer(Player * p){
    drawRect(p->x , p->y, p->size, p->size);
    return 0;
}