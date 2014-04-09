/* 
 * File:   Vector.h
 * Author: XorFish
 *
 * Created on 5. März 2014, 12:52
 */

#ifndef VECTOR_H
#define	VECTOR_H

#include "SFML-2.1/include/SFML/Config.hpp"


class Vector {
private:
     enum dimension {Dim0=0,Dim2=2,Dim3=3,Dim4=4}; 
public:
    //Variablen
    float x;
    float y;
    float z;
    float w;
    dimension Dimension;
    
    static const Vector NullvectorD0;
    static const Vector NullvectorD2;
    static const Vector NullvectorD3;
    static const Vector NullvectorD4;
    
    //Konstructor für Dim2-4
    Vector(float, float, float, float);
    Vector(float, float, float);
    Vector(float, float);
    Vector();
    
    void setVector(float, float, float,float);
    void setVector(float, float, float);
    void setVector(float, float);
    void setVector(void);

    
    //Vergleiche zweier Vektoren
    bool operator==(const Vector &other);
    bool operator!=(const Vector &other);
    
    //Addition und Subtraktion von Vektoren
    Vector & operator+=(const Vector &other);
    Vector operator+(const Vector &other);
    Vector & operator-=(const Vector &other);
    Vector operator-(const Vector &other);
    
    //Multiplikation mit Skalar oder Skalarprodukt
    float operator*(const Vector &other);
    Vector  operator*(const float &other);
    Vector & operator*=(const float &other);
    virtual ~Vector();
    
};
Vector operator *(const float,const Vector&);
Vector operator *(const int,const Vector&);
Vector operator *(const double,const Vector&);
#endif	/* VECTOR_H */

