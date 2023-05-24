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
        if(isAlive()== false) throw("Error: This cowboy is already dead");
        return this->bullets;
    }

    // Setter:
    void Cowboy::setBullets(int bullet){
        if(isAlive() == false) throw("Error: This cowboy is already dead");
        this->bullets = bullet;
    }

    // Function to simulate a cowboy shooting a rival character
    void Cowboy::shoot(Character * rival) {
        if(isAlive() == false) throw("Error: This cowboy is already dead");
        else if(bullets <= 0) throw("Error: Run out of bullets");
        else{
            rival->hit(10);
            bullets--;
        }
    }

    // Function to check if the cowboy has bullets
    bool Cowboy::hasboolets() {
        if(isAlive() == false) throw("Error: This cowboy is already dead");
        if(bullets > 0) return true;
        return false;
    }

    // Function to reload the cowboy's bullets
    void Cowboy::reload() {
        if(isAlive() == false) throw("Error: This cowboy is already dead");
        this->bullets = 6;
    }

    // To string:
    string Cowboy::toString(){
        if(isAlive() == true) return "C: " + this->getName() + ", location: " + this->getLocation().toString() + ", hit points: " + to_string(this->getHit_points()) + ", still alive\n";
        else return "C: (" + this->getName() + "), already dead\n";
    }

    /*// Overriding the print function from the Character class to print the cowboy
    string Cowboy::print() {
        //need to perform
        return "";
    }*/
}