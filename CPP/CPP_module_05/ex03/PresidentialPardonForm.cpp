#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), target(target){};
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5){};
PresidentialPardonForm::~PresidentialPardonForm(){};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("Presidential Pardon Form", 25, 5){
    this->target = other.target;
};
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    if (this != &other)
        this->target = other.target;
    return *this;
}

int PresidentialPardonForm::abstract(){
    return 0;
}

void PresidentialPardonForm::action() const{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}