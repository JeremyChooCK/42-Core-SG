#include "main.hpp"

int main()
{
const Animal* d1 = new Dog();
const Animal* c1 = new Cat();
delete c1;
delete d1;//should not create a leak

std::cout << std::endl;
std::cout << "Create Animal array========================================================================" << std::endl;
std::cout << std::endl;

Animal* j[10];
for (int i = 0; i < 5; i++)
{
    j[i] = new Dog();
    std::cout << std::endl;
    j[i + 5] = new Cat();
    std::cout << std::endl;
}

std::cout << "Delete Animal array========================================================================" << std::endl;
std::cout << std::endl;

for (int i = 0; i < 10; i++)
{
    delete j[i];//should not create a leak
    std::cout << std::endl;
}
Dog basic;
basic.setIdea(0, "I am a dog");
Dog tmp = basic;

std::cout << basic.getIdea(0) << std::endl;
std::cout << tmp.getIdea(0) << std::endl;

basic.setIdea(0, "I am a cool dog");

std::cout << basic.getIdea(0) << std::endl;
std::cout << tmp.getIdea(0) << std::endl;

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
    this->brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = dog.type;
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, dog.brain->getIdea(i));
}

void Dog::setIdea(int i, std::string idea)
{
    this->brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const
{
    return this->brain->getIdea(i);
}

Dog::~Dog(){
    delete this->brain;
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
    this->brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = cat.type;
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, cat.brain->getIdea(i));
}

void Cat::setIdea(int i, std::string idea)
{
    this->brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const
{
    return this->brain->getIdea(i);
}

Cat::~Cat()
{
    delete this->brain;
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

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, std::string idea)
{
    this->ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
    return this->ideas[i];
}