#include "CartesianCoordinate2D.h"
#include <iostream>
#include <iomanip>

int main() 
{
    std::cout << "--- Basic construction ---" << std::endl;
    CartesianCoordinate2D a;                  
    CartesianCoordinate2D b(4.0, -3.0);       
    CartesianCoordinate2D c(-5.0, 1.0);       
    CartesianCoordinate2D d(b);               

    std::cout << "a (default): " << a << std::endl;
    std::cout << "b (param):   " << b << std::endl;
    std::cout << "c (param):   " << c << std::endl;
    std::cout << "d (copy b):  " << d << std::endl << std::endl;

    std::cout << "--- Getters / Setters ---" << std::endl;
    std::cout << "b.getX(): " << b.getX() << ", b.getY(): " << b.getY() << std::endl;
    b.setX(6.0);
    b.setY(2.0);
    std::cout << "b after setX/setY -> " << b << std::endl << std::endl;

    // show quadrant 0 on axis
    a.setX(2.0); 
    std::cout << "--- Quadrants (0 if on axis) ---" << std::endl;
    std::cout << "a " << a << " quadrant: " << a.getQuadrant() << std::endl;
    std::cout << "b " << b << " quadrant: " << b.getQuadrant() << std::endl;
    std::cout << "c " << c << " quadrant: " << c.getQuadrant() << std::endl;
    std::cout << "d " << d << " quadrant: " << d.getQuadrant() << std::endl << std::endl;

    std::cout << "--- Copy assignment ---" << std::endl;
    std::cout << "d before: " << d << std::endl;
    d = c; 
    std::cout << "d after: " << d << " (assigned from c)" << std::endl << std::endl;

    std::cout << "--- operator - (difference) ---" << std::endl;
    std::cout << c << " - " << b << " = " << (c - b) << std::endl << std::endl; // (-11.0, -1.0);

    std::cout << "--- operator -= (in-place subtraction) ---" << std::endl;
    std::cout << "a start: " << a << std::endl;
    a -= c; // (7.0, -1.0)
    std::cout << "a -= " << c << " -> " << a << std::endl << std::endl;

    std::cout << "--- Distance from origin ---" << std::endl;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "a distance: " << a.getDistanceFromOrigin() << std::endl;
    std::cout << "b distance: " << b.getDistanceFromOrigin() << std::endl;
    std::cout << "c distance: " << c.getDistanceFromOrigin() << std::endl << std::endl;
    std::cout.unsetf(std::ios::fixed);
    std::cout << std::setprecision(6);

    std::cout << "--- operator > (farther from origin) ---" << std::endl;
    std::cout << "c > b ? " << (c > b ? "true" : "false") << std::endl;
    std::cout << "b > c ? " << (b > c ? "true" : "false") << std::endl << std::endl;

    std::cout << "--- operator << (stream output) ---" << std::endl;
    std::cout << "Print any coordinate directly, e.g., b -> " << b << std::endl << std::endl;

    return 0;
}
