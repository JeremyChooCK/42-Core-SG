#ifndef Zombie_HPP
#define Zombie_HPP

#include <iostream>
#include <string>

class Zombie {
public:
    static Zombie* newZombie(std::string name);
    static void randomChump(std::string name);
    Zombie(std::string name);
    ~Zombie();
    void announce();

private:
    std::string name;
};

#endif
