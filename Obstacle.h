/* 
 * File:   Obstacle.h
 * Author: XorFish
 *
 * Created on 19. März 2014, 08:52
 */

#ifndef OBSTACLE_H
#define	OBSTACLE_H
#include "Vector.h"
#include "Orientation.h"
#include <SFML/Graphics.hpp>

class Obstacle {
private:

    Vector position;
    Vector size;
    Vector playfield;
    sf::Color color;

public:

    
    Obstacle(Vector, Vector, sf::Color, Vector);
    Obstacle();
    //virtual ~Obstacle();

    Vector getSize();
    void setSize(Vector);
    Vector getPosition();
    void setPosition(Vector);

    sf::Vector2f getProjectedSize(Orientation::side, Orientation::rotation);
    sf::Vector2f getProjectedSize(Orientation);
    
    void setProjectedSize(Orientation::side, Orientation::rotation, Vector);
    void setProjectedSize(Orientation, Vector);
    void ExpandProjectedSize(Orientation::side, Orientation::rotation, Vector);
    void ExpandProjectedSize(Orientation, Vector);
    
    sf::Vector2f getProjectedPosition(Orientation::side, Orientation::rotation);
    sf::Vector2f getProjectedPosition(Orientation);
    
    void setProjectedPosition(Orientation::side, Orientation::rotation, Vector);
    void setProjectedPosition(Orientation, Vector);
    void ExpandProjectedPosition(Orientation::side, Orientation::rotation, Vector);
    void ExpandProjectedPosition(Orientation, Vector);
    
    sf::Vector2f getProjectedZ(Orientation::side);
    void setProjectedZ(Orientation::side, Vector);
    
    Vector getPlayfield(void);
    void   setPlayfield(Vector);

    sf::Color getColor();
    void setColor(sf::Color);
};

#endif	/* OBSTACLE_H */

