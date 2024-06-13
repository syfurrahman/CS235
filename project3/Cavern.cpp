/*
CSCI235 Spring 2024
Project 3 - The Cavern
Syfur Rahman
March 7th, 2024
In this project you will implement the Cavern class, where you will house your Creatures. 
*/

#include "Cavern.hpp"
#include "ArrayBag.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

/**
  Default constructor.
  Default-initializes all private members. 
*/
Cavern::Cavern() : level_sum_(0), tame_count_(0) 
{
    
}

/** 
  * @param   :   A reference to a Creature entering the Cavern
  * @post    :   If the given Creature is not already in the Cavern, add Creature to the Cavern and updates the level sum and the tame Creature count if the creature is tame.
  * @return  :   returns true if a Creature was successfully added to the Cavern, false otherwise
            :   Hint: Use the above definition of equality will help determine if a Creature is already in the Cavern
**/
bool Cavern::enterCavern(const Creature& creature) {
    // Check if the creature is not already in the Cavern
    if (!contains(creature)) {
        // Add the creature to the Cavern
        if (add(creature)) {
            // Update the level sum
            level_sum_ += creature.getLevel();

            // Update the tame count if the creature is tame
            if (creature.isTame()) {
                tame_count_++;
            }

            // Successfully added to the Cavern
            return true;
        }
    }

    // Creature is already in the Cavern or failed to add
    return false;
}

/** 
  * @param   :   A  reference to a Creature leaving the Cavern
  * @return  :  returns true if a creature was successfully removed from the Cavern (i.e. items_), false otherwise
  * @post    :    removes the creature from the Cavern and updates the level sum. 
                  If the Creature is tame it also updates the tame count.
**/
bool Cavern::exitCavern(const Creature &creature) {
    if (remove(creature)) {
        level_sum_ -= creature.getLevel();
        if (creature.isTame()) {
            tame_count_--;
        }
        return true;
    }
    return false;
}

 /** 
  * @return   :  The integer level count of all the creatures currently in the Cavern
  **/
 int Cavern::getLevelSum() const {
    return level_sum_;
}

 /**
  * @return   :  The average level (int) of all the creatures in the Cavern
  * @post     :  Computes the average level (double) of the Cavern rounded to the NEAREST integer.
  **/
int Cavern::calculateAvgLevel() const {
    if (getCurrentSize() == 0) {
        return 0; // Avoid division by zero
    }
    return static_cast<int>(std::round(level_sum_ * 1.0 / getCurrentSize()));
}
 /**
  * @return   :  The integer count of tame Creatures in the Cavern
  **/
 int Cavern::getTameCount() const {
    return tame_count_;
}

 /**
  * @return   :  The percentage (double) of all the tame creatures in the Cavern
  * @post     :   Computes the percentage of tame creatures in the Cavern rounded up to 2 decimal places.
  **/
 double Cavern::calculateTamePercentage() const {
    if (getCurrentSize() == 0) {
        return 0.0; // Avoid division by zero
    }
    return std::ceil((tame_count_*1.0) / getCurrentSize() * 10000.0)/100; 
}

 /**
    @param  : A reference to a string representing a creature Category with a value in ["UNKNOWN", "UNDEAD", "MYSTICAL", "ALIEN"], or default value "ALL" if no category is given
    @post   : Removes all creatures from the Cavern whose category matches the given category. If no category is given, removes all creatures from the Cavern.
    @return : The number of creatures removed from the Cavern
              NOTE: no pre-processing of the input string necessary, only uppercase input will match. If the input string does not match one of the expected category values, do not remove any creatures.
*/
int Cavern::tallyCategory(const std::string &category) const {
    int count = 0;
    for (int i = 0; i < getCurrentSize(); i++) {
        if(items_[i].getCategory() == category) {
            count++;
        }
    }
    return count;
}


/**
    @param  :   An integer representing the level threshold of the creatures to be removed from the Cavern, with default value 0
    @post   :   Removes all creatures from the Cavern whose level is less than the given level. If no level is given, removes all creatures from the Cavern. Ignore negative input.
    @return :   The number of creatures removed from the Cavern
*/
int Cavern::releaseCreaturesBelowLevel(int level) {
    int size = getCurrentSize();
    int numRemoved = 0;

    if (level < 0) {
        return 0;
    } else if (level== 0) {
        numRemoved = size;
        clear(); // Assuming clear() is a function to remove all creatures
    } else {
        for (int i = 0; i < size; i++) {
            if (ArrayBag<Creature>::items_[i].getLevel() < level) {
                Creature toBeRemoved = ArrayBag<Creature>::items_[i];
                exitCavern(toBeRemoved);
                numRemoved++;
            }
        }
    }

    return numRemoved;
}

/**
    @param  : A reference to a string representing a creature Category with a value in ["UNKNOWN", "UNDEAD", "MYSTICAL", "ALIEN"], or default value "ALL" if no category is given
    @post   : Removes all creatures from the Cavern whose category matches the given category. If no category is given, removes all creatures from the Cavern.
    @return : The number of creatures removed from the Cavern
              NOTE: no pre-processing of the input string necessary, only uppercase input will match. If the input string does not match one of the expected category values, do not remove any creatures.
*/
int Cavern::releaseCreaturesOfCategory(const std::string& category) {
    int count = 0;

    for (int i = 0; i < getCurrentSize(); i++) {
        const Creature& currentCreature = ArrayBag<Creature>::items_[i];

        // Check if the category is "ALL" or matches the current creature's category
        if (category == "ALL" || currentCreature.getCategory() == category) {
            // Update count and remove the creature from the Cavern
            if (exitCavern(currentCreature)) {
                count++;
            }
        }
    }

    return count;
}

/**
  * @post    : Outputs a report of the creatures currently in the Cavern in the form:
              "UNKNOWN: [x]\nUNDEAD: [x]\nMYSTICAL: [x]\nALIEN: [x]\n\nAVERAGE LEVEL: [x]\nTAME:[x]%\n"
              Note that the average level should be rounded to the NEAREST integer, and the percentage of tame creatures in the Cavern should be rounded to 2 decimal places.

              Example output: 
              UNKNOWN: 1
              UNDEAD: 3
              MYSTICAL: 2
              ALIEN: 1

              AVERAGE LEVEL: 5
              TAME: 85.72%
*/
void Cavern::cavernReport() const {
    std::cout << "UNKNOWN: " << tallyCategory("UNKNOWN") << std::endl;
    std::cout << "UNDEAD: " << tallyCategory("UNDEAD") << std::endl;
    std::cout << "MYSTICAL: " << tallyCategory("MYSTICAL") << std::endl;
    std::cout << "ALIEN: " << tallyCategory("ALIEN") << std::endl;

    int averageLevel = calculateAvgLevel();
    double tamePercentage = calculateTamePercentage();

    std::cout << "\nAVERAGE LEVEL: " << averageLevel << std::endl;
    std::cout << "TAME: " << tamePercentage << "%" << std::endl;
}