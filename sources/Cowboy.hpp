#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include"Character.hpp"
using namespace std;

namespace ariel {

    class Cowboy : public Character {  // Defines the Cowboy class that inherits from the Character class

        private:

            int bullets;  // Private member variable for the number of bullets the cowboy has

        public:

            // Constructor:
            Cowboy(string name, Point location);  // Parameterized constructor that initializes a cowboy with a name and location

            // Overriding the pure virtual function from the Character class to create a copy of this object
            Character* Copy() const override {
            return new Cowboy(*this);
            }

            // Getter:
            int getBullets();  // Returns the number of bullets the cowboy has

            // Setter:
            void setBullets(int bul);  // Sets the number of bullets the cowboy has

            // Function to simulate a cowboy shooting a rival character
            void shoot(Character *rival);

            // Function to check if the cowboy has bullets
            bool hasboolets();

            // Function to reload the cowboy's bullets
            void reload();
            
            // Overriding the print function from the Character class to print the cowboy
            string print() override;
    };

}