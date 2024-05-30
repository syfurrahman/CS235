#include "Creature.hpp"

int main() {
    
    Creature creature1; // Instantiate a creature with the default constructor
    creature1.setHitpoints(10); // Set hitpoints to 10
    creature1.setLevel(5); // Set level to 5
    creature1.setTame(true); // Set tame flag to True

    // Print out the creature's information using the display() function
    creature1.display();

    // Expected output:
    // NAMELESS
    // Category: UNKNOWN
    // Level: 5
    // Hitpoints: 10
    // Tame: TRUE

    // 2.2
    Creature creature2("Wormy", Creature::MYSTICAL, 3, 2); // Instantiate a creature with the parameterized constructor
    creature2.setTame(true); // Set Wormy as Tame

    // Print out the creature's information using the display() function
    creature2.display();

    // Expected output:
    // WORMY
    // Category: MYSTICAL
    // Level: 2
    // Hitpoints: 3
    // Tame: TRUE

    return 0;
}
