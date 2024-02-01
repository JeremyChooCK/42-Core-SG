#include "main.hpp"

int main() {
    // Testing MateriaSource
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Testing Ice and Cure as AMateria derivatives
    Ice* ice = new Ice();
    Cure* cure = new Cure();

    std::cout << "Ice type: " << ice->getType() << std::endl;
    std::cout << "Cure type: " << cure->getType() << std::endl;

    // Testing clone() method
    AMateria* clonedIce = ice->clone();
    AMateria* clonedCure = cure->clone();
    std::cout << "Cloned Ice type: " << clonedIce->getType() << std::endl;
    std::cout << "Cloned Cure type: " << clonedCure->getType() << std::endl;

    // Testing AMateria is still abstract
    // Uncommenting the following line should result in a compilation error
    // AMateria* abstractMateria = new AMateria("abstract");

    // Testing Character implementation
    Character* me = new Character("me");
    me->equip(ice);
    me->equip(cure);

    // Testing deep copy
    Character* copyOfMe = new Character(*me);
    std::cout << "Original: " << me->getName() << ", Copy: " << copyOfMe->getName() << std::endl;

    // Testing use() function
    Character* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    // Clean up
    delete src;
    delete clonedIce;
    delete clonedCure;
    delete me;
    delete copyOfMe;
    delete bob;

    return 0;
}


AMateria::AMateria(std::string const & type) : type(type) {}
AMateria::~AMateria() {}
std::string const & AMateria::getType() const { return type; }
void AMateria::use(ICharacter& target) {
    std::cout << "use " << type << " on " << target.getName() << std::endl;
}

Ice::Ice() : AMateria("ice") {}
Ice::~Ice() {}
AMateria* Ice::clone() const { return new Ice(*this); }
void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

Cure::Cure() : AMateria("cure") {}
Cure::~Cure() {}
AMateria* Cure::clone() const { return new Cure(*this); }
void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& src) : name(src.name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = src.inventory[i] ? src.inventory[i]->clone() : NULL;
    }
}

Character::~Character(){
    for (int i = 0; i < 4; i++)
        if (inventory[i] != NULL)
            delete inventory[i];
}
void Character::equip(AMateria* m){
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL){
            inventory[i] = m;
            return;
        }
    }
}
void Character::unequip(int idx){
    if (inventory[idx] != NULL)
        inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter& target){
    if (inventory[idx] != NULL)
        inventory[idx]->use(target);
}
std::string const & Character::getName() const { return name; }

IMateriaSource::~IMateriaSource() {}
void IMateriaSource::learnMateria(AMateria*) {}
AMateria* IMateriaSource::createMateria(std::string const & type) {
    if (type == "ice")
        return new Ice();
    else if (type == "cure")
        return new Cure();
    else
        return NULL;
}

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL) {
            delete inventory[i];
        }
    }
}
void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
    delete m; // If inventory is full, delete the materia to prevent memory leak
}

AMateria* MateriaSource::createMateria(std::string const & type){
    if (type == "ice")
        return new Ice();
    else if (type == "cure")
        return new Cure();
    else
        return NULL;
}
