#include <iostream>
#include <string>
#include <stdio.h>
#include "Team.hpp"
#include "Team.hpp"
#include "typeinfo"
using namespace std;

namespace ariel{

    // Initializes a Team object with the given leader
    Team::Team(Character *leader):
    leader(leader){
        if (leader == nullptr) throw invalid_argument("Error: Leader is null");
        team.fill(nullptr);
        add(leader);
    }

    // Initializes a Team object as a copy of another
    Team::Team(const Team &other) :
    leader(other.leader){
        int size = team.size();
        for (size_t i = 0; i < size ; i++){
            if (other.team[i] != nullptr) team[i] = other.team[i]->Copy();
        }
    }

    // Destroys a Team object and releases any allocated resources
    Team::~Team(){
        for (size_t i = 0; i < 10; i++){
            if (team[i]) delete team[i];
        }
    }

    // Assigns the current Team object the same state as another
    Team &Team::operator=(const Team &other){
        return *this;
    }

    // Initializes a Team object by moving another
    Team::Team(Team &&other) noexcept:
    leader(other.leader){
        team = std::move(other.team);
        other.team.fill(nullptr);
    }

    // Assigns the current Team object the same state as another by moving
    Team &Team::operator=(Team &&other) noexcept{
        return *this;
    }

    // Adds a new player to the team
    void Team::add(Character *player){
        return;
    }

    // Makes the team attack a rival team
    void Team::attack(Team *rival){
        return;
    }

    // Checks if there are any players in the team that are still alive
    int Team::stillAlive(){
        return 0;
    }

    // Prints information about the team
    void Team::print(){
        return;
    }
}