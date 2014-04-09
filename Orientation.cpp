/* 
 * File:   Orientation.cpp
 * Author: XorFish
 * 
 * Created on 2. April 2014, 08:44
 */

#include "Orientation.h"

Orientation::Orientation() 
{
    setOrientation(Obstacle::front, Obstacle::r0);
}
Orientation::Orientation(Obstacle::side Side,Obstacle::rotation Rotation) 
{
    setOrientation(Side, Rotation);
}
Obstacle::side Orientation::getSide()
{
    return side;
}
Obstacle::rotation Orientation::getRotation()
{
    return rotation;
}
void Orientation::setSide(Obstacle::side Side)
{
    side=Side;
}
void Orientation::setRotation(Obstacle::rotation Rotation)
{
    rotation=Rotation;
}
void Orientation::setOrientation(Obstacle::side Side,Obstacle::rotation Rotation)
{
        side=Side;
        rotation=Rotation;
}
void Orientation::Rotate(Direction d) 
{
    Obstacle::rotation rUp,rLeft,rRight,rDown,rTemp;
    Obstacle::side sUp,sLeft, sRight, sDown,sTemp;

        switch(side)
        {
            case Obstacle::front:
                
                sUp=Obstacle::top;
                rUp=Obstacle::r0;
                
                sLeft=Obstacle::left;
                rLeft=Obstacle::r0;
                
                sRight=Obstacle::right;
                rRight=Obstacle::r0;
                
                sDown=Obstacle::bottom;
                rDown=Obstacle::r0;
                break;
                
            case Obstacle::left:
                
                sUp=Obstacle::top;
                rUp=Obstacle::r90;
                
                sLeft=Obstacle::back;
                rLeft=Obstacle::r0;
                
                sRight=Obstacle::front;
                rRight=Obstacle::r0;
                
                sDown=Obstacle::bottom;
                rDown=Obstacle::r270;
                break;
                
            case Obstacle::right:
                
                sUp=Obstacle::top;
                rUp=Obstacle::r270;
                
                sLeft=Obstacle::front;
                rLeft=Obstacle::r0;
                
                sRight=Obstacle::back;
                rRight=Obstacle::r0;
                
                sDown=Obstacle::bottom;
                rDown=Obstacle::r90;
                break;
                
            case Obstacle::back:
                 
                sUp=Obstacle::top;
                rUp=Obstacle::r180;
                
                sLeft=Obstacle::right;
                rLeft=Obstacle::r0;
                
                sRight=Obstacle::left;
                rRight=Obstacle::r0;
                
                sDown=Obstacle::bottom;
                rDown=Obstacle::r180;
                break;
                
            case Obstacle::top: 
                 
                sUp=Obstacle::back;
                rUp=Obstacle::r180;
                
                sLeft=Obstacle::left;
                rLeft=Obstacle::r270;
                
                sRight=Obstacle::right;
                rRight=Obstacle::r90;
                
                sDown=Obstacle::front;
                rDown=Obstacle::r0;
                break;
                
            case Obstacle::bottom:
                 
                sUp=Obstacle::front;
                rUp=Obstacle::r0;
                
                sLeft=Obstacle::left;
                rLeft=Obstacle::r90;
                
                sRight=Obstacle::right;
                rRight=Obstacle::r270;
                
                sDown=Obstacle::back;
                rDown=Obstacle::r180;
                break;
        }
        switch (rotation)
        {
            case Obstacle::r90:
                sTemp=sUp;
                sUp=sRight;
                sRight=sDown;
                sDown=sLeft;
                sLeft=sTemp;
                
                rTemp=rUp;
                rUp=(Obstacle::rotation)((rRight+(int)Obstacle::r90)%4);
                rRight=(Obstacle::rotation)((rDown+(int)Obstacle::r90)%4);
                rDown=(Obstacle::rotation)((rLeft+(int)Obstacle::r90)%4);
                rLeft=(Obstacle::rotation)((rTemp+(int)Obstacle::r90)%4);
                break;
            case Obstacle::r180:
                sTemp=sUp;
                sUp=sDown;
                sDown=sTemp;
                
                sTemp=sRight;
                sRight=sLeft;
                sLeft=sTemp;
                
                rTemp=rUp;
                rUp=(Obstacle::rotation)((rDown+(int)Obstacle::r180)%4);
                rDown=(Obstacle::rotation)((rTemp+(int)Obstacle::r180)%4);
                rTemp=rRight;
                rRight=(Obstacle::rotation)((rLeft+(int)Obstacle::r180)%4);
                rLeft=(Obstacle::rotation)((rTemp+(int)Obstacle::r180)%4);
                break;
            case Obstacle::r270:
                sTemp=sUp;
                sUp=sLeft;
                sLeft=sDown;
                sDown=sRight;
                sRight=sTemp;
                
                rTemp=rUp;
                rUp=(Obstacle::rotation)((rLeft+(int)Obstacle::r270)%4);
                rLeft=(Obstacle::rotation)((rDown+(int)Obstacle::r270)%4);
                rDown=(Obstacle::rotation)((rRight+(int)Obstacle::r270)%4);
                rRight=(Obstacle::rotation)((rTemp+(int)Obstacle::r270)%4);
                break;
        }
        switch (d)
        {
            case up:
                side=sUp;
                rotation=rUp;
                break;
            case down:
                side=sDown;
                rotation=rDown;
                break;
            case right:
                side=sRight;
                rotation=rRight;
                break;
            case left:
                side=sLeft;
                rotation=rLeft;
                break;
        }
        
}

/*Orientation::Orientation(const Orientation& orig) {
}

Orientation::~Orientation() {
}*/

