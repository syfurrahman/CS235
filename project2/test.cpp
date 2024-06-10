#include <iostream>
#include <vector>
#include "Dragon.hpp"
#include "Ghoul.hpp"
#include "Mindflayer.hpp"

void printCreatureInfo(const Creature& creature) {
    std::cout << "NAME: " << creature.getName() << "\n"
              << "CATEGORY: " << creature.getCategory() << "\n"
              << "HP: " << creature.getHitpoints() << "\n"
              << "LVL: " << creature.getLevel() << "\n"
              << "TAME: " << creature.isTame() << "\n";

    if (const Dragon* dragon = dynamic_cast<const Dragon*>(&creature)) {
        // Additional Dragon-specific information
        std::cout << "ELEMENT: " << dragon->getElement() << "\n"
                  << "HEADS: " << dragon->getNumberOfHeads() << "\n"
                  << "FLIGHT: " << dragon->can_fly() << "\n";
    } else if (const Ghoul* ghoul = dynamic_cast<const Ghoul*>(&creature)) {
        // Additional Ghoul-specific information
        std::cout << "DECAY: " << ghoul->getDecay() << "\n"
                  << "FACTION: " << ghoul->getFaction() << "\n"
                  << "TRANSFORM: " << ghoul->canTransform() << "\n";
    } else if (const Mindflayer* mindflayer = dynamic_cast<const Mindflayer*>(&creature)) {
        // Additional Mindflayer-specific information
        std::cout << "SUMMONING: " << mindflayer->getSummoning() << "\n";

        // Print Projectiles
        const std::vector<Mindflayer::Projectile>& projectiles = mindflayer->getProjectiles();
        for (const auto& projectile : projectiles) {
            std::cout << mindflayer->variantToString(projectile.type_) << ": " << projectile.quantity_ << "\n";
        }

        // Print Affinities
        const std::vector<Mindflayer::Variant>& affinities = mindflayer->getAffinities();
        for (const auto& affinity : affinities) {
            std::cout << mindflayer->variantToString(affinity) << "\n";
        }
    }

    std::cout << "\n";
}

int main() {
    // 2.1 Dragons
    std::cout << "2.1.1 Default Dragon:\n";
    Dragon defaultDragon;
    printCreatureInfo(defaultDragon);

    std::cout << "2.1.2 Dragon Smog:\n";
    Dragon smogDragon("Smog");
    printCreatureInfo(smogDragon);

    std::cout << "2.1.3 Dragon Burny:\n";
    Dragon burnyDragon("Burny", Creature::UNDEAD, 100, 10, true, "FIRE", 1, true);
    printCreatureInfo(burnyDragon);

    std::cout << "2.1.4 Modified Burny:\n";
    burnyDragon.setElement("WATER");
    burnyDragon.setNumberOfHeads(2);
    burnyDragon.setNumberOfHeads(0);
    burnyDragon.setFlight(false);
    printCreatureInfo(burnyDragon);

    // 2.2 Ghouls
    std::cout << "2.2.1 Default Ghoul:\n";
    Ghoul defaultGhoul;
    printCreatureInfo(defaultGhoul);

    std::cout << "2.2.2 Ghoul Homph:\n";
    Ghoul homphGhoul("Homph");
    printCreatureInfo(homphGhoul);

    std::cout << "2.2.3 Ghoul Chomper:\n";
    Ghoul chomperGhoul("Chomper", Creature::ALIEN, 100, 10, true, 3, Ghoul::FLESHGORGER, true);
    printCreatureInfo(chomperGhoul);

    std::cout << "2.2.4 Modified Chomper:\n";
    chomperGhoul.setDecay(2);
    chomperGhoul.setDecay(-20);
    chomperGhoul.setFaction(Ghoul::SHADOWSTALKER);
    chomperGhoul.setTransformation(false);
    printCreatureInfo(chomperGhoul);

    // 2.3 Mindflayers
    std::cout << "2.3.1 Default Mindflayer:\n";
    Mindflayer defaultMindflayer;
    printCreatureInfo(defaultMindflayer);

    std::cout << "2.3.2 Mindflayer Bigbrain:\n";
    std::vector<Mindflayer::Projectile> projectiles = {{Mindflayer::PSIONIC, 2}, {Mindflayer::TELEPATHIC, 1}, {Mindflayer::PSIONIC, 1}, {Mindflayer::ILLUSIONARY, 3}};
    std::vector<Mindflayer::Variant> affinities = {Mindflayer::PSIONIC, Mindflayer::TELEPATHIC, Mindflayer::PSIONIC, Mindflayer::ILLUSIONARY};
    Mindflayer bigbrainMindflayer("Bigbrain", Creature::MYSTICAL, 100, 10, true, projectiles, true, affinities);
    printCreatureInfo(bigbrainMindflayer);

    return 0;
}
