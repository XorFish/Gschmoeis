#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;
#include "Vector.h"
#include "Obstacle.h"
#include "Orientation.h"
#include "Player.h"
#include "PlayerHandler.h"
#include <iostream>
#include <vector>

using namespace std;
void DRAW(PlayerHandler* Handler, Orientation O,float Scale, sf::Vector2f Position, sf::RenderWindow* target)
{
    sf::RectangleShape rec(Position);
    rec.setFillColor(Handler->Player1.getColor());
            for(int ind=Handler->getSortedvector(O).size()-1;ind>=0;ind--)
            {
               rec.setPosition(Handler->getSortedvector(O).at(ind).getProjectedPosition(O));
               rec.setSize(Handler->getSortedvector(O).at(ind).getProjectedSize(O));
               rec.setScale(Scale,Scale);
               rec.setPosition(rec.getPosition().x*Scale, rec.getPosition().y*Scale);
               rec.move(Position);
               target->draw(rec);
            }
           rec.setPosition(Handler->Player1.getProjectedPosition(O));
           rec.setSize(Handler->Player1.getProjectedSize(O));
           rec.setScale(Scale,Scale);
           rec.setPosition(rec.getPosition().x*Scale, rec.getPosition().y*Scale);
           rec.move(Position);
           target->draw(rec);
           
           rec.setOrigin(20,20);
           rec.setSize(sf::Vector2f(40,40));
           rec.setFillColor(sf::Color::Blue);
           rec.setPosition(Handler->getCentre(Handler->Player1,O));
           rec.setScale(Scale,Scale);
           rec.setPosition(rec.getPosition().x*Scale, rec.getPosition().y*Scale);
           rec.move(Position);
           target->draw(rec);
           
}
int main()
{
    
   /* ContextSettings settings;
        settings.antialiasingLevel = 8;
        
    RenderWindow window(sf::VideoMode(500, 500), "SFML works!", sf::Style::Default, settings);
    sf::Clock c;
    c.restart();
    
    FallingRectangle test2(Vector2f(-1,1),Vector2f(0,0.01),Vector2f(75,50),Vector2f(150,-33),sf::Color::Green);
    test.setOutlineThickness(2);
    test2.setOutlineThickness(2);
    test.setOutlineColor(Color::White);
    test2.setOutlineColor(Color::White);*/
    //FallingRectangle test(Vector2f(1,0),Vector2f(0,0.01),Vector2f(100,33),Vector2f(250,-33),sf::Color::Red);
    
  
    Vector Size(20,20,20);
    Vector Position(200,250,50);
    Vector Playfield(1000,1000,1000);
    Orientation rotate(Orientation::front,Orientation::r0);
    Vector2f Offset(200,0);
    PlayerHandler handler;
    Player test(Size,Position, sf::Color::Green, Playfield, Orientation::Right, rotate);
    handler.Player1=test;
    

    
    
    sf::RectangleShape rec(handler.Player1.getProjectedSize(rotate.getSide(),rotate.getRotation()));
    sf::RectangleShape position(handler.Player1.getProjectedSize(rotate.getSide(),rotate.getRotation()));
    sf::RectangleShape collision1(handler.Player1.getProjectedSize(rotate.getSide(),rotate.getRotation()));
    sf::RectangleShape collision2(handler.Player1.getProjectedSize(rotate.getSide(),rotate.getRotation()));
    sf::RectangleShape collision3(handler.Player1.getProjectedSize(rotate.getSide(),rotate.getRotation()));
   
    rec.setPosition(handler.Player1.getProjectedPosition(rotate.getSide(),rotate.getRotation()));
    rec.setSize(handler.Player1.getProjectedSize(rotate.getSide(),rotate.getRotation()));
    rec.setFillColor(Color::Green);
    rec.setOutlineThickness(2);
    rec.setOutlineColor(sf::Color::Red);
    position=rec;
    position.setSize(sf::Vector2f(40,40));
    position.setOrigin(20,20);
    position.setFillColor(sf::Color::Blue);
    collision1=collision2=collision3=position;
    collision1.setScale(0.2,0.2);
    collision2.setScale(0.2,0.2);
    collision3.setScale(0.2,0.2);
    
    ContextSettings settings;
        settings.antialiasingLevel = 8;
        
    RenderWindow window(sf::VideoMode(1400, 1000), "SFML works!", sf::Style::Default, settings);
    sf::Clock c;
    c.restart();
    
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type==Event::KeyPressed)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                   //test1.Blocks.push_back(test1.Turn(Orientation::Down));
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                   switch(handler.Player1.getDirection())
                    {
                        case Orientation::Down:
                            
                            handler.AddObstacle(handler.Player1.Turn(Orientation::Left));
                            break;
                        case Orientation::Up:
                            handler.AddObstacle(handler.Player1.Turn(Orientation::Right));
                            break;
                        case Orientation::Right:
                            handler.AddObstacle(handler.Player1.Turn(Orientation::Down));
                            break;
                        case Orientation::Left:
                            handler.AddObstacle(handler.Player1.Turn(Orientation::Up));
                            break;
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    switch(handler.Player1.getDirection())
                    {
                        case Orientation::Down:
                            handler.AddObstacle(handler.Player1.Turn(Orientation::Right));
                            break;
                        case Orientation::Up:
                            handler.AddObstacle(handler.Player1.Turn(Orientation::Left));
                            break;
                        case Orientation::Right:
                            handler.AddObstacle(handler.Player1.Turn(Orientation::Up));
                            break;
                        case Orientation::Left:
                            handler.AddObstacle(handler.Player1.Turn(Orientation::Down));
                            break;
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    //test1.Blocks.push_back(test1.Turn(Orientation::Up));
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    handler.AddObstacle(handler.Player1.Rotate(Orientation::Left));              
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    handler.AddObstacle(handler.Player1.Rotate(Orientation::Down));                   
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    handler.AddObstacle(handler.Player1.Rotate(Orientation::Right));                   
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    handler.AddObstacle(handler.Player1.Rotate(Orientation::Up));
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    handler.Player1.Blocks.clear();
                }
            }
            if (event.type == Event::Closed)
                window.close();
        }
        if(c.getElapsedTime()>sf::milliseconds(20))
        {
            c.restart();
            handler.Player1.move();
            handler.Player1.move();
            handler.Player1.move();
            handler.Player1.move();
            if(handler.Collison(handler.Player1,handler.getSortedvector(handler.Player1.getOrientation()),handler.Player1.getOrientation()))
                window.clear(sf::Color::Red);
            else
                window.clear(sf::Color::White);
            DRAW(&handler,handler.Player1.getOrientation(),1,sf::Vector2f(0,0),&window);
            DRAW(&handler,Orientation::Rotate(handler.Player1.getOrientation(),Orientation::Left),0.2,sf::Vector2f(1000,400),&window);
            DRAW(&handler,Orientation::Rotate(handler.Player1.getOrientation(),Orientation::Right),0.2,sf::Vector2f(1200, 400),&window);
            DRAW(&handler,Orientation::Rotate(handler.Player1.getOrientation(),Orientation::Up),0.2,sf::Vector2f(1100, 200),&window);
            DRAW(&handler,Orientation::Rotate(handler.Player1.getOrientation(),Orientation::Down),0.2,sf::Vector2f(1100, 600),&window);
            
            position.setPosition(handler.getCentre(handler.Player1,handler.Player1.getOrientation()));
            
            window.draw(position);
            
            
            
            window.display();
        }
    }
}
   /* while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if(c.getElapsedTime()>=sf::milliseconds(3))
        {
            //test.setAcceleration(Vector2f((sf::Mouse::getPosition(window).x-test.getPosition().x+test.getSize().x/2)/10000.0,(sf::Mouse::getPosition(window).y-test.getPosition().y+test.getSize().y/2)/10000.0));
            test.setPosition(sf::Mouse::getPosition(window).x-test.getSize().x/2,sf::Mouse::getPosition(window).y-test.getSize().y/2);
           /* if(test.getPosition().y>=(500-test.getSize().y)&&test.getSpeed().y>0)
            {
                test.setSpeed(Vector2f(test.getSpeed().x*0.95f,-(test.getSpeed().y*0.95f)));
                if(test.getSpeed().y<0.005&&test.getSpeed().y>-0.005)
                {
                    test.setAcceleration(Vector2f(0,0));
                    test.setSpeed(Vector2f(0,0));
                }
            }
            if(test.getPosition().x>=(500-test.getSize().x)&&test.getSpeed().x>0)
            {
                test.setSpeed(Vector2f(-(test.getSpeed().x*0.95f),test.getSpeed().y*0.95f));
            }
            if(test.getPosition().x<=0&&test.getSpeed().x<0)
            {
                test.setSpeed(Vector2f(-(test.getSpeed().x*0.95f),test.getSpeed().y*0.95f));
            }
            
            test.Tick();*/
             /* if(test2.getPosition().y>=(500-test2.getSize().y)&&test2.getSpeed().y>0)
            {
                test2.setSpeed(Vector2f(test2.getSpeed().x*0.95f,-(test2.getSpeed().y*0.95f)));
                if(test2.getSpeed().y<0.005&&test2.getSpeed().y>-0.005)
                {
                    test2.setAcceleration(Vector2f(0,0));
                    test2.setSpeed(Vector2f(0,0));
                }
            }
            if(test2.getPosition().x>=(500-test2.getSize().x)&&test2.getSpeed().x>0)
            {
                test2.setSpeed(Vector2f(-(test2.getSpeed().x*0.95f),test2.getSpeed().y*0.95f));
            }
            if(test2.getPosition().x<=0&&test2.getSpeed().x<0)
            {
                test2.setSpeed(Vector2f(-(test2.getSpeed().x*0.95f),test2.getSpeed().y*0.95f));
            }
            
            test2.Tick();
            window.clear(sf::Color::Black);
            window.draw(test);
            window.draw(test2);
            window.display();
            c.restart();
            
        }
      
        
    }
    /*
    
    ContextSettings settings;
        settings.antialiasingLevel = 8;
    
    RenderWindow window(sf::VideoMode(500, 500), "SFML works!", sf::Style::Default, settings);
    CircleShape shape(250.f,100);
    RectangleShape rectangle1(Vector2f(200,200));
    RectangleShape rectangle2(Vector2f(200,200));
    
    shape.setOutlineThickness(5);
    shape.setOutlineColor(Color::Black);
    shape.setFillColor(Color::Green);
    
    rectangle1.setFillColor(Color::Yellow);
    rectangle1.setOutlineColor(Color::Black);
    rectangle1.setOutlineThickness(5);
    rectangle1.setOrigin(Vector2f(100,100));
    rectangle1.move(Vector2f(250,250));
    
    rectangle2=rectangle1;
    rectangle2.setFillColor(Color::Blue);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        
        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            rectangle1.rotate(0.1);
            rectangle2.rotate(-0.1);
        }
        else
        {
            rectangle1.rotate(-0.1);
            rectangle2.rotate(0.1);
        }
        sleep(milliseconds(2));
        window.clear(Color::Magenta);
        window.draw(shape);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.display();
    }

    return 0;*/
