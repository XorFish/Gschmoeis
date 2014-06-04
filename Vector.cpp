/* 
 * File:   Vector.cpp
 * Author: XorFish
 * 
 * Created on 5. März 2014, 12:52
 */
#include "Vector.h"
#include <exception>

void Vector::setVector(void) {
    this->x=0;
    this->y=0;
    this->z=0;
    //this->w=0;
    this->Dimension=Vector::Dim0;
}
void Vector::setVector(float X, float Y) {
    this->x=X;
    this->y=Y;
    this->z=0;
    //this->w=0;
    this->Dimension=Vector::Dim2;
}
void Vector::setVector(float X, float Y, float Z) {
    this->x=X;
    this->y=Y;
    this->z=Z;
    //this->w=0;
    this->Dimension=Vector::Dim3;
}
/*void Vector::setVector(float X, float Y, float Z,float W) {
    this->x=X;
    this->y=Y;
    this->z=Z;
    this->w=W;
    this->Dimension=Vector::Dim4;
}*/
Vector::Vector()
{
    setVector();
}
Vector::Vector(float X,float Y)
{
    setVector(X,Y);
}
Vector::Vector(float X,float Y,float Z)
{
    setVector(X,Y,Z);
}
/*Vector::Vector(float X,float Y,float Z, float W)
{
    setVector(X,Y,Z,W);
}*/
bool Vector::operator==(const Vector &other)
{
    bool result=false;
    
    if  (( other.x==this->x)
        &&(other.y==this->y)
        &&(other.z==this->z)
        //&&(other.w==this->w)
        &&(other.Dimension==this->Dimension))
                result=true;
    return result;
}
bool Vector::operator!=(const Vector &other)
{
    return !(*this==other);
}
Vector::~Vector() {
}
Vector & Vector::operator +=(const Vector& other)
{   if(this->Dimension==other.Dimension)
    {
        if(this->Dimension!=Vector::Dim0)
        {
            this->x=this->x+other.x;
            this->y=this->y+other.y;
        }
        if(this->Dimension==Vector::Dim3)
            this->z=this->z+other.z;
        /*if(this->Dimension==Vector::Dim4)
        {
            this->z=this->z+other.z;
            this->w=this->w+other.w;
        }*/
    }
    else
    {
        this->setVector();
    }
    return *this;
}
Vector Vector::operator +(const Vector& other)
{
    Vector result(*this);
    result+=other;
    return result;
}
Vector & Vector::operator -=(const Vector& other)
{
    if(this->Dimension==other.Dimension)
    {
        if(this->Dimension!=Vector::Dim0)
        {
            this->x=this->x-other.x;
            this->y=this->y-other.y;
        }
        if(this->Dimension==Vector::Dim3)
            this->z=this->z-other.z;
       /* if(this->Dimension==Vector::Dim4)
        {
            this->z=this->z-other.z;
            this->w=this->w-other.w;
        }*/
    }
    else
    {
        this->setVector();
    }
    return *this;
}
Vector Vector::operator -(const Vector& other)
{
    Vector result(*this);
    result-=other;
    return result;
}
Vector & Vector::operator *=(const float& other)        //Multiplikation mit Skalar
{
    this->x*=other;
    this->y*=other;
    this->z*=other;
    //this->w*=other;
    return *this;
}
Vector  Vector::operator *(const float& other)          //Multiplikation mit Skalar
{
    Vector result(*this);
    result*=other;
    return result;
}
Vector operator *(const float Skalar,const Vector& other)
{
    Vector result(other);
    result*=Skalar;
    return result;
}
Vector operator *(const int Skalar,const Vector& other)
{
    Vector result(other);
    result*=Skalar;
    return result;
}
Vector operator *(const double Skalar,const Vector& other)
{
    Vector result(other);
    result*=Skalar;
    return result;
}
float Vector::operator *(const Vector& other)           //Skalarprodukt
{
    float result;
    result=this->x*other.x;
    result+=this->y*other.y;
    result+=this->z*other.z;
    //result+=this->w*other.w;
    return result;
}