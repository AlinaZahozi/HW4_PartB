#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include "Ninja.hpp"
using namespace std;

namespace ariel {

    class YoungNinja : public Ninja {  // Defines the YoungNinja class that inherits from the Ninja class

        public:

            // Constructor:
            YoungNinja(string name, Point location);  // Parameterized constructor that initializes a young ninja with a name and location
            
    };

}