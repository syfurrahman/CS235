// Syfur Rahman
// syfur.rahman94@myhunter.cuny.edu
// CSCI 235
// Project 2
// Algorithmic Adventures II: The Exponential Creature Odyssey
#include "Mindflayer.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

/**
  Default constructor.
  Default-initializes all private members. 
  Default Category: ALIEN
  Default summoning: False
*/
Mindflayer::Mindflayer() : Creature{}, projectiles_{}, affinities_{}, summoning_{false} {
    setCategory(ALIEN); // Set the category using the set function
}


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
Mindflayer::Mindflayer(const std::string& name, Category category, int hitpoints, int level,
                       bool tame, const std::vector<Projectile>& projectiles, bool summoning,
                       const std::vector<Variant>& affinities)
    : Creature(name, category, hitpoints, level, tame), projectiles_{}, affinities_{}, summoning_{summoning} {

    setProjectiles(projectiles);
    setAffinities(affinities);
}


/**
  Getter for the projectiles.
  @return     : The projectiles (a vector of Projectile structs)
*/

std::vector<Mindflayer::Projectile> Mindflayer::getProjectiles() const {
  return projectiles_;
}

// Setter for the projectiles
void Mindflayer::setProjectiles(
    const std::vector<Mindflayer::Projectile> &projectiles) {
  projectiles_.clear();
  for (const auto &projectile : projectiles) {
    if (projectile.quantity_ > 0) {
      projectiles_.emplace_back(projectile);
    }
  }
}

// Getter for the summoning
bool Mindflayer::getSummoning() const { return summoning_; }

// Setter for the summoning
void Mindflayer::setSummoning(const bool& summoning) { summoning_ = summoning; }

// Getter for the affinities
std::vector<Mindflayer::Variant> Mindflayer::getAffinities() const {
  return affinities_;
}

// Setter for the affinities
void Mindflayer::setAffinities(
    const std::vector<Mindflayer::Variant> &affinities) {
  affinities_.clear();
  for (const auto &affinity : affinities) {
    auto it = std::find(affinities_.begin(), affinities_.end(), affinity);
    if (it == affinities_.end()) {
      affinities_.emplace_back(affinity);
    }
  }
}

// Convert Variant to string
std::string Mindflayer::variantToString(Variant variant) const {
  switch (variant) {
  case PSIONIC:
    return "PSIONIC";
  case TELEPATHIC:
    return "TELEPATHIC";
  case ILLUSIONARY:
    return "ILLUSIONARY";
  default:
    return "UNKNOWN";
  }
}