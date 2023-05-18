#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include "Character.hpp"
using namespace std;
     

namespace ariel {

    class Ninja : public Character {  // Defines the Ninja class that inherits from the Character class

        private:

            int speed;  // Private member variable for the speed of the ninja
            
        public:

            // Constructor:
            Ninja(string name,Point location,int hit_points);  // Parameterized constructor that initializes a ninja with a name, location, and hit points

            // Overriding the pure virtual function from the Character class to create a copy of this object
            Character* Copy() const override {
                return new Ninja(*this);
            }

            // Getter:
            int getSpeed();  // Returns the speed of the ninja

            // Setter:
            void setSpeed(int speed);  // Sets the speed of the ninja

            // Function for moving the ninja towards the rival character
            void move(Character* rival);

            // Function for the ninja to slash the rival character
            void slash(Character* rival);

            // Overriding the print function from the Character class to print the ninja
            string print() override;

            // Overriding the getType function from the Character class to get the type of the ninja
            const std::type_info& getType() const override;

    };

}