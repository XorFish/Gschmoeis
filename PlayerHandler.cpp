/* 
 * File:   PlayerHandler.cpp
 * Author: XorFish
 * 
 * Created on 14. Mai 2014, 10:54
 */

#include "PlayerHandler.h"

PlayerHandler::PlayerHandler() 
{
    
}
std::vector<Obstacle> PlayerHandler::getSortedvector(Orientation s)
{
    switch (s.getSide())
    {
        case Orientation::front:
            return Front;
            break;
        case Orientation::back:
            return Back;
            break;
        case Orientation::left:
            return Left;
            break;
        case Orientation::right:
            return Right;
            break;
        case Orientation::bottom:
            return Up;
            break;
        case Orientation::top:
            return Down;
            break;
    }
}

std::vector<Obstacle> PlayerHandler::sortside(Obstacle O,std::vector<Obstacle> List, Orientation::side Addside){
float Znew, Ztest;
    bool notfound=true;
    int ind=0;
    
    if (O.getProjectedZ(Addside).y<0)
        Znew=O.getProjectedZ(Addside).x+O.getProjectedZ(Addside).y;
    else
        Znew=O.getProjectedZ(Addside).y;
    if(List.empty())
    {
        List.push_back(O);
        notfound=false;
    }
    std::vector<Obstacle>::iterator insertat=List.begin();
    while(notfound)
    {
        if (List.at(ind).getProjectedZ(Addside).y<0)
                Ztest=List.at(ind).getProjectedZ(Addside).x+List.at(ind).getProjectedZ(Addside).y;
        else
                Ztest=List.at(ind).getProjectedZ(Addside).y;
        if(Znew<=Ztest)
        {
            
            insertat=List.begin()+ind;
            List.insert(insertat, O);
            notfound=false;
        }
        ind++; 
        if (ind==List.size())
        {
            notfound=false;
            List.push_back(O);
            sf::RectangleShape r();
        }
    }
    return List;
}
bool PlayerHandler::collision(Obstacle O, Orientation dir, sf::Vector2f P)
{
    sf::RectangleShape t(O.getProjectedSize(dir));
    t.setPosition(O.getProjectedPosition(dir));
    if(t.getGlobalBounds().contains(P))
        return true;
    else
        return false;
}
void PlayerHandler::AddObstacle(Obstacle O)
{
    Front=sortside(O, Front, Orientation::front);
    Back=sortside(O, Back, Orientation::back);
    Left=sortside(O, Left, Orientation::left);
    Right=sortside(O, Right, Orientation::right);
    Up=sortside(O, Up, Orientation::top);
    Down=sortside(O, Down, Orientation::bottom);
}
Three_Points PlayerHandler::getPoints(Player P,Orientation O)
{
    sf::Vector2f P0,P1,P2;
    switch(P.getDirection())
    {
        case Orientation::Up:
            if(P.getProjectedSize(O).y>=0)
                P0.y=P1.y=P2.y=P.getProjectedPosition(O).y-10;
            else
                P0.y=P1.y=P2.y=P.getProjectedPosition(O).y+P.getProjectedSize(O).y-10;
            P1.x=P.getProjectedSize(O).x/2+P.getProjectedPosition(O).x;
            P0.x=P1.x-20;
            P2.x=P1.x+20;
            break;
        case Orientation::Down:
            if(P.getProjectedSize(O).y<0)
                P0.y=P1.y=P2.y=P.getProjectedPosition(O).y+10;
            else
                P0.y=P1.y=P2.y=P.getProjectedPosition(O).y+P.getProjectedSize(O).y+10;
            P1.x=P.getProjectedSize(O).x/2+P.getProjectedPosition(O).x;
            P0.x=P1.x-20;
            P2.x=P1.x+20;
            break;
        case Orientation::Left:
            if(P.getProjectedSize(O).x>=0)
                P0.x=P1.x=P2.x=P.getProjectedPosition(O).x-10;
            else
                P0.x=P1.x=P2.x=P.getProjectedPosition(O).x+P.getProjectedSize(O).x-10;
            P1.y=P.getProjectedSize(O).y/2+P.getProjectedPosition(O).y;
            P0.y=P1.y-20;
            P2.y=P1.y+20;
            break;
        case Orientation::Right:
            if(P.getProjectedSize(O).x<0)
                P0.x=P1.x=P2.x=P.getProjectedPosition(O).x+10;
            else
                P0.x=P1.x=P2.x=P.getProjectedPosition(O).x+P.getProjectedSize(O).x+10;
            P1.y=P.getProjectedSize(O).y/2+P.getProjectedPosition(O).y;
            P0.y=P1.y-20;
            P2.y=P1.y+20;
            break;    
    }
     Three_Points TPoint(P0,P1,P2);
     return TPoint;
}
sf::Vector2f PlayerHandler::getCentre(Player P,Orientation O)
{
    sf::Vector2f P0;
    switch(P.getDirection())
    {
        case Orientation::Up:
            if(P.getProjectedSize(O).y>=0)
                P0.y=P.getProjectedPosition(O).y+10;
            else
                P0.y=P.getProjectedPosition(O).y+P.getProjectedSize(O).y+10;
            P0.x=P.getProjectedSize(O).x/2+P.getProjectedPosition(O).x;
            break;
        case Orientation::Down:
            if(P.getProjectedSize(O).y<0)
                P0.y=P.getProjectedPosition(O).y-10;
            else
                P0.y=P.getProjectedPosition(O).y+P.getProjectedSize(O).y-10;
            P0.x=P.getProjectedSize(O).x/2+P.getProjectedPosition(O).x;
            break;
        case Orientation::Left:
            if(P.getProjectedSize(O).x>=0)
                P0.x=P.getProjectedPosition(O).x+10;
            else
                P0.x=P.getProjectedPosition(O).x+P.getProjectedSize(O).x+10;
            P0.y=P.getProjectedSize(O).y/2+P.getProjectedPosition(O).y;

            break;
        case Orientation::Right:
            if(P.getProjectedSize(O).x<0)
                P0.x=P.getProjectedPosition(O).x-10;
            else
                P0.x=P.getProjectedPosition(O).x+P.getProjectedSize(O).x-10;
            P0.y=P.getProjectedSize(O).y/2+P.getProjectedPosition(O).y;
            break;    
    }
     return P0;
}
bool PlayerHandler::Collison (Player P,std::vector<Obstacle> Obstacles, Orientation O)
{
    bool game_over=false;
    for(int i=0;i<Obstacles.size();i++)
    {
        game_over|=collision(Obstacles.at(i),O, getPoints(P,O).getPoint(0));
        game_over|=collision(Obstacles.at(i),O, getPoints(P,O).getPoint(1));
        game_over|=collision(Obstacles.at(i),O, getPoints(P,O).getPoint(2));
    }
    return game_over;
}
