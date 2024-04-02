#ifndef FORM_HPP
#define FORM_HPP
#include <stdbool.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    public:
        Form(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
        ~Form();
        Form(const Form& other);
        class GradeTooHighException;
        class GradeTooLowException;
        int getGradeRequiredToSign();
        int getGradeRequiredToExecute();
        std::string getName();
        bool getIsSigned();
        void beSigned(Bureaucrat b);
    private:
        const std::string name;
        const int gradeRequiredToSign;
        const int gradeRequiredToExecute;
        bool isSigned;
};
class Form::GradeTooHighException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade too high";
    }
};

class Form::GradeTooLowException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade too low";
    }
};
std::ostream& operator<<(std::ostream& COUT, Form& form);
#endif