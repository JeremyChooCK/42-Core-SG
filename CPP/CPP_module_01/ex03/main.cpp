#include <iostream>
#include <string>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

std::string    Weapon::getType() const{
    return (this->type);
}
void    Weapon::setType(std::string type){
    this->type = type;
}

void    HumanA::attack(void){
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}

void    HumanB::attack(void){
    std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}
HumanA::~HumanA(void) {}
HumanB::HumanB(std::string name) : name(name) {}
HumanB::~HumanB(void) {}
Weapon::Weapon(std::string type) :type(type) {}
Weapon::~Weapon(void) {}

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
