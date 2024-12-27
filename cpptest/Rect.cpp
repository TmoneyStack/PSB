#include "Rect.h"

void Rect::drawRect(float x, float y, float w, float h, unsigned int c) {

    Vertex* vertices = (Vertex*)sceGuGetMemory(2 * sizeof(Vertex));

    vertices[0].x = x;
    vertices[0].y = y;

    vertices[1].x = x + w;
    vertices[1].y = y + h;

    sceGuColor(c); // Black, colors are ABGR
    sceGuDrawArray(GU_SPRITES, GU_TEXTURE_16BIT | GU_VERTEX_16BIT | GU_TRANSFORM_2D, 2, 0, vertices);
}

void Rect::drawTestingArea(int dist){
    for(int i = 0; i < 500; i += dist){
        for(int j = 0; j < 500; j += dist)
            drawRect(i, j, 1, 1, 0xFF000000);
    }
}