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
    // TODO: exception here for entering a non numeric value?
}

CartesianCoordinate2D::CartesianCoordinate2D(const CartesianCoordinate2D& rhs)
    : x(rhs.x),
      y(rhs.y)
{
    // Empty
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
    return sqrt((x * x) + (y * y));
}

int CartesianCoordinate2D::getQuadrant() const
{
    // If a point is on any axis, return the value 0
    if(x == 0 || y == 0)
    {
        return 0;
    }

    else if(x > 0)
    {
        if(y > 0)
        {
            return 1;
        }
        return 4;
    }
    else
    {
        if(y > 0)
        {
            return 2;
        }
        return 3;
    }
}

CartesianCoordinate2D& CartesianCoordinate2D::operator =(const CartesianCoordinate2D& rhs)
{
    x = rhs.x;
    y = rhs.y;

    return *this;
}

CartesianCoordinate2D CartesianCoordinate2D::operator -(const CartesianCoordinate2D& rhs)
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
    return getDistanceFromOrigin() > rhs.getDistanceFromOrigin();
}

std::ostream& operator <<(std::ostream& ostrm, const CartesianCoordinate2D& rhs)
{
    ostrm << "(" << rhs.x << ", " << rhs.y << ")";
    return ostrm;
}

