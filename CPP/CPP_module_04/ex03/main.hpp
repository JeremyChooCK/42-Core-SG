#ifndef MAIN_HPP
# define MAIN_HPP
# include <iostream>
# include <string>
class AMateria;
class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const & type);
        virtual ~AMateria();
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};
class Ice : public AMateria
{
    public:
        Ice();
        virtual ~Ice();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};
class Cure : public AMateria
{
    public:
        Cure();
        virtual ~Cure();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};
class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
    public:
        Character(std::string const & name);
        Character(Character const & src);
        virtual ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};
class IMateriaSource
{
    public:
        virtual ~IMateriaSource();
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* inventory[4];
    public:
        MateriaSource();
        virtual ~MateriaSource();
        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);
};
#endif