#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {}

void Zombie::announce() {
    std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::zombieHorde(int N, std::string name) {
    Zombie* zombies;

    zombies = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        zombies[i] = Zombie();
        zombies[i].name = name; 
    }
    return zombies;
}