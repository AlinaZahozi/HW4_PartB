#include <iostream>
#include <string>
#include <stdio.h>
#include "Character.hpp"
using namespace std;


namespace ariel{

    // Default constructor
    Character::Character(){
        this->name = "No name";
        Point center(0,0);
        this->location = center;
        this->hit_points = 0;
        this->is_alive = true;
    }

    // Parameterized constructor
    Character::Character(string name, Point location, int hit_points): 
    name(name),
    location(location),
    hit_points(hit_points),
    is_alive(true){}

    // Copy constructor
    Character::Character(const Character& other):
    name(other.name),
    location(other.location),
    hit_points(other.hit_points),
    is_alive(other.is_alive){}

    // Move constructor
    Character::Character(Character &&other) noexcept:
    name(move(other.name)),
    location(move(other.location)),
    hit_points(move(other.hit_points)),
    is_alive(move(other.is_alive)){}

    // Destructor:
    Character::~Character() = default;

    // Copy assignment operator
    Character& Character::operator=(const Character &other){
        name = other.name;
        location = other.location;
        hit_points = other.hit_points;
        is_alive = other.is_alive;
        return *this;
    }

    // Move assignment operator
    Character& Character::operator=(Character &&other) noexcept {
        name = move(other.name);
        location = move(other.location);
        hit_points = move(other.hit_points);
        is_alive = move(other.is_alive);
        return *this;
    }


    // Getters:
    string Character::getName(){
        return this->name;
    }

    Point Character::getLocation(){
        return this->location;
    }

    int Character::getHit_points(){
        return this->hit_points;
    }

    // Setters:
    void Character::setName(string name){
        this->name = name;
    }

    void Character::setLocation(Point location){
        this->location = location;
    }

    void Character::setHit_points(int points){
        this->hit_points = points;
    }

    // To string:
    string Character::toString() const{
        //need to perform
        return "";
    }

    // Checks if the character is alive
    bool Character::isAlive(){
        return true;
    }

    // Calculates the distance to another character
    double Character::distance(Character *player){
        return 0;
    }

    // Decreases the character's hit points by a certain amount
    void Character::hit(int points){
        return;
    }

    // Prints the character
    string Character::print(){
        //need to perform
        return "";
    }

    // Returns the type info of the character
    const std::type_info& Character::getType() const {
        return typeid(Character);
    }

}