#include "ClapTrap.hpp"

int main() {
    // Create a ClapTrap instance named "CT1"
    ClapTrap ct1("CT1");

    // Perform an attack
    ct1.attack("Enemy");

    // Take some damage
    ct1.takeDamage(4);

    // Repair
    ct1.beRepaired(5);

    ct1.takeDamage(11);
    return 0;
}