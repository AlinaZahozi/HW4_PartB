#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <limits>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
using namespace std;

namespace ariel {

    constexpr int MAXIMUM_PLAYERS_TEAM2 = 10; // Maximum number of players in a team

    class Team2 {

    protected:
        array<Character*, MAXIMUM_PLAYERS_TEAM2> team; // Array to hold pointers to Character objects (team members)
        Character* leader; // Pointer to the Character object that is the team leader
        int players_number;

    public:
        // Constructor:
        Team2(Character* leader); // Initializes a Team object with the given leader
        
        // Copy Constructor:
        Team2(const Team2& other); // Initializes a Team object as a copy of another

        // Move Constructor:
        Team2(Team2&& other) noexcept; // Initializes a Team object by moving another

        // Destructor:
        ~Team2(); // Destroys a Team object and releases any allocated resources

        // Copy Assignment Operator:
        Team2& operator=(const Team2& other); // Assigns the current Team object the same state as another

        // Move Assignment Operator:
        Team2& operator=(Team2&& other) noexcept; // Assigns the current Team object the same state as another by moving

        // Member Functions:
        virtual void add(Character* player); // Adds a new player to the team
        virtual void attack(Team2* rival); // Makes the team attack a rival team
        virtual int stillAlive(); // Checks if there are any players in the team that are still alive
        virtual void print(); // Prints information about the team
    };
}
