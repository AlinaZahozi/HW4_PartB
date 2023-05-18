#include <iostream>
#include <string>
#include <stdio.h>
#include "Point.hpp"

namespace ariel{

    // Constructors:
    Point::Point(){
        this->x_cordinta = 0;
        this->y_cordinta = 0;
    }

    Point::Point(double x ,double y){
        this->x_cordinta = x;
        this->y_cordinta = y;
    }

    // Getters:
    double Point::getX(){
        return this->x_cordinta;
    }
    
    double Point::getY(){
        return this->y_cordinta;
    }

    // Setters:
    void Point::setX(double x){
        this->x_cordinta = x;
    }

    void Point::setY(double y){
        this->y_cordinta = y;
    }

    // To string:
    string Point::toString() const{
        return "(" + to_string(this->x_cordinta) + ", " + to_string(this->y_cordinta) + ")";
    }

    // Calculates the distance to another point
    double Point::distance(Point other){
        //need to perform
        return 0;
    }

    // Prints the point
    void Point::print(){
        cout << this->toString() << endl;
    }

    // Moves towards another point by a specified distance
    Point Point::moveTowards(Point src , Point dst , double dist){
        //need to perform
        return Point(0,0);
    }
}