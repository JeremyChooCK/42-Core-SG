#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " is created." << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << this->name << " is deleted." << std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << this->name << " requests a high five." << std::endl;
}