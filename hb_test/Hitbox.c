#include <pspkernel.h>
#include <pspgu.h>
#include <pspctrl.h>
#include <pspdisplay.h>

#include <stdbool.h>
#include "Rect.c"
#include <stdlib.h>

const int PLAYER_SPEED = 5; //px per step??

typedef struct {
    int pos[2];     // middle / origin (x,y)
    int dist[2];    // distance from x, distance from y (size)
    int speed;
    unsigned int color;
} Hitbox;

Hitbox* newHitBox(int x, int y, int length, int width, unsigned int c){
    Hitbox* newHit = (Hitbox*)malloc(sizeof(Hitbox));
    newHit->pos[0] = x;
    newHit->pos[1] = y;
    newHit->dist[0] = width/2;
    newHit->dist[1] = length/2;
    newHit->speed = PLAYER_SPEED;
    newHit->color = c;
    return newHit;
}

int hbMin(Hitbox* hb, bool axis){       // axis: 0=x, 1=y
    return hb->pos[axis] - hb->dist[axis];
}

int hbMax(Hitbox* hb, bool axis){       // axis: 0=x, 1=y
    return hb->pos[axis] + hb->dist[axis];
}

// check if 2 hitboxes are intersecting on x and y
bool isIntersect(Hitbox* ob1, Hitbox* ob2){
    for(int i = 0; i < 2; i++){
        if(hbMin(ob1, i) > hbMax(ob2, i))
            return false;
        if(hbMax(ob1, i) < hbMin(ob2, i))
            return false;
    }
    return true;
}

void hbDraw(Hitbox *hb){
    Vertex* vertices = (Vertex*)sceGuGetMemory(2 * sizeof(Vertex));

    vertices[0].x = hbMin(hb, 0);
    vertices[0].y = hbMin(hb, 1);

    vertices[1].x = hbMax(hb, 0);
    vertices[1].y = hbMax(hb, 1);

    sceGuColor(hb->color); // Red, colors are ABGR
    sceGuDrawArray(GU_SPRITES, GU_TEXTURE_16BIT | GU_VERTEX_16BIT | GU_TRANSFORM_2D, 2, 0, vertices);
}

void stepMoveLeft(Hitbox* player, Hitbox* hbStale){
    for(int i = 0; i < PLAYER_SPEED; i++){
        player->pos[0] -= 1;
        if(isIntersect(player, hbStale)){
            player->pos[0] += 1;
            break;
        }
    }
}

void stepMoveRight(Hitbox* player, Hitbox* hbStale){
    for(int i = 0; i < PLAYER_SPEED; i++){
        player->pos[0] += 1;
        if(isIntersect(player, hbStale)){
            player->pos[0] -= 1;
            break;
        }
    }
}

void stepMoveUp(Hitbox* player, Hitbox* hbStale){
    for(int i = 0; i < PLAYER_SPEED; i++){
        player->pos[1] -= 1;
        if(isIntersect(player, hbStale)){
            player->pos[1] += 1;
            break;
        }
    }
}

void stepMoveDown(Hitbox* player, Hitbox* hbStale){
    for(int i = 0; i < PLAYER_SPEED; i++){
        player->pos[1] += 1;
        if(isIntersect(player, hbStale)){
            player->pos[1] -= 1;
            break;
        }
    }
}

void checkInput(Hitbox* hb, SceCtrlData pad, Hitbox* temp){
    if (pad.Buttons != 0)
    {
        if (pad.Buttons & PSP_CTRL_UP)
            {   
                stepMoveUp(hb, temp);
            }
            if (pad.Buttons & PSP_CTRL_DOWN)
            {
                stepMoveDown(hb, temp);
            }
            if (pad.Buttons & PSP_CTRL_LEFT)
            {
                stepMoveLeft(hb, temp);
            }
            if (pad.Buttons & PSP_CTRL_RIGHT)
            {
                stepMoveRight(hb, temp);
            }
            if (pad.Buttons & PSP_CTRL_CROSS)
            {
                // hb->color += 50;
            }
            if (pad.Buttons & PSP_CTRL_CIRCLE)
            {
                
            }   
            if (pad.Buttons & PSP_CTRL_TRIANGLE)
            {
                
            }
    }
    
}