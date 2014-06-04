/* 
 * File:   Orientation.cpp
 * Author: XorFish
 * 
 * Created on 2. April 2014, 08:44
 */

#include "Orientation.h"

Orientation::Orientation() 
{
    setOrientation(Orientation::front, Orientation::r0);
}
Orientation::Orientation(Orientation::side Side,Orientation::rotation Rotation) 
{
    setOrientation(Side, Rotation);
}
Orientation::side Orientation::getSide()
{
    return side_p;
}
Orientation::rotation Orientation::getRotation()
{
    return rotation_p;
}
void Orientation::setSide(Orientation::side Side)
{
    side_p=Side;
}
void Orientation::setRotation(Orientation::rotation Rotation)
{
    rotation_p=Rotation;
}
void Orientation::setOrientation(Orientation::side Side,Orientation::rotation Rotation)
{
        side_p=Side;
        rotation_p=Rotation;
}

void Orientation::Rotate(Direction d) 
{
    Orientation::rotation rUp,rLeft,rRight,rDown,rTemp;
    Orientation::side sUp,sLeft, sRight, sDown,sTemp;

        switch(side_p)
        {
            case Orientation::front:
                
                sUp=Orientation::top;
                rUp=Orientation::r0;
                
                sLeft=Orientation::left;
                rLeft=Orientation::r0;
                
                sRight=Orientation::right;
                rRight=Orientation::r0;
                
                sDown=Orientation::bottom;
                rDown=Orientation::r0;
                break;
                
            case Orientation::left:
                
                sUp=Orientation::top;
                rUp=Orientation::r90;
                
                sLeft=Orientation::back;
                rLeft=Orientation::r0;
                
                sRight=Orientation::front;
                rRight=Orientation::r0;
                
                sDown=Orientation::bottom;
                rDown=Orientation::r270;
                break;
                
            case Orientation::right:
                
                sUp=Orientation::top;
                rUp=Orientation::r270;
                
                sLeft=Orientation::front;
                rLeft=Orientation::r0;
                
                sRight=Orientation::back;
                rRight=Orientation::r0;
                
                sDown=Orientation::bottom;
                rDown=Orientation::r90;
                break;
                
            case Orientation::back:
                 
                sUp=Orientation::top;
                rUp=Orientation::r180;
                
                sLeft=Orientation::right;
                rLeft=Orientation::r0;
                
                sRight=Orientation::left;
                rRight=Orientation::r0;
                
                sDown=Orientation::bottom;
                rDown=Orientation::r180;
                break;
                
            case Orientation::top: 
                 
                sUp=Orientation::back;
                rUp=Orientation::r180;
                
                sLeft=Orientation::left;
                rLeft=Orientation::r270;
                
                sRight=Orientation::right;
                rRight=Orientation::r90;
                
                sDown=Orientation::front;
                rDown=Orientation::r0;
                break;
                
            case Orientation::bottom:
                 
                sUp=Orientation::front;
                rUp=Orientation::r0;
                
                sLeft=Orientation::left;
                rLeft=Orientation::r90;
                
                sRight=Orientation::right;
                rRight=Orientation::r270;
                
                sDown=Orientation::back;
                rDown=Orientation::r180;
                break;
        }
        switch (rotation_p)
        {
            case Orientation::r90:
                sTemp=sUp;
                sUp=sRight;
                sRight=sDown;
                sDown=sLeft;
                sLeft=sTemp;
                
                rTemp=rUp;
                rUp=(Orientation::rotation)((rRight+(int)Orientation::r90)%4);
                rRight=(Orientation::rotation)((rDown+(int)Orientation::r90)%4);
                rDown=(Orientation::rotation)((rLeft+(int)Orientation::r90)%4);
                rLeft=(Orientation::rotation)((rTemp+(int)Orientation::r90)%4);
                break;
            case Orientation::r180:
                sTemp=sUp;
                sUp=sDown;
                sDown=sTemp;
                
                sTemp=sRight;
                sRight=sLeft;
                sLeft=sTemp;
                
                rTemp=rUp;
                rUp=(Orientation::rotation)((rDown+(int)Orientation::r180)%4);
                rDown=(Orientation::rotation)((rTemp+(int)Orientation::r180)%4);
                rTemp=rRight;
                rRight=(Orientation::rotation)((rLeft+(int)Orientation::r180)%4);
                rLeft=(Orientation::rotation)((rTemp+(int)Orientation::r180)%4);
                break;
            case Orientation::r270:
                sTemp=sUp;
                sUp=sLeft;
                sLeft=sDown;
                sDown=sRight;
                sRight=sTemp;
                
                rTemp=rUp;
                rUp=(Orientation::rotation)((rLeft+(int)Orientation::r270)%4);
                rLeft=(Orientation::rotation)((rDown+(int)Orientation::r270)%4);
                rDown=(Orientation::rotation)((rRight+(int)Orientation::r270)%4);
                rRight=(Orientation::rotation)((rTemp+(int)Orientation::r270)%4);
                break;
        }
        switch (d)
        {
            case Up:
                side_p=sUp;
                rotation_p=rUp;
                break;
            case Down:
                side_p=sDown;
                rotation_p=rDown;
                break;
            case Right:
                side_p=sRight;
                rotation_p=rRight;
                break;
            case Left:
                side_p=sLeft;
                rotation_p=rLeft;
                break;
        }
        
}
Orientation Orientation::Rotate(side s, rotation r, Direction d)
{
    Orientation temp(s,r);
    temp.Rotate(d);
    return temp;  
}
Orientation Orientation::Rotate(Orientation o, Direction d)
{
    o.Rotate(d);
    return o; 
}
/*Orientation::Orientation(const Orientation& orig) {
}

Orientation::~Orientation() {
}*/

