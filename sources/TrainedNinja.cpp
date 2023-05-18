#include "TrainedNinja.hpp"

namespace ariel {

    // Parameterized constructor that initializes a trained ninja with a name and location
    TrainedNinja::TrainedNinja(string name, Point location) :
    Ninja(name, location, 120){
        setSpeed(12);
    }
}