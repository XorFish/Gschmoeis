/* 
 * File:   Obstacle.h
 * Author: XorFish
 *
 * Created on 19. März 2014, 08:52
 */

#ifndef OBSTACLE_H
#define	OBSTACLE_H
#include "Vector.h"
#include <SFML/Graphics.hpp>

class Obstacle {
private:
    
    Vector position;
    Vector size;
    Vector playfield;
    sf::Color color;
    
public:
    enum side{front=0, back=1, right=2, left=3, top=4, bottom=5};
    enum rotation{r0=0, r90=1, r180=2, r270=3};
    Obstacle(Vector,Vector, sf::Color, Vector);
    //virtual ~Obstacle();
    
    Vector getSize();
    void setSize(Vector);
    Vector getPosition();
    void setPosition(Vector);
    
    sf::Vector2f getProjectedSize(side,rotation);
    void setProjectedSize(side,rotation, Vector);
    sf::Vector2f getProjectedPosition(side,rotation);
    void setProjectedPosition(side,rotation, Vector);
    sf::Vector2f getProjectedZ(side);
    void setProjectedZ(side, Vector);
    
    sf::Color getColor();
    void setColor(sf::Color);
};

#endif	/* OBSTACLE_H */

