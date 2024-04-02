#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){};
Intern::~Intern(){};

FormTypes::FormTypes(std::string name, std::string target) : name(name){
    this->types[0] = new ShrubberyCreationForm(target);
    this->types[1] = new RobotomyRequestForm(target);
    this->types[2] = new PresidentialPardonForm(target);
}
FormTypes::~FormTypes(){};

AForm **FormTypes::getTypes(){
    return this->types;
}

AForm* Intern::makeForm(std::string name, std::string target){
    FormTypes formtypes(name, target);
    AForm* result = NULL;
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++){
        if (name == names[i])
            result = formtypes.getTypes()[i];
        else
            delete formtypes.getTypes()[i];
    }
    if (result == NULL)
        throw InvalidName();
    std::cout << "Intern creates " << name << " form" << std::endl;
    return result;
}