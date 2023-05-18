#include "Team.hpp"
using namespace std;
     
namespace ariel {

    class SmartTeam : public Team { // SmartTeam is a subclass of Team

    public:
        // Constructor:
        SmartTeam(Character* leader); // Initializes a SmartTeam object with the given leader

        void print() override; // Overrides the print function of the base class to display information about SmartTeam
    };

}