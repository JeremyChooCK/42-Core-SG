#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}