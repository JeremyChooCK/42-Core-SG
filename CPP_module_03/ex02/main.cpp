#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Create a ClapTrap instance named "CT1"
    // ClapTrap ct1("CT1");
    // ScavTrap st1("ST1");
    FragTrap ft1("FT1");

    // Perform an attack
    // ct1.attack("Enemy");

    // // Take some damage
    // ct1.takeDamage(4);

    // // Repair
    // ct1.beRepaired(5);

    // ct1.takeDamage(11);

    // Additional actions can be added here

    // st1.attack("Enemy");

    // Take some damage
    // st1.takeDamage(4);

    // Repair
    // st1.beRepaired(5);

    // st1.takeDamage(1000);
    // st1.guardGate();


    ft1.attack("Enemy");

    // Take some damage
    ft1.takeDamage(4);

    // Repair
    ft1.beRepaired(5);

    ft1.highFivesGuys();

    ft1.takeDamage(1000);

    return 0;
}