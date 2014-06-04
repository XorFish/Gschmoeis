/* 
 * File:   Two_Points.h
 * Author: XorFish
 *
 * Created on 1. Juni 2014, 12:54
 */

#ifndef TWO_POINTS_H
#define	TWO_POINTS_H
#include <SFML/Graphics.hpp>

class Three_Points {
public:
    Three_Points();
    Three_Points(sf::Vector2f, sf::Vector2f,sf::Vector2f);
    sf::Vector2f getPoint(int);
    
private:
    sf::Vector2f point0;
    sf::Vector2f point1;
    sf::Vector2f point2;
};

#endif	/* TWO_POINTS_H */

