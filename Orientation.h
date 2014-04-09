/* 
 * File:   Orientation.h
 * Author: XorFish
 *
 * Created on 2. April 2014, 08:44
 */

#ifndef ORIENTATION_H
#define	ORIENTATION_H
#include "Obstacle.h"
class Orientation {
public:
    enum Direction{up=0, down=1, right=2, left=3};
    Orientation();
    Orientation(Obstacle::side, Obstacle::rotation);
    void setOrientation(Obstacle::side, Obstacle::rotation);
    
    Obstacle::side getSide();
    Obstacle::rotation getRotation();
    void setSide(Obstacle::side);
    void setRotation(Obstacle::rotation);
    
    static Orientation Rotate(Obstacle::side, Obstacle::rotation, Direction);
    void Rotate(Direction);
    //Orientation(const Orientation& orig);
    //virtual ~Orientation();
private:
    Direction direction;
    Obstacle::side side;
    Obstacle::rotation rotation;

};

#endif	/* ORIENTATION_H */

