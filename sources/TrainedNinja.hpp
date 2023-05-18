#pragma once
#include <iostream>
#include <string>
#include "Ninja.hpp"
using namespace std;
     
namespace ariel {

    class TrainedNinja : public Ninja {  // Defines the TrainedNinja class that inherits from the Ninja class

        public:

            // Constructor:
            TrainedNinja(string name, Point location);  // Parameterized constructor that initializes a trained ninja with a name and location
            
    };

}