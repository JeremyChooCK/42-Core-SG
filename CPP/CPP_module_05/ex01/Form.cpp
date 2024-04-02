#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) : name(name), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute), isSigned(false){
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw GradeTooLowException();
    else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
        throw GradeTooHighException();
};
Form::~Form(){};
Form::Form(const Form& other)
    : name(other.name), gradeRequiredToSign(other.gradeRequiredToSign),
      gradeRequiredToExecute(other.gradeRequiredToExecute), isSigned(other.isSigned) {
    // All work done in initializer list
}


int Form::getGradeRequiredToExecute(){
    return this->gradeRequiredToExecute;
}

int Form::getGradeRequiredToSign(){
    return this->gradeRequiredToSign;
}

std::string Form::getName(){
    return this->name;
}


bool Form::getIsSigned(){
    return this->isSigned;
}

std::ostream& operator<<(std::ostream& COUT, Form& form){
    COUT << "name : " << form.getName() << std::endl;
    COUT << "signed : " << form.getIsSigned() << std::endl;
    COUT << "grade required to sign : " << form.getGradeRequiredToSign() << std::endl;
    COUT << "grade required to execute : " << form.getGradeRequiredToExecute() << std::endl;
    return COUT;
}

void Form::beSigned(Bureaucrat b){
    // if bureacrat grade is lower than the grade to be signed
    if (b.getGrade() < this->getGradeRequiredToSign())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}