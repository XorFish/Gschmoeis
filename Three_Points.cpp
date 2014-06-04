/* 
 * File:   Two_Points.cpp
 * Author: XorFish
 * 
 * Created on 1. Juni 2014, 12:54
 */

#include "Three_Points.h"

Three_Points::Three_Points() {
    
}
Three_Points::Three_Points(sf::Vector2f P0, sf::Vector2f P1, sf::Vector2f P2){
    point0=P0;
    point1=P1;
    point2=P2;
}
sf::Vector2f Three_Points::getPoint(int Point)
{
    if(Point==0)
        return point0;
    else if(Point==1)
        return point1;
    else
        return point2;
}

