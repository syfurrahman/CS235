// Syfur Rahman
// syfur.rahman94@myhunter.cuny.edu
// CSCI 235
// Project 2
// Algorithmic Adventures II: The Exponential Creature Odyssey
// Mindflayer.hpp
// Syfur Rahman
// syfur.rahman94@myhunter.cuny.edu
// CSCI 235
// Project 2
// Algorithmic Adventures II: The Exponential Creature Odyssey
// Mindflayer.hpp
#ifndef MINDFLAYER_HPP_
#define MINDFLAYER_HPP_

#include <iostream>
#include <string> 
#include <cctype>
#include <vector>
#include <algorithm>
#include "Creature.hpp"

class Mindflayer : public Creature {
public:
    enum Variant { PSIONIC, TELEPATHIC, ILLUSIONARY };

    struct Projectile {
        Variant type_;
        int quantity_;
    };

/**
  Default constructor.
  Default-initializes all private members. 
  Default Category: ALIEN
  Default summoning: False
*/
    Mindflayer();

    /**
  Parameterized constructor.
  @param      : A reference to the name of the Mindflayer (a string)
  @param      : The category of the Mindflayer (a Category enum) with default value ALIEN
  @param      : The Mindflayer's hitpoints (an integer), with default value 1 if not provided, or if the value provided is 0 or negative
  @param      : The Mindflayer's level (an integer), with default value 1 if not provided, or if the value provided is 0 or negative
  @param      : A flag indicating whether the Mindflayer is tame, with default value False
  @param      : The projectiles (a vector of Projectile structs), with default value an empty vector if not provided
  @param      : A flag indicating whether the Mindflayer can summon, with default value False
  @param      : The affinities (a vector of Variant enums), with default value an empty vector if not provided
  @post       : The private members are set to the values of the corresponding parameters.
  Hint: Notice the default arguments in the parameterized constructor.
*/
    Mindflayer(const std::string& name, Category category = ALIEN, int hitpoints = 1, int level = 1, bool tame = false, const std::vector<Projectile>& projectiles = {}, bool summoning = false, const std::vector<Variant>& affinities = {});

/**
  Getter for the projectiles.
  @return     : The projectiles (a vector of Projectile structs)
*/
    std::vector<Projectile> getProjectiles() const;


    void setProjectiles(const std::vector<Projectile>& projectiles);

    bool getSummoning() const;

    /**
  Setter for the projectiles.
  @param      : A reference to the projectiles (a vector of Projectile structs)
  @post       : The projectiles are set to the value of the parameter. There should not be any duplicate projectiles in Mindflayer's projectiles vector.
        : For example, if the vector in the given parameter contains the following Projectiles: {{PSIONIC, 2}, {TELEPATHIC, 1}, {PSIONIC, 1}, {ILLUSIONARY, 3}}, 
        : the projectiles vector should be set to contain the following Projectiles: {{PSIONIC, 3}, {TELEPATHIC, 1}, {ILLUSIONARY, 3}}.
        : If the quantity of a projectile is 0 or negative, it should not be added to the projectiles vector. 
        : Note the order of the projectiles in the vector.
*/

/**
  Getter for the summoning.
  @return     : The summoning (a boolean)
*/
    void setSummoning(const bool& summoning);

    std::vector<Variant> getAffinities() const;

    /**
    Setter for the affinities.
    @param      : A reference to the affinities (a vector of Variant enums)
    @post       : The affinities are set to the value of the parameter.
        : There should not be any duplicate affinities in Mindflayer's affinities vector. 
        : For example, if the vector in the given parameter contains the following affinities: {PSIONIC, TELEPATHIC, PSIONIC, ILLUSIONARY}, 
        : the affinities vector should be set to contain the following affinities: {PSIONIC, TELEPATHIC, ILLUSIONARY}.
        : Note the order of the affinities in the vector.
    */
    void setAffinities(const std::vector<Variant>& affinities);

    /**
    @param       : A reference to the Variant 
    @return      : The string representation of the variant
    */
    std::string variantToString(Variant variant) const;

private:
    std::vector<Projectile> projectiles_;
    std::vector<Variant> affinities_;
    bool summoning_;
};

#endif // MINDFLAYER_HPP_
