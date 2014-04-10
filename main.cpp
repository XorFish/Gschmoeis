#include <SFML/Graphics.hpp>
using namespace sf;
#include "Vector.h"
#include "Obstacle.h"
#include "Orientation.h"
#include <iostream>

using namespace std;
class FallingRectangle: public sf::RectangleShape{
    Vector2f speed;
    Vector2f acceleration;
    public:
    void setSpeed(Vector2f);
    Vector2f getSpeed(void);
    void setAcceleration(Vector2f);
    Vector2f getAcceleration(void);
    FallingRectangle(Vector2f,Vector2f,Vector2f,Vector2f,Color);
    bool Tick(int, int);
    void Tick(void);
};
void     FallingRectangle::setSpeed(Vector2f Speed)                     {speed=Speed;}
Vector2f FallingRectangle::getSpeed(void)                               {return speed;}
void     FallingRectangle::setAcceleration(Vector2f Acceleration)       {acceleration=Acceleration;}
Vector2f FallingRectangle::getAcceleration(void)                        {return acceleration;}
FallingRectangle::FallingRectangle(Vector2f Speed,Vector2f Acceleration,Vector2f Size,Vector2f Position,Color c)
{
    speed=Speed;
    acceleration=Acceleration;
    setSize(Size);
    setPosition(Position);
    setFillColor(c);
}
bool FallingRectangle::Tick(int x, int y)
{
    return RectangleShape::getGlobalBounds().contains(x,y);
    move(speed+=acceleration);
}
void FallingRectangle::Tick(void) {move(speed+=acceleration);}

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
    
  
    Vector Size(100,200,20);
    Vector Position(200,250,50);
    Vector Playfield(1000,1000,1000);
    Obstacle test1(Size,Position, sf::Color::Red,Playfield);

    
    Orientation rotate(Obstacle::front,Obstacle::r0);
    sf::RectangleShape rec(test1.getProjectedSize(rotate.getSide(),rotate.getRotation()));
   
    rec.setPosition(test1.getProjectedPosition(rotate.getSide(),rotate.getRotation()));
    rec.setSize(test1.getProjectedSize(rotate.getSide(),rotate.getRotation()));
    rec.setFillColor(Color::Green);
    ContextSettings settings;
        settings.antialiasingLevel = 8;
        
    RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!", sf::Style::Default, settings);
    sf::Clock c;
    c.restart();
    Vector v(0,0);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type==Event::KeyPressed)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    v.setVector(test1.getProjectedPosition(rotate.getSide(),rotate.getRotation()).x,test1.getProjectedPosition(rotate.getSide(),rotate.getRotation()).y+5);
                    test1.setProjectedPosition(rotate.getSide(),rotate.getRotation(), v);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    v.setVector(test1.getProjectedPosition(rotate.getSide(),rotate.getRotation()).x+5,test1.getProjectedPosition(rotate.getSide(),rotate.getRotation()).y);
                    test1.setProjectedPosition(rotate.getSide(),rotate.getRotation(), v);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                   v.setVector(test1.getProjectedPosition(rotate.getSide(),rotate.getRotation()).x-5,test1.getProjectedPosition(rotate.getSide(),rotate.getRotation()).y);
                   test1.setProjectedPosition(rotate.getSide(),rotate.getRotation(), v);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    v.setVector(test1.getProjectedPosition(rotate.getSide(),rotate.getRotation()).x,test1.getProjectedPosition(rotate.getSide(),rotate.getRotation()).y-5);
                    test1.setProjectedPosition(rotate.getSide(),rotate.getRotation(),v );
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    rotate.Rotate(Orientation::left);                   
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    rotate.Rotate(Orientation::down);                   
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    rotate.Rotate(Orientation::right);                   
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    rotate.Rotate(Orientation::up);
                }
            }
            if (event.type == Event::Closed)
                window.close();
        }
        if(c.getElapsedTime()>sf::milliseconds(5))
        {
            c.restart();
            rec.setPosition(test1.getProjectedPosition(rotate.getSide(),rotate.getRotation()));
            rec.setSize(test1.getProjectedSize(rotate.getSide(),rotate.getRotation()));
            window.clear(sf::Color::Black);
            window.draw(rec);
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
