#include "Zombie.hpp"

// Zombie* Zombie::newZombie(std::string name) {
//     return new Zombie(name);
// }

// void Zombie::randomChump(std::string name) {
//     Zombie zombie(name);
//     zombie.announce();
// }

Zombie::Zombie(std::string name) : name(name) {
    // Constructor body
}

Zombie::~Zombie() {
    // Destructor body
}

void Zombie::announce() {
    std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}