#ifndef MAIN_HPP
# define MAIN_HPP
#include <iostream>
#include <string>
class Animal{
    public:
        Animal();
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;
    protected:
        std::string type;
};
class Dog : public Animal{
    public:
        Dog();
        virtual ~Dog();
        virtual void makeSound() const;
};
class Cat : public Animal{
    public:
        Cat();
        virtual ~Cat();
        virtual void makeSound() const;
};
class WrongAnimal{
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        void makeSound() const;
        std::string getType() const;
    protected:
        std::string type;
};
class WrongCat : public WrongAnimal{
    public:
        WrongCat();
        virtual ~WrongCat();
};

#endif