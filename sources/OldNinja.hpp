#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include "Ninja.hpp"
using namespace std;

namespace ariel {

    class OldNinja : public Ninja {  // Defines the OldNinja class that inherits from the Ninja class

        public:

            // Constructor:
            OldNinja(string name, Point location);  // Parameterized constructor that initializes an old ninja with a name and location
            
    };


};
