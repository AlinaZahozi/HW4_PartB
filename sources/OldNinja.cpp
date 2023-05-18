#include "OldNinja.hpp"

namespace ariel {

    // Parameterized constructor that initializes an old ninja with a name and location
    OldNinja::OldNinja(string name, Point location) :
    Ninja(name, location, 150){
        setSpeed(8);
    }
}
