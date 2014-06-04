/* 
 * File:   Orientation.h
 * Author: XorFish
 *
 * Created on 2. April 2014, 08:44
 */

#ifndef ORIENTATION_H
#define	ORIENTATION_H
class Orientation {
public:
    enum side {
        front = 0, back = 1, right = 2, left = 3, top = 4, bottom = 5
    };

    enum rotation {
        r0 = 0, r90 = 1, r180 = 2, r270 = 3
    };
    enum Direction{Up=0, Down=1, Right=2, Left=3};
    Orientation();
    Orientation(side, rotation);
    void setOrientation(side, rotation);
    
    side getSide();
    rotation getRotation();
    void setSide(side);
    void setRotation(rotation);
    
    static Orientation Rotate(side, rotation, Direction);
    static Orientation Rotate(Orientation, Direction);
    void Rotate(Direction);
    //Orientation(const Orientation& orig);
    //virtual ~Orientation();
private:
    Direction direction;
    side side_p;
    rotation rotation_p;

};

#endif	/* ORIENTATION_H */

