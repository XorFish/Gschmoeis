/* 
 * File:   Obstacle.cpp
 * Author: XorFish
 * 
 * Created on 19. März 2014, 08:52
 */

#include <SFML/System/Vector2.hpp>

#include "Obstacle.h"

Obstacle::Obstacle(Vector Size, Vector Position, sf::Color Color, Vector Playfield) {
    size = Size;
    position = Position;
    color = Color;
    playfield = Playfield;
}

Obstacle::Obstacle() {
}

void Obstacle::setSize(Vector Size) {
    size = Size;
}

Vector Obstacle::getSize(void) {
    return size;
}

void Obstacle::setPosition(Vector Position) {
    position = Position;
}

Vector Obstacle::getPosition(void) {
    return position;
}

void Obstacle::setColor(sf::Color Color) {
    color = Color;
}

sf::Color Obstacle::getColor(void) {
    return color;
}

Vector Obstacle::getPlayfield(void) {
    return playfield;
}

void Obstacle::setPlayfield(Vector Playfield) {
    playfield = Playfield;
}

sf::Vector2f Obstacle::getProjectedSize(Orientation::side Direction, Orientation::rotation Rotation) {
    Vector result(0, 0);
    switch (Direction) {
        case Orientation::front:
            result.setVector(size.x, -size.z);
            break;
        case Orientation::right:
            result.setVector(-size.y, -size.z);
            break;
        case Orientation::top:
            result.setVector(size.x, size.y);
            break;
        case Orientation::back:
            result.setVector(-size.x, -size.z);
            break;
        case Orientation::left:
            result.setVector(size.y, -size.z);
            break;
        case Orientation::bottom:
            result.setVector(size.x, -size.y);
            break;
    }
    switch (Rotation) {
        case Orientation::r270:
            result.setVector(-result.y, result.x);
            break;
        case Orientation::r90:
            result.setVector(result.y, -result.x);
            break;
        case Orientation::r180:
            result.setVector(-result.x, -result.y);
            break;
    }
    return sf::Vector2f(result.x, result.y);
}

sf::Vector2f Obstacle::getProjectedSize(Orientation O) {
    return getProjectedSize(O.getSide(), O.getRotation());
}

void Obstacle::ExpandProjectedSize(Orientation::side Side, Orientation::rotation Rotation, Vector Expand) {
    Vector* NewSize = new Vector(getProjectedSize(Side, Rotation).x, getProjectedSize(Side, Rotation).y);
    *NewSize += Expand;
    setProjectedSize(Side, Rotation, *NewSize);

}

void Obstacle::ExpandProjectedSize(Orientation O, Vector Expand) {
    ExpandProjectedSize(O.getSide(), O.getRotation(), Expand);
}

void Obstacle::ExpandProjectedPosition(Orientation::side Side, Orientation::rotation Rotation, Vector Expand) {
    Vector* NewPosition = new Vector(getProjectedPosition(Side, Rotation).x, getProjectedPosition(Side, Rotation).y);
    *NewPosition += Expand;
    setProjectedPosition(Side, Rotation, *NewPosition);

}

void Obstacle::ExpandProjectedPosition(Orientation O, Vector Expand) {
    ExpandProjectedPosition(O.getSide(), O.getRotation(), Expand);
}

void Obstacle::setProjectedSize(Orientation::side Direction, Orientation::rotation Rotation, Vector newSize) {
    switch (Rotation) {
        case Orientation::r270:
            newSize.setVector(newSize.y, -newSize.x);
            break;
        case Orientation::r90:
            newSize.setVector(-newSize.y, newSize.x);
            break;
        case Orientation::r180:
            newSize.setVector(-newSize.x, -newSize.y);
            break;
    }
    switch (Direction) {
        case Orientation::front:
            size.setVector(newSize.x, size.y, -newSize.y);
            break;
        case Orientation::right:
            size.setVector(size.x, -newSize.x, -newSize.y);
            break;
        case Orientation::top:
            size.setVector(newSize.x, newSize.y, size.z);
            break;
        case Orientation::back:
            size.setVector(-newSize.x, size.y, -newSize.y);
            break;
        case Orientation::left:
            size.setVector(size.x, newSize.x, -newSize.y);
            break;
        case Orientation::bottom:
            size.setVector(newSize.x, -newSize.y, size.z);
            break;
    }

}

void Obstacle::setProjectedSize(Orientation O, Vector newSize) {
    setProjectedSize(O.getSide(), O.getRotation(), newSize);
}

sf::Vector2f Obstacle::getProjectedPosition(Orientation::side Side, Orientation::rotation Rotation) {
    /**
     * 
     * @param Side: Seite der Projektion
     * @param Rotation: Rotation der Projektion
     * @return Vector 
     */
    Vector result(0, 0);
    float h, w;
    switch (Side) {
        case Orientation::front:
            h = playfield.z;
            w = playfield.x;
            result.setVector(position.x, h - position.z);
            break;
        case Orientation::right:
            h = playfield.z;
            w = playfield.y;
            result.setVector(w - position.y, h - position.z);
            break;
        case Orientation::top:
            h = playfield.y;
            w = playfield.x;
            result.setVector(position.x, position.y);
            break;
        case Orientation::back:
            h = playfield.z;
            w = playfield.x;
            result.setVector(w - position.x, h - position.z);
            break;
        case Orientation::left:
            h = playfield.z;
            w = playfield.y;
            result.setVector(position.y, h - position.z);
            break;
        case Orientation::bottom:
            h = playfield.y;
            w = playfield.x;
            result.setVector(position.x, h - position.y);
            break;
    }
    switch (Rotation) {
        case Orientation::r270:
            result.setVector(h - result.y, result.x);
            break;
        case Orientation::r90:
            result.setVector(result.y, w - result.x);
            break;
        case Orientation::r180:
            result.setVector(w - result.x, h - result.y);
            break;
    }
    return sf::Vector2f(result.x, result.y);
}

sf::Vector2f Obstacle::getProjectedPosition(Orientation O) {
    return getProjectedPosition(O.getSide(), O.getRotation());
}

void Obstacle::setProjectedPosition(Orientation::side Side, Orientation::rotation Rotation, Vector newPosition) {
    float h, w;
    switch (Side) {
        case Orientation::front:
            h = playfield.z;
            w = playfield.x;
            break;
        case Orientation::right:
            h = playfield.z;
            w = playfield.y;
            break;
        case Orientation::top:
            h = playfield.y;
            w = playfield.x;
            break;
        case Orientation::back:
            h = playfield.z;
            w = playfield.x;
            break;
        case Orientation::left:
            h = playfield.z;
            w = playfield.y;
            break;
        case Orientation::bottom:
            h = playfield.y;
            w = playfield.x;
            break;
    }
    switch (Rotation) {
        case Orientation::r270:
            newPosition.setVector(newPosition.y, w - newPosition.x);
            break;
        case Orientation::r90:
            newPosition.setVector(h - newPosition.y, newPosition.x);
            break;
        case Orientation::r180:
            newPosition.setVector(w - newPosition.x, h - newPosition.y);
            break;
    }
    switch (Side) {
        case Orientation::front:
            position.setVector(newPosition.x, position.y, playfield.z - newPosition.y);
            break;
        case Orientation::right:
            position.setVector(position.x, playfield.y - newPosition.x, playfield.z - newPosition.y);
            break;
        case Orientation::top:
            position.setVector(newPosition.x, newPosition.y, position.z);
            break;
        case Orientation::back:
            position.setVector(playfield.x - newPosition.x, position.y, playfield.z - newPosition.y);
            break;
        case Orientation::left:
            position.setVector(position.x, newPosition.x, playfield.z - newPosition.y);
            break;
        case Orientation::bottom:
            position.setVector(newPosition.x, playfield.y - newPosition.y, position.z);
            break;
    }
}

void Obstacle::setProjectedPosition(Orientation O, Vector newPosition) {
    setProjectedPosition(O.getSide(), O.getRotation(), newPosition);
}

sf::Vector2f Obstacle::getProjectedZ(Orientation::side Side) {
    sf::Vector2f Z(0, 0);
    switch (Side) {
        case Orientation::front:
            if (size.y > 0)
                Z.x = playfield.y - (position.y + size.y);
            else
                Z.x = playfield.y - position.y;
            Z.y = size.y;
            break;
        case Orientation::right:
            if (size.x > 0)
                Z.x = playfield.x - (position.x + size.x);
            else
                Z.x = playfield.x - position.x;
            Z.y = size.x;
            break;
        case Orientation::top:
            if (size.z < 0)
                Z.x = position.z + size.z;
            else
                Z.x = position.z;
            Z.y = size.z;
            break;
        case Orientation::back:
            if (size.y < 0)
                Z.x = position.y + size.y;
            else
                Z.x = position.y;
            Z.y = size.y;
            break;
        case Orientation::left:
            if (size.x < 0)
                Z.x = position.x + size.x;
            else
                Z.x = position.x;
            Z.y = size.x;
            break;
        case Orientation::bottom:
            if (size.z > 0)
                Z.x = playfield.z - (position.z + size.z);
            else
                Z.x = playfield.z - position.z;
            Z.y = size.z;
            break;

    }
    return Z;
}
/*Obstacle::~Obstacle() 
{
}
 */
