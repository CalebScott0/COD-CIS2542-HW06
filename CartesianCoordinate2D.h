#ifndef CARTESIANCOORDINATE2D_H
#define CARTESIANCOORDINATE2D_H
#include <iostream>

class CartesianCoordinate2D
{
public:
    CartesianCoordinate2D();
    CartesianCoordinate2D(double X, double Y);
    CartesianCoordinate2D(const CartesianCoordinate2D& rhs);
    
    double getX() const;
    void setX(double X);

    double getY() const;
    void setY(double Y);

    double getDistanceFromOrigin() const;
    int getQuadrant() const;

    // overloaded operators
    CartesianCoordinate2D& operator =(const CartesianCoordinate2D& rhs);
    CartesianCoordinate2D operator -(const CartesianCoordinate2D& rhs);
    CartesianCoordinate2D& operator -=(const CartesianCoordinate2D& rhs);
    bool operator >(const CartesianCoordinate2D& rhs) const;

    friend std::ostream& operator <<(std::ostream& ostrm, const CartesianCoordinate2D& rhs);
    

private:
    double x;
    double y;

};


#endif
