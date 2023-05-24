#include <string>
#include <iostream>
#include "Ninja.hpp"
using namespace std;

namespace ariel {

    // Parameterized constructor that initializes a ninja with a name, location, and hit points
    Ninja::Ninja(string name, Point location, int hit_points):
    Character(name, location, hit_points),
    speed(0){}

    // Returns the speed of the ninja
    int Ninja::getSpeed(){
        return this->speed;
    }

    // Sets the speed of the ninja
    void Ninja::setSpeed(int otherSpeed) {
        this->speed = otherSpeed;
    }

    // Overriding the getType function from the Character class to get the type of the ninja
    const std::type_info& Ninja::getType() const {
        return typeid(Ninja);
    }

    // Function for moving the ninja towards the rival character
    void Ninja::move(Character* rival) {
        // Check if the rival is null
        if(rival == nullptr) throw std::invalid_argument("Rival cannot be null");

        // Check if the rival is already dead
        if(!rival->getIs_alive()) throw std::invalid_argument("Rival is already dead");

        // Check if the ninja is still alive
        if(!this->getIs_alive()) throw std::invalid_argument("Ninja is already dead");

        Point newLocation = this->location.moveTowards(this->location, rival->getLocation(), this->speed);
        this->setLocation(newLocation);
    }

    // Function for the ninja to slash the rival character
    void Ninja::slash(Character* rival) {
        // Check if the rival is null
        if(rival == nullptr) throw std::invalid_argument("Rival cannot be null");

        // Check if the rival is already dead
        if(!rival->getIs_alive()) throw std::invalid_argument("Rival is already dead");

        // Check if the ninja is still alive
        if(!this->getIs_alive()) throw std::invalid_argument("Ninja is already dead");

        // Calculate the distance to the rival
        double distanceToRival = this->distance(rival);

        // If the rival is less than 1 meter away, slash the rival
        if(distanceToRival < 1.0) rival->hit(40);
    }

    // To string:
    string Ninja::toString(){
        if(isAlive() == true) return "N: " + this->getName() + ", location: " + this->getLocation().toString() + ", hit points: " + to_string(this->getHit_points()) + ", still alive\n";
        else return "N: (" + this->getName() + "), already dead\n";
    }

    // Overriding the print function from the Character class to print the ninja
    //string Ninja::print() {
    //    //need to perform
    //    return "";
    //}
}