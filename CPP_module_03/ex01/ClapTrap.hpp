#ifndef CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap{
    protected:
        std::string name;
        std::string type;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        virtual void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap(std::string name);
        ~ClapTrap();
};

#endif