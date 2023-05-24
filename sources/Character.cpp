#include <iostream>
#include <string>
#include <stdio.h>
#include "Character.hpp"
using namespace std;


namespace ariel{

    // Parameterized constructor
    Character::Character(string name, Point location, int hit_points): 
    name(name),
    location(location),
    hit_points(hit_points),
    is_alive(true),
    is_availible(true){}

    // Copy constructor
    Character::Character(const Character& other):
    name(other.name),
    location(other.location),
    hit_points(other.hit_points),
    is_alive(other.is_alive),
    is_availible(other.is_availible){}

    // Move constructor
    Character::Character(Character &&other) noexcept:
    name(move(other.name)),
    location(move(other.location)),
    hit_points(move(other.hit_points)),
    is_alive(move(other.is_alive)),
    is_availible(move(other.is_availible)){}

    // Destructor:
    Character::~Character() = default;

    // Copy assignment operator
    Character& Character::operator=(const Character &other){
        name = other.name;
        location = other.location;
        hit_points = other.hit_points;
        is_alive = other.is_alive;
        is_availible = other.is_availible;
        return *this;
    }

    // Move assignment operator
    Character& Character::operator=(Character &&other) noexcept {
        name = move(other.name);
        location = move(other.location);
        hit_points = move(other.hit_points);
        is_alive = move(other.is_alive);
        is_availible = move(other.is_availible);
        return *this;
    }


    // Getters:
    string Character::getName(){
        return this->name;
    }

    Point Character::getLocation() const{
        return this->location;
    }

    int Character::getHit_points(){
        return this->hit_points;
    }

    bool Character::getIs_alive(){
        return this->is_alive;
    }

    bool Character::get_is_availible(){
        return this->is_availible;
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

    void Character::setIs_alive(bool alive){
        this->is_alive = alive;
    }

    void Character::set_is_availible(bool availible){
        this->is_availible = availible;
    }

    // To string:
    string Character::toString(){
        if(this->is_alive == true) return "Character name: " + this->name + ", location: " + this->location.toString() + ", hit points: " + to_string(this->hit_points) + ", still alive";
        else return "Character name: (" + this->name + "), already dead";
    }

    // Checks if the character is alive
    bool Character::isAlive(){
        return this->is_alive;
    }

    // Calculates the distance to another character
    double Character::distance(const Character *other) const{
        return location.distance(other->getLocation());
    }

    // Decreases the character's hit points by a certain amount
    void Character::hit(int points){
        if(points < 0) throw std::invalid_argument("Points cannot be negative");
        if(points > this->hit_points){
            this->hit_points = 0;
            this->is_alive = false;
        }
        else this->hit_points -= points;
    }

    // Prints the character
    string Character::print(){
        cout << this->toString();
        return this->toString();
    }

    // Returns the type info of the character
    const std::type_info& Character::getType() const {
        return typeid(Character);
    }

}