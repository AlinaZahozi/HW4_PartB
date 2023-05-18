#include "SmartTeam.hpp"

namespace ariel {

    // Initializes a SmartTeam object with the given leader
    SmartTeam::SmartTeam(Character* leader):
    Team(leader){
        if (leader == nullptr) throw invalid_argument("Error: Leader is null");
    }

    // Overrides the print function of the base class to display information about SmartTeam
    void SmartTeam::print(){
        return;
    }
}