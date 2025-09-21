#include "CartesianCoordinate2D.h"
#include <cmath>

CartesianCoordinate2D::CartesianCoordinate2D()
    : x(0.0),
      y(0.0)
{
    // Empty.
}

CartesianCoordinate2D::CartesianCoordinate2D(double X, double Y)
    : x(X),
      y(Y)
{
    // Empty.
}

CartesianCoordinate2D::CartesianCoordinate2D(const CartesianCoordinate2D& rhs)
    : x(rhs.x),
      y(rhs.y)
{
    // Empty.
}

double CartesianCoordinate2D::getX() const
{
    return x;
}

void CartesianCoordinate2D::setX(double X)
{
    x = X;
} 

double CartesianCoordinate2D::getY() const
{
     return y;
}

void CartesianCoordinate2D::setY(double Y)
{
    y = Y;
} 

double CartesianCoordinate2D::getDistanceFromOrigin() const
{
    return std::hypot(x, y);
}

int CartesianCoordinate2D::getQuadrant() const
{

    if(x > 0)
    {
        if(y > 0)
        {
            return 1;
        }
        if(y < 0)
        {
            return 4;
        }
    }
    else if(x < 0)
    {
        if(y > 0)
        {
            return 2;
        }
        if(y < 0)
        {
            return 3;
        }
    }
    // any point on an axis
    return 0;
}

CartesianCoordinate2D& CartesianCoordinate2D::operator =(const CartesianCoordinate2D& rhs)
{
    x = rhs.x;
    y = rhs.y;

    return *this;
}

CartesianCoordinate2D CartesianCoordinate2D::operator -(const CartesianCoordinate2D& rhs) const
{
    return CartesianCoordinate2D(x - rhs.x, y - rhs.y);
}

CartesianCoordinate2D& CartesianCoordinate2D::operator -=(const CartesianCoordinate2D& rhs)
{
    x -= rhs.x;
    y -= rhs.y;

    return *this;
}

bool CartesianCoordinate2D::operator >(const CartesianCoordinate2D& rhs) const
{
    // > returns true if *this* is FARTHER from the origin than rhs.
    return getDistanceFromOrigin() > rhs.getDistanceFromOrigin();
}

std::ostream& operator <<(std::ostream& ostrm, const CartesianCoordinate2D& rhs)
{
    ostrm << "(" << rhs.x << ", " << rhs.y << ")";
    return ostrm;
}

