#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) : name(name), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute), isSigned(false){
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw GradeTooLowException();
    else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
        throw GradeTooHighException();
};
AForm::~AForm(){};

int AForm::getGradeRequiredToExecute(){
    return this->gradeRequiredToExecute;
}

int AForm::getGradeRequiredToSign(){
    return this->gradeRequiredToSign;
}

std::string AForm::getName(){
    return this->name;
}

bool AForm::getIsSigned(){
    return this->isSigned;
}

std::ostream& operator<<(std::ostream& COUT, AForm& form){
    COUT << "name : " << form.getName() << std::endl;
    COUT << "signed : " << form.getIsSigned() << std::endl;
    COUT << "grade required to sign : " << form.getGradeRequiredToSign() << std::endl;
    COUT << "grade required to execute : " << form.getGradeRequiredToExecute() << std::endl;
    return COUT;
}

void AForm::beSigned(Bureaucrat b){
    // if bureacrat grade is lower than the grade to be signed
    if (b.getGrade() < this->getGradeRequiredToSign())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

void AForm::action() const{}

void AForm::execute(Bureaucrat const & executor) const{
    //check if form is signed
    if (this->isSigned == false)
        throw NotSignedException();
    else if (executor.getGrade() > this->gradeRequiredToExecute)
        throw GradeTooLowException();
    std::cout << executor.getName() << " executed " << const_cast<AForm*>(this)->getName() << std::endl;
    this->action();
}