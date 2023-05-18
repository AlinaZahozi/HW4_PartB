#include "Team.hpp"

namespace ariel {

    class Team2 : public Team { // Team2 is a subclass of Team

    public:
        // Constructor:
        Team2(Character* leader); // Initializes a Team2 object with the given leader

        void print() override; // Overrides the print function of the base class to display information about Team2
    };

}