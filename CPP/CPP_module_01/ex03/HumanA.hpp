#ifndef HUMANA_HPP
#define HUMANA_HPP

class Weapon{
    public:
        std::string  getType() const;
        void    setType(std::string type);
        Weapon(std::string type);
        ~Weapon(void);
    private:
        std::string type;
};

class HumanA{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    attack(void);
    private:
        std::string name;
        Weapon &weapon;
};
class HumanB{
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void    attack(void);
        void    setWeapon(Weapon &weapon);
    private:
        std::string name;
        Weapon *weapon;
};
#endif