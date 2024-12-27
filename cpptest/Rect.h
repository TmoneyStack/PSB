#ifndef RECT_H    //header guard
#define RECT_H    //header guard

#include <pspkernel.h>
#include <pspgu.h>
#include <pspctrl.h>
#include <pspdisplay.h>

typedef struct 
{
    unsigned short u, v;
    short x, y, z;
} Vertex;

void drawRect(float x, float y, float w, float h, unsigned int c);

void drawTestingArea(int dist);

#endif //RECT_H