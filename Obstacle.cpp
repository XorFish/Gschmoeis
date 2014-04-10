/* 
 * File:   Obstacle.cpp
 * Author: XorFish
 * 
 * Created on 19. März 2014, 08:52
 */

#include <SFML/System/Vector2.hpp>

#include "Obstacle.h"
#include "Vector.h"
Obstacle::Obstacle(Vector Size, Vector Position, sf::Color Color, Vector Playfield) 
{
    size=Size;
    position=Position;
    color=Color;
    playfield=Playfield;
}
void Obstacle::setSize(Vector Size)
{
    size=Size;
}
Vector Obstacle::getSize(void)
{
    return size;
}
void Obstacle::setPosition(Vector Position)
{
    position=Position;
}
Vector Obstacle::getPosition(void)
{
    return position;
}
void Obstacle::setColor(sf::Color Color)
{
    color=Color;
}
sf::Color Obstacle::getColor(void)
{
    return color;
}
sf::Vector2f Obstacle::getProjectedSize(side Direction, rotation Rotation)
{
    Vector result(0,0);
    switch(Direction)
    {
        case front:
                result.setVector(size.x, -size.z);
                break;
        case right:
                result.setVector(-size.y, -size.z);
                break;
        case top:
                result.setVector(size.x, size.y);
                break;
        case back:
                result.setVector(-size.x, -size.z);
                break;
        case left:
                result.setVector(size.y, -size.z);
                break;
        case bottom:
                result.setVector(size.x, -size.y);
                break;
    }
    switch(Rotation)
    {
        case r270:
            result.setVector(-result.y,result.x);
            break;
        case r90:
            result.setVector(result.y,-result.x);
            break;
        case r180:
            result.setVector(-result.x,-result.y);
            break;
    }
    return sf::Vector2f(result.x,result.y);
}
sf::Vector2f Obstacle::getProjectedPosition(side Side, rotation Rotation)
{
    /**
     * 
     * @param Side: Seite der Projektion
     * @param Rotation: Rotation der Projektion
     * @return Vector 
     */
    Vector result(0,0);
    float h,w;
    switch(Side)
    {
        case front:
                h=playfield.z;
                w=playfield.x;
                result.setVector(position.x, h-position.z);
                break;
        case right:
                h=playfield.z;
                w=playfield.y;
                result.setVector(w-position.y, h-position.z);
                break;
        case top:
                h=playfield.y;
                w=playfield.x;
                result.setVector(position.x, position.y);
                break;
        case back:
                h=playfield.z;
                w=playfield.x;
                result.setVector(w-position.x, h-position.z);
                break;
        case left:
                h=playfield.z;
                w=playfield.y;
                result.setVector(position.y, h-position.z);
                break;
        case bottom:
                h=playfield.y;
                w=playfield.x;
                result.setVector(position.x, h-position.y);
                break;
    }
     switch(Rotation)
    {
        case r270:
            result.setVector(h-result.y,result.x);
            break;
        case r90:
            result.setVector(result.y,w-result.x);
            break;
        case r180:
            result.setVector(w-result.x,h-result.y);
            break;
    }
    return sf::Vector2f(result.x,result.y);
}

sf::Vector2f Obstacle::getProjectedZ(side Side) 
{
    sf::Vector2f Z(0,0);
    switch(Side)
    {
        case front:
            if(size.y>0)
                Z.x=playfield.y-(position.y+size.y);
            else
                Z.x=playfield.y-position.y;
            Z.y=size.y;
            break;
        case right:
             if(size.x>0)
                Z.x=playfield.x-(position.x+size.x);
            else
                Z.x=playfield.x-position.x;
            Z.y=size.x;
            break;
        case top:
             if(size.z<0)
                Z.x=position.z+size.z;
            else
                Z.x=position.z;
            Z.y=size.z;
            break;
        case back:
            if(size.y<0)
                Z.x=position.y+size.y;
            else
                Z.x=position.y;
            Z.y=size.y;
            break;
        case left:
            if(size.x<0)
                Z.x=position.x+size.x;
            else
                Z.x=position.x;
            Z.y=size.x;
            break;
        case bottom:
            if(size.z>0)
                Z.x=playfield.z-(position.z+size.z);
            else
                Z.x=playfield.z-position.z;
            Z.y=size.z;
            break;
            
    }
    
}
/*Obstacle::~Obstacle() 
{
}
*/
