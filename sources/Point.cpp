#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <stdexcept>
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
    double Point::distance(const Point& other) const {
        double calX = other.x_cordinta - this->x_cordinta;
        double calY = other.y_cordinta - this->y_cordinta;
        return sqrt(calX * calX + calY * calY);
    }


    // Prints the point
    void Point::print(){
        cout << this->toString() << endl;
    }

    // Moves towards another point by a specified distance
    Point Point::moveTowards(const Point &src, const Point &dst, double dist){
        // Throw an exception if the distance is negative.
        if (dist < 0) throw invalid_argument("Distance cannot be negative");

        double calX = dst.x_cordinta - src.x_cordinta;
        double calY = dst.y_cordinta - src.y_cordinta;

        double len = sqrt(calX * calX + calY * calY);

        // If the source and destination are the same, there's nowhere to move
        if (len == 0) {
            if (dist == 0) return src;
            else throw invalid_argument("Source and destination are the same, distance should be zero");
        }

        // Normalize the direction vector (calX, calY)
        calX /= len;
        calY /= len;

        // Scale it by the desired distance and add to the source point
        double newX = src.x_cordinta + calX * dist;
        double newY = src.y_cordinta + calY * dist;

        // Check if the moved point is beyond the destination point
        double distSrcToMoved = sqrt(pow(newX - src.x_cordinta, 2) + pow(newY - src.y_cordinta, 2));
        double distSrcToDest = sqrt(pow(dst.x_cordinta - src.x_cordinta, 2) + pow(dst.y_cordinta - src.y_cordinta, 2));

        if (distSrcToMoved > distSrcToDest) return dst; // The moved point is beyond the destination point, return the destination point

        return Point(newX, newY);
    }

}