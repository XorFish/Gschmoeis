/* 
 * File:   Player.h
 * Author: XorFish
 *
 * Created on 30. April 2014, 08:31
 */

#ifndef PLAYER_H
#define	PLAYER_H
#include "Obstacle.h"
#include <vector>
//#include "Orientation.h"


class Player: public Obstacle {
public:
    Player(Vector, Vector, sf::Color, Vector, Orientation::Direction, Orientation);
    Player();
    
    
    Obstacle Turn(Orientation::Direction);
    Obstacle Rotate(Orientation::Direction);
    Orientation getOrientation();
    Orientation::Direction getDirection();
    void setDirection(Orientation::Direction);
    void setOrientation(Orientation O);
    Obstacle* Last;
    std::vector<Obstacle> Blocks;
    
    
    void move(void);
    
private:
    Orientation::Direction direction;
    Orientation orientation_P;
    
    
};

#endif	/* PLAYER_H */

