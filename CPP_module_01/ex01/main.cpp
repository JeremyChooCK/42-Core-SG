#include "Zombie.hpp"

int main() {
    int hordeSize = 5;
    std::string zombieName = "yoyo the bear";

    Zombie* horde = Zombie::zombieHorde(hordeSize, zombieName);

    for (int i = 0; i < hordeSize; ++i) {
        horde[i].announce();
    }

    delete[] horde; // Delete the array of pointers

    return 0;
}
