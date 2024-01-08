#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name){
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " is created." << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << this->name << " is deleted." << std::endl;
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap " << this->name << " is " << this->name << " and " << ClapTrap::name << "." << std::endl;
}

void DiamondTrap::set_name(std::string name){
    this->name = name;
}