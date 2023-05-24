#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include "Point.hpp"
using namespace std;

namespace ariel{

class Character {  

    protected:
        string name;  // protected member variable for the character's name
        Point location;  // protected member variable for the character's location
        int hit_points;  // protected member variable for the character's hit points
        bool is_alive;  // protected member variable for the character's alive status
        bool is_availible;

    public:
        // Constructors:
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
        Point getLocation() const;  // Returns the character's location
        int getHit_points();  // Returns the character's hit points
        bool getIs_alive();
        bool get_is_availible();

        // Setters:
        void setName(string);  // Sets the character's name
        void setLocation(Point);  // Sets the character's location
        void setHit_points(int);  // Sets the character's hit points
        void setIs_alive(bool);
        void set_is_availible(bool);

        // To string:
        virtual string toString();  // Returns a string representation of the character

        // Checks if the character is alive
        bool isAlive();

        // Calculates the distance to another character
        double distance(const Character *other) const;

        // Decreases the character's hit points by a certain amount
        void hit(int points);
        
        // Prints the character
        virtual string print();

        // Returns the type info of the character
        virtual const std::type_info& getType() const;
};

}