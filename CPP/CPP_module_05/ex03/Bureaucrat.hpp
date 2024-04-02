#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void incrementGrade(int amount);
        void decrementGrade(int amount);
        class GradeTooHighException;
        class GradeTooLowException;
        void signForm(AForm* form);
        void executeForm(AForm const & form);
};
class Bureaucrat::GradeTooHighException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade too high";
    }
};

class Bureaucrat::GradeTooLowException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade too low";
    }
};
std::ostream& operator<<(std::ostream& COUT, Bureaucrat& b);
#endif