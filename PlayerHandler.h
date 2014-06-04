/* 
 * File:   PlayerHandler.h
 * Author: XorFish
 *
 * Created on 14. Mai 2014, 10:54
 */

#ifndef PLAYERHANDLER_H
#define	PLAYERHANDLER_H
#include <vector>
#include "Player.h"
#include "Three_Points.h"

class PlayerHandler {
public:
    PlayerHandler();
    std::vector<Obstacle> Front;
    std::vector<Obstacle> Back;
    std::vector<Obstacle> Right;
    std::vector<Obstacle> Left;
    std::vector<Obstacle> Up;
    std::vector<Obstacle> Down;
    void AddObstacle(Obstacle);
    std::vector<Obstacle> getSortedvector(Orientation);
    bool Collison (Player,std::vector<Obstacle>, Orientation);
    Three_Points getPoints(Player,Orientation);
    sf::Vector2f getCentre(Player,Orientation);
    Player Player1;
    Player Player2;
private:
    
    std::vector<Obstacle> sortside(Obstacle,std::vector<Obstacle>, Orientation::side );
    bool collision(Obstacle, Orientation, sf::Vector2f);
    

};

#endif	/* PLAYERHANDLER_H */

