#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Create a ClapTrap instance named "CT1"
    // ClapTrap ct1("CT1");
    ScavTrap st1("ST1");

    // Perform an attack
    // ct1.attack("Enemy");

    // // Take some damage
    // ct1.takeDamage(4);

    // // Repair
    // ct1.beRepaired(5);

    // ct1.takeDamage(11);

    // Additional actions can be added here

    st1.attack("Enemy");

    // Take some damage
    st1.takeDamage(4);

    // Repair
    st1.beRepaired(5);

    st1.takeDamage(11);
    st1.guardGate();

    return 0;
}