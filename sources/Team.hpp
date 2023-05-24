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

    constexpr int MAXIMUM_PLAYERS = 10; // Maximum number of players in a team

    class Team {

    protected:
        array<Character*, MAXIMUM_PLAYERS> team; // Array to hold pointers to Character objects (team members)
        Character* leader; // Pointer to the Character object that is the team leader
        int players_number; // Integer to hold the amount of players in this team
        bool alive; // To check if the team is alive

    public:
        // Constructor:
        Team(Character* leader); // Initializes a Team object with the given leader
        
        // Copy Constructor:
        Team(const Team& other); // Initializes a Team object as a copy of another

        // Move Constructor:
        Team(Team&& other) noexcept; // Initializes a Team object by moving another

        // Destructor:
        virtual ~Team(); // Destroys a Team object and releases any allocated resources

        // Copy Assignment Operator:
        Team& operator=(const Team& other); // Assigns the current Team object the same state as another

        // Move Assignment Operator:
        Team& operator=(Team&& other) noexcept; // Assigns the current Team object the same state as another by moving

        // To get alive
        bool get_alive();

        // To set alive to false
        void is_dead();

        // Member Functions:
        virtual void add(Character* player); // Adds a new player to the team
        virtual void attack(Team* rival); // Makes the team attack a rival team
        virtual int stillAlive(); // Checks if there are any players in the team that are still alive
        virtual void print(); // Prints information about the team
    };
}
