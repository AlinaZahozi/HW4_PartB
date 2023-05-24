#include <iostream>
#include <string>
#include <stdio.h>
#include "Cowboy.hpp"


namespace ariel{

    // Constructor:
    Cowboy::Cowboy(string name, Point location): 
    Character(name, location, 110),
    bullets(6){}

    // Getter:
    int Cowboy::getBullets() {
        if(isAlive()== false) throw runtime_error("Error: This cowboy is already dead");
        return this->bullets;
    }

    // Setter:
    void Cowboy::setBullets(int bullet){
        if(isAlive() == false) throw runtime_error("Error: This cowboy is already dead");
        this->bullets = bullet;
    }

    // Function to simulate a cowboy shooting a rival character
    void Cowboy::shoot(Character * rival) {
        if(isAlive() == false) throw runtime_error("Error: This cowboy is already dead");
        if(rival->isAlive() == false) throw runtime_error("Error: This ninja is already dead");

        if(rival == this) throw runtime_error("Error: No self harm");

        else if(this->bullets <= 0) cout << "Run out of bullets\n";
        else{
            rival->hit(10);
            this->bullets--;
            if(rival->getHit_points() <= 0) rival->setIs_alive(false);
        }
    }

    // Function to check if the cowboy has bullets
    bool Cowboy::hasboolets() {
        if(isAlive() == false) throw runtime_error("Error: This cowboy is already dead");
        if(bullets > 0) return true;
        return false;
    }

    // Function to reload the cowboy's bullets
    void Cowboy::reload() {
        if(isAlive() == false) throw runtime_error("Error: This cowboy is already dead");
        this->bullets = 6;
    }

    // To string:
    string Cowboy::toString(){
        if(isAlive() == true) return "C: " + this->getName() + ", location: " + this->getLocation().toString() + ", hit points: " + to_string(this->getHit_points()) + ", still alive\n";
        else return "C: (" + this->getName() + "), already dead\n";
    }
}