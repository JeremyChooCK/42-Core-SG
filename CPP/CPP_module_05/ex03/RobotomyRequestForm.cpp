#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime> 
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), target(target){};
RobotomyRequestForm::~RobotomyRequestForm(){};
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45){};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form): AForm("Robotomy Request Form", 72, 45){
        this->target = form.target;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    this->target = other.target;
    return *this;
}
int RobotomyRequestForm::abstract(){
    return 0;
}

void RobotomyRequestForm::action() const{
    std::cout << "drilling noise..." << std::endl;
    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized" << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;
}