/* 
 * File:   Player.cpp
 * Author: XorFish
 * 
 * Created on 30. April 2014, 08:31
 */

#include "Player.h"
#include <math.h>

Player::Player(Vector Size, Vector Position, sf::Color Color, Vector Playfield, Orientation::Direction StartDirection, Orientation orientation):Obstacle(Size, Position, Color, Playfield) 
{
    direction=StartDirection;
    Last= (new Obstacle(Size, Position, Color, Playfield));
    orientation_P= orientation;  
}
Player::Player(void):Obstacle() 
{
}
Obstacle Player::Turn(Orientation::Direction dir)
{
   
        sf::Vector2f Size=getProjectedSize(orientation_P);
        sf::Vector2f Position=getProjectedPosition(orientation_P); 
        Obstacle temp=*Last;
        Last->setPosition(getPosition());
        Last->setSize(getSize());
        
        
        switch(direction)
        {
            case Orientation::Up:
                if(Size.x<0)
                    Position.x+=Size.x;
                if(Size.y<0)
                        Position.y+=Size.y;
                break;
            case Orientation::Down:
                if (Size.x<0)
                    Position.x+=Size.x;
                if (Size.y<0)
                    Position.y-=abs(Size.x);
                else
                    Position.y+=Size.y-abs(Size.x);
                break;
            case Orientation::Right:
                if (Size.y<0)
                    Position.y+=Size.y;
                if (Size.x<0)
                    Position.x-=abs(Size.y);
                else
                    Position.x+=Size.x-abs(Size.y);
                break;
            case Orientation::Left:
                if(Size.y<0)
                    Position.y+=Size.y;
                if(Size.x<0)
                    Position.x+=Size.x;
                break;
        }
        setProjectedSize(orientation_P,Vector(20, 20));
        setProjectedPosition(orientation_P,Vector(Position.x, Position.y));
        
        direction=dir;
        Blocks.push_back(temp);
        return *Last;
        
}
void Player::move() {
    Vector changeSize(0, 0);
    Vector changePosition(0, 0);
    switch (direction) {
        case Orientation::Up:
            if (getProjectedSize(orientation_P).y >= 0) {
                changeSize.y = 1;
                changePosition.y = -1;
            } else {
                changeSize.y = -1;
            }
            break;
        case Orientation::Down:
            if (getProjectedSize(orientation_P).y >= 0) {
                changeSize.y = 1;
            } else {
                changeSize.y = -1;
                changePosition.y = 1;
            }
            break;
        case Orientation::Right:
            if (getProjectedSize(orientation_P).x >= 0) {
                changeSize.x = 1;
            } else {
                changeSize.x = -1;
                changePosition.x = 1;
            }
            break;
        case Orientation::Left:
            if (getProjectedSize(orientation_P).x >= 0) {
                changeSize.x = 1;
                changePosition.x = -1;
            } else {
                changeSize.x = -1;
            }
            break;
    }
    ExpandProjectedSize(orientation_P.getSide(), orientation_P.getRotation(), changeSize);
    ExpandProjectedPosition(orientation_P.getSide(), orientation_P.getRotation(), changePosition);
}
Obstacle Player::Rotate(Orientation::Direction dir)
{
     Obstacle O=Turn(direction);
     orientation_P.Rotate(dir);
     return O;
}
Orientation Player::getOrientation()
{
    return orientation_P;
}
void Player::setOrientation(Orientation O)
{
    orientation_P=O;
}
Orientation::Direction Player::getDirection()
{
return direction;
}
void Player::setDirection(Orientation::Direction Dir)
{
        direction=Dir;
}
