//Syfur Rahman
//syfur.rahman94@myhunter.cuny.edu
// Project 1
// Creature.hpp

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <string>
#include <algorithm>

class Creature {
  public:
    enum Category { UNKNOWN, UNDEAD, MYSTICAL, ALIEN };

    // Constructors
    Creature();
    Creature(const std::string& name, Category category = UNKNOWN,
             int hitpoints = 1, int level = 1, bool is_tame = false);

    // Accessors (get)
    std::string getName() const;
    std::string getCategory() const;
    int getHitpoints() const;
    int getLevel() const;
    bool isTame() const;

    // Mutators (set)
    bool setName(const std::string& name);
    void setCategory(const Category& category);
    bool setHitpoints(const int& hitpoints);
    bool setLevel(const int& level);
    void setTame(const bool& is_tame);

    // Display function
    void display() const;
    
  private:
    // The name of the creature (a string in UPPERCASE)
    std::string name_;
    // The category of the creature (an enum)
    Category category_;
    // The creature's hitpoints (an integer)
    int hitpoints_;
    // The creature's level (an integer)
    int level_;
    // A boolean flag indicating whether the creature is tame
    bool is_tame_;
};

#endif // Ends CREATURE_HPP
