#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <limits>
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
        players_number = 0;
        add(leader);
    }

    // Initializes a Team object as a copy of another
    Team::Team(const Team &other) :
    leader(other.leader){
        for (size_t i = 0; i < team.size() ; i++){
            if (other.team[i] != nullptr) team[i] = other.team[i]->Copy();
        }
    }

    // Destroys a Team object and releases any allocated resources
    Team::~Team(){
        for (size_t i = 0; i < 10; i++){
            if (team[i] != nullptr) delete team[i];
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
    void Team::add(Character* player){
        if(player == nullptr) throw invalid_argument("Player cannot be null.");
        if(this->players_number >= 10) throw overflow_error("Team is already full.");
        
        auto it = std::find(team.begin(), team.end(), nullptr);
        
        if(it != team.end()){
            *it = player;
            this->players_number ++;
        }
    }

    // Makes the team attack a rival team
    void Team::attack(Team* rival){

        if(rival == nullptr)throw invalid_argument("Rival team cannot be null.");

        if(this->stillAlive() == 0 || rival->stillAlive() == 0) return;  // No members left in one of the teams, end the attack

        // Check if the leader is alive
        if(!this->leader->getIs_alive()){
            // If not, select a new leader
            double closest_distance = std::numeric_limits<double>::max();
            for(auto& character : this->team){
                if(character != nullptr && character->getIs_alive()){
                    double distance = this->leader->getLocation().distance(character->getLocation());
                    if(distance < closest_distance){
                        closest_distance = distance;
                        this->leader = character;
                    }
                }
            }
        }

        // Select a victim from the rival team
        Character* victim = nullptr;
        double closest_distance = std::numeric_limits<double>::max();
        for(auto& character : rival->team){
            if(character != nullptr && character->getIs_alive()){
                double distance = this->leader->getLocation().distance(character->getLocation());
                if(distance < closest_distance){
                    closest_distance = distance;
                    victim = character;
                }
            }
        }

        // All living members of this team attack the victim
        for(auto& character : this->team){
            if(character != nullptr && character->getIs_alive()){
                // Depending on the type of the character, perform the attack
                if(typeid(*character) == typeid(Cowboy)){
                    Cowboy* cowboy = static_cast<Cowboy*>(character);
                    if(cowboy->getBullets() > 0) cowboy->shoot(victim);
                    else cowboy->reload();
                }
                else if(typeid(*character) == typeid(Ninja)){
                    Ninja* ninja = static_cast<Ninja*>(character);
                    if(ninja->getLocation().distance(victim->getLocation()) <= 1.0) ninja->slash(victim);
                    else ninja->move(victim);
                }
            }

            // If the victim is dead, choose a new victim
            if(!victim->getIs_alive()){
                victim = nullptr;
                closest_distance = std::numeric_limits<double>::max();
                for(auto& character : rival->team){
                    if(character != nullptr && character->getIs_alive()){
                        double distance = this->leader->getLocation().distance(character->getLocation());
                        if(distance < closest_distance){
                            closest_distance = distance;
                            victim = character;
                        }
                    }
                }
            }

            // If there are no living members in the rival team, end the attack
            if(rival->stillAlive() == 0) break;
        }
    }


    // Checks if there are any players in the team that are still alive
    int Team::stillAlive(){
        int ans = 0;
        for (size_t i = 0; i < 10; i++){
            if (team[i] != nullptr){
                if(team[i]->getIs_alive() == true) ans++;
            }
        }
        return ans;
    }

    // Prints information about the team
    void Team::print(){
        for (size_t i = 0; i < 10; i++){
            if (team[i] != nullptr){
               if(i == 0) cout << "The leader of the team: " + team[i]->getName() + "\n";
               team[i]->print();
            }
        }
    }
}