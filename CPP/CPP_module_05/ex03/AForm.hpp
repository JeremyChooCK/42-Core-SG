#ifndef AFORM_HPP
#define AFORM_HPP
#include <stdbool.h>
#include <string>
#include <iostream>
#include <fstream>

class Bureaucrat;

class AForm{
    public:
        AForm(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
        virtual ~AForm();
        virtual int abstract() = 0;
        class GradeTooHighException;
        class GradeTooLowException;
        class NotSignedException;
        virtual int getGradeRequiredToSign();
        virtual int getGradeRequiredToExecute();
        virtual std::string getName();
        virtual bool getIsSigned();
        virtual void beSigned(Bureaucrat b);
        virtual void execute(Bureaucrat const & executor) const;
        virtual void action() const;
    private:
        const std::string name;
        const int gradeRequiredToSign;
        const int gradeRequiredToExecute;
        bool isSigned;
        std::string target;
};
class AForm::GradeTooHighException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade too high";
    }
};

class AForm::GradeTooLowException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade too low";
    }
};
class AForm::NotSignedException : public std::exception {
public:
    const char* what() const throw() {
        return "Form not signed, cannot execute";
    }
};
std::ostream& operator<<(std::ostream& COUT, AForm& form);
#endif