#include "main.hpp"

int main()
{

std::cout << "\nDefault Animal tests\n" << std::endl;

const Animal* meta = new Animal();
const Animal* i = new Cat();
const Animal* j = new Dog();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete j;
delete i;
delete meta;

std::cout << "\nWrong Animal tests\n" << std::endl;

const WrongAnimal* meta1 = new WrongAnimal();
const WrongAnimal* i1 = new WrongCat();
const Animal* j1 = new Dog();
std::cout << j1->getType() << " " << std::endl;
std::cout << i1->getType() << " " << std::endl;
i1->makeSound(); //will output the cat sound!
j1->makeSound();
meta1->makeSound();

delete j1;
delete i1;
delete meta1;

return 0;
}

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound" << std::endl;
}

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;

}

void Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal sound" << std::endl;
}

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}