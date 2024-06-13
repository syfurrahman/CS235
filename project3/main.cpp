#include "ArrayBag.hpp"
#include "Creature.hpp"
#include "Cavern.hpp"
#include <string>

int main() {
    // Create a Cavern object
    Cavern cavern;

    // Create some Creature objects
    Creature creature1("Creature1", Creature::UNKNOWN, 5, 10, true);
    Creature creature2("Bobby", Creature::UNKNOWN, 7, 5, false);
    Creature creature3("Creature3", Creature::MYSTICAL, 5, 1, false);
    Creature creature4("Holiday", Creature::ALIEN, 1, 2, false);
    Creature creature5("Sinbad", Creature::ALIEN, 17, 2, false);
    Creature creature6("Narnia", Creature::MYSTICAL, 31, 2, false);
    Creature creature7("Joe", Creature::UNDEAD, 3, 2, false);

    // Test enterCavern
    cavern.enterCavern(creature1);
    cavern.enterCavern(creature2);
    cavern.enterCavern(creature3);
    cavern.enterCavern(creature4);
    cavern.enterCavern(creature5);
    cavern.enterCavern(creature6);
    cavern.enterCavern(creature7); 

    cavern.cavernReport();



    // Test cavernReport

    return 0;
}