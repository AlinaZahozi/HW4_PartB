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
        return speed;
    }

    // Sets the speed of the ninja
    void Ninja::setSpeed(int otherSpeed) {
        speed = otherSpeed;
    }

    // Overriding the getType function from the Character class to get the type of the ninja
    const std::type_info& Ninja::getType() const {
        return typeid(Ninja);
    }

    // Function for moving the ninja towards the rival character
    void Ninja::move(Character* rival){}

    // Function for the ninja to slash the rival character
    void Ninja::slash(Character* rival){}

    // Overriding the print function from the Character class to print the ninja
    string Ninja::print() {
        //need to perform
        return "";
    }
}