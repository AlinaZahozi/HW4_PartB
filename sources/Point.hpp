#pragma once  // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
using namespace std;

namespace ariel{ 

class Point { 
    protected:
        double x_cordinta;  // Private member variable for the x-coordinate
        double y_cordinta;  // Private member variable for the y-coordinate

    public:
        // Constructors:
        Point();  // Default constructor
        Point(double x_cord ,double y_cord);  // Parameterized constructor

        // Getters:
        double getX();  // Returns the x-coordinate
        double getY();  // Returns the y-coordinate
        
        // Setters:
        void setX(double x_cord);  // Sets the x-coordinate
        void setY(double y_cord);  // Sets the y-coordinate

        // To string:
        string toString() const;  // Returns a string representation of the point

        // Calculates the distance to another point
        double distance(const Point &other) const;

        // Prints the point
        void print();

        // Moves towards another point by a specified distance
        Point moveTowards(const Point &src, const Point &dst, double dist) const;
};

}
