#include "Team2.hpp"
using namespace std;

namespace ariel {

    // Initializes a Team2 object with the given leader
    Team2::Team2(Character* leader):
    Team(leader){
        if (leader == nullptr) throw invalid_argument("Error: Leader is null");
    }
}
