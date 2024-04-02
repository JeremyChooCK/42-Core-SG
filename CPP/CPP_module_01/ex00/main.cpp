#include "Zombie.hpp"

int main() {
    Zombie* zombie1 = Zombie::newZombie("Zombie1");
    zombie1->announce();
    delete zombie1;

    Zombie::randomChump("Zombie2");

    return 0;
}
