#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include "Point.hpp"
using namespace std;

namespace ariel{

class Character {  

    private:
        string name;  // Private member variable for the character's name
        Point location;  // Private member variable for the character's location
        int hit_points;  // Private member variable for the character's hit points
        bool is_alive;  // Private member variable for the character's alive status

    public:
        // Constructors:
        Character();  // Default constructor
        Character(string name, Point location, int hit_points);  // Parameterized constructor
        Character(const Character &other);  // Copy constructor
        Character(Character &&other) noexcept;  // Move constructor

        // Assignment operators:
        Character &operator=(const Character &other);  // Copy assignment operator
        Character &operator=(Character &&other) noexcept;  // Move assignment operator

        // Pure virtual function for making a copy of this object
        virtual Character* Copy() const = 0;
        
        // Destructor:
        virtual ~Character();  // Virtual destructor to allow proper cleanup in derived classes

        // Getters:
        string getName();  // Returns the character's name
        Point getLocation();  // Returns the character's location
        int getHit_points();  // Returns the character's hit points

        // Setters:
        void setName(string);  // Sets the character's name
        void setLocation(Point);  // Sets the character's location
        void setHit_points(int);  // Sets the character's hit points

        // To string:
        string toString() const;  // Returns a string representation of the character

        // Checks if the character is alive
        bool isAlive();

        // Calculates the distance to another character
        double distance(Character *other);

        // Decreases the character's hit points by a certain amount
        void hit(int points);
        
        // Prints the character
        virtual string print();

        // Returns the type info of the character
        virtual const std::type_info& getType() const;
};

}