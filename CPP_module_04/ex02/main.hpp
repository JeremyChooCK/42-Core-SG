#ifndef MAIN_HPP
# define MAIN_HPP
#include <iostream>
#include <string>
class Brain{
    public:
        Brain();
        ~Brain();
        std::string getIdea(int i) const;
        void setIdea(int i, std::string idea);
    private:
        std::string ideas[100];
};
class Animal{
    public:
        Animal();
        virtual ~Animal();
        virtual void makeSound() const = 0;
        std::string getType() const;
    protected:
        std::string type;
};
class Dog : public Animal{
    public:
        Dog();
        Dog(const Dog &dog);
        virtual ~Dog();
        virtual void makeSound() const;
        void setIdea(int i, std::string idea);
        std::string getIdea(int i) const;
    private:
        Brain *brain;
};
class Cat : public Animal{
    public:
        Cat();
        Cat(const Cat &cat);
        virtual ~Cat();
        virtual void makeSound() const;
        void setIdea(int i, std::string idea);
        std::string getIdea(int i) const;
    private:
        Brain *brain;
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