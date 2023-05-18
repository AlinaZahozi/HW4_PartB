#include "YoungNinja.hpp"

namespace ariel {

    // Parameterized constructor that initializes a young ninja with a name and location
    YoungNinja::YoungNinja(string name, Point location) :
    Ninja(name, location, 100){
        setSpeed(14);
    }
}