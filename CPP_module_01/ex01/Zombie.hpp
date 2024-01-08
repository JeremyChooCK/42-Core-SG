#ifndef Zombie_HPP
#define Zombie_HPP

#include <iostream>
#include <string>

class Zombie {
public:
    static Zombie* zombieHorde( int N, std::string name );
    Zombie();
    ~Zombie();
    void announce();

private:
    std::string name;
};

#endif
