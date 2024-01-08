#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    // ClapTrap ct1("CT1");
    // ScavTrap st1("ST1");
    // FragTrap ft1("FT1");
    DiamondTrap dt1("DT1");

    // ct1.attack("Enemy");

    // ct1.takeDamage(4);

    // ct1.beRepaired(5);

    // ct1.takeDamage(11);


    // st1.attack("Enemy");

    // Take some damage
    // st1.takeDamage(4);

    // st1.beRepaired(5);

    // st1.takeDamage(1000);
    // st1.guardGate();


    // ft1.attack("Enemy");

    // ft1.takeDamage(4);

    // ft1.beRepaired(5);

    // ft1.highFivesGuys();

    // ft1.takeDamage(1000);

    dt1.attack("Enemy");

    dt1.takeDamage(4);

    dt1.beRepaired(5);

    dt1.highFivesGuys();

    dt1.guardGate();

    dt1.whoAmI();
    dt1.set_name("DT2");
    dt1.whoAmI();

    dt1.takeDamage(1000);

    return 0;
}