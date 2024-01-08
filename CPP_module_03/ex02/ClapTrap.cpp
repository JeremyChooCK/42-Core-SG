#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name){
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap " << this->name << " is created." << std::endl;
};

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << this->name << " is deleted." << std::endl;
}

void ClapTrap::attack(const std::string &target){
    if (this->hitPoints < 1){
        std::cout << "ClapTrap " << this->name << " is dead and cannot attack." << std::endl;
        return ;
    }
    if (this->energyPoints < 1){
        std::cout << "ClapTrap " << this->name << " does not have enough energy to attack." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->hitPoints < 1){
        std::cout << "ClapTrap " << this->name << " is already dead." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    this->hitPoints -= amount;
    if (this->hitPoints < 1){
        std::cout << "ClapTrap " << this->name << " has died." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->hitPoints < 1){
        std::cout << "ClapTrap " << this->name << " is dead and cannot be repaired." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points of health!" << std::endl;
    this->hitPoints += amount;
}
