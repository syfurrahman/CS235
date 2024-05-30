// Syfur Rahman
// syfur.rahman94@myhunter.cuny.edu
// Project 1
// Creature.cpp

#include "Creature.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

// Default constructor
Creature::Creature() : name_("NAMELESS"), category_(UNKNOWN), hitpoints_(1), level_(1), is_tame_(false) {}

// Parameterized constructor
Creature::Creature(const std::string& name, Category category, int hitpoints, int level, bool is_tame)
    : name_("NAMELESS"), category_(UNKNOWN), hitpoints_(1), level_(1), is_tame_(false) {

    setName(name);
    setCategory(category);
    setHitpoints(hitpoints);
    setLevel(level);
    setTame(is_tame);
}

// Accessors (get)

/** getName
      @return : the name of the Creature
  */

std::string Creature::getName() const {
    return name_;
}

/** getCategory
      @return : the category of the Creature (in string form)
   */

std::string Creature::getCategory() const {
    switch (category_) {
        case UNKNOWN: return "UNKNOWN";
        case UNDEAD: return "UNDEAD";
        case MYSTICAL: return "MYSTICAL";
        case ALIEN: return "ALIEN";
        default: return "UNKNOWN";
    }
}

 /** getHitpoints:
      @return : the value stored in hitpoints_
   */

int Creature::getHitpoints() const {
    return hitpoints_;
}

/** getLevel
      @return : the value stored in level_
   */

int Creature::getLevel() const {
    return level_;
}

/** isTame:
    @return true if the creature is tame, false otherwise
    Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getTame
   */

bool Creature::isTame() const {
    return is_tame_;
}

// Mutators (set)

/** setName
    @param : the name of the Creature, a reference to string
    @post  : sets the Creature's name to the value of the parameter in UPPERCASE. 
             (convert any lowercase character to uppercase)
             Only alphabetical characters are allowed. 
           : If the input contains non-alphabetic characters, do nothing.
    @return : true if the name was set, false otherwise
*/

bool Creature::setName(const std::string& name) {
    std::string uppercaseName;
    
    // Check if all characters are alphabetic
    for (char ch : name) {
        if (!isalpha(ch)) {
            return false; // Non-alphabetic character found, do nothing
        }
    }

    // Convert to UPPERCASE
    for (char ch : name) {
        uppercaseName += toupper(ch);
    }

    // Set the uppercase name to the member variable
    name_ = uppercaseName;
    return true;
}

/** setCategory
      @param  : a reference to Category, the category of the Creature (an enum)
      @post   : sets the Creature's category to the value of the parameter
              : If the given category was invalid, set category_ to UNKNOWN.
*/

void Creature::setCategory(const Category& category) {
    category_ = category;
}

 /** setHitpoints
    @param  : a reference to integer that represents the creature's hitpoints
    @pre    : hitpoints >= 0 : Characters cannot have negative hitpoints 
              (do nothing for invalid input)
    @post   : sets the hitpoints private member to the value of the parameter
    @return : true if the hitpoints were set, false otherwise
  */

bool Creature::setHitpoints(const int& hitpoints) {
    if (hitpoints >= 0) {
        hitpoints_ = hitpoints;
        return true;
    }
    return false;
}

/** setLevel
    @param  : a reference to integer level
    @pre    : level >= 0 : Characters cannot have a negative level
    @post   : sets the level private member to the value of the parameter 
             (do nothing for invalid input)
    @return : true if the level was set, false otherwise
  */

bool Creature::setLevel(const int& level) {
    if (level >= 0) {
        level_ = level;
        return true;
    }
    return false;
}

 /**
      @param  : a reference to boolean value
      @post   : sets the tame flag to the value of the parameter
  */


void Creature::setTame(const bool& is_tame) {
    is_tame_ = is_tame;
}

// Display function
 /**
    @post     : displays Creature data in the form:
              "[NAME]\n
               Category: [CATEGORY]\n
               Level: [LEVEL]\n
               Hitpoints: [Hitpoints]\n
               Tame: [TRUE/FALSE]"   
*/
void Creature::display() const {
    std::cout << name_ << "\n";
    std::cout << "Category: ";
    
    // Convert Category enum to string for display
    switch (category_) {
        case UNKNOWN:
            std::cout << "UNKNOWN";
            break;
        case UNDEAD:
            std::cout << "UNDEAD";
            break;
        case MYSTICAL:
            std::cout << "MYSTICAL";
            break;
        case ALIEN:
            std::cout << "ALIEN";
            break;
    }

    std::cout << "\nLevel: " << level_ << "\n";
    std::cout << "Hitpoints: " << hitpoints_ << "\n";
    std::cout << "Tame: " << (is_tame_ ? "TRUE" : "FALSE") << std::endl;
}