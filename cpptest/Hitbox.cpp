#include "Hitbox.h"

Hitbox::Hitbox(): m_pos{100, 100}, m_dist{50, 50},
                  m_speed(PLAYER_SPEED), m_color(0xFF000000)
{

}

Hitbox::Hitbox(int x, int y, int length, int width, unsigned int color):
        m_pos{x, y}, m_dist{width/2, length/2}, m_speed(PLAYER_SPEED), m_color(color)
{

}

//todo insert def for Copy Constr & assigment opp

//accesser & mutator definitions
int Hitbox::getX(){return m_pos[0];}
void Hitbox::setX(int x){m_pos[0]=x;}
int Hitbox::getY(){return m_pos[1];}
void Hitbox::setY(int y){m_pos[1]=y;}
int Hitbox::getWidth(){return m_dist[0]*2;}
void Hitbox::setWidth(int width){m_dist[0]=width/2;}
int Hitbox::getLength(){return m_dist[1]*2;}
void Hitbox::setLength(int length){m_dist[0]=length/2;}
int Hitbox::getSpeed(){return m_speed;}
void Hitbox::setSpeed(int speed){m_speed = speed;}
unsigned int Hitbox::getColor(){return m_color;}
void Hitbox::setColor(unsigned int color){m_color = color;}


int Hitbox::hbMin(bool axis)
{       
    return m_pos[axis] - m_dist[axis];
}

int Hitbox::hbMax(bool axis)    
{       
    return m_pos[axis] + m_dist[axis];
}

bool Hitbox::isIntersect(Hitbox* other)
{
    for(int i = 0; i < 2; i++){
        if(hbMin(i) > other->hbMax(i))
            return false;
        if(hbMax(i) < other->hbMin(i))
            return false;
    }
    return true;
}

