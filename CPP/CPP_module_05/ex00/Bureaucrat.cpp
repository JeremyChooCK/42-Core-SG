#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) :name(name){
    if (grade < 1)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooHighException();
    this->grade = grade;
}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {};
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) { // Self-assignment check
        this->name = other.name;
        this->grade = other.grade;
    }
    return *this; // Return a reference to this object
}
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