#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " is created." << std::endl;
};

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << this->name << " is deleted." << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (this->hitPoints < 1){
        std::cout << "ScavTrap " << this->name << " is dead and cannot attack." << std::endl;
        return ;
    }
    if (this->energyPoints < 1){
        std::cout << "ScavTrap " << this->name << " does not have enough energy to attack." << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}