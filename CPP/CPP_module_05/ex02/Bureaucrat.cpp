#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) :name(name){
    if (grade < 1)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooHighException();
    this->grade = grade;
}
Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

void Bureaucrat::incrementGrade(int amount){
    amount = 1;
    if (this->grade - amount < 1)
        throw GradeTooHighException();
    this->grade -= amount;
}

void Bureaucrat::decrementGrade(int amount){
    amount = 1;
    if (this->grade + amount > 150)
        throw GradeTooLowException();
    this->grade += amount;
}

std::ostream& operator<<(std::ostream& COUT, Bureaucrat& b){
    COUT << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return COUT;
}

void Bureaucrat::signForm(AForm* form){
    form->beSigned(*this);
    if (form->getIsSigned() == false)
        std::cout << this->getName() << " couldn't sign " << form->getName() << " because grade is too low" << std::endl;
    else
        std::cout << this->getName() << " signed " << form->getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const & form){
    form.execute(*this);
}