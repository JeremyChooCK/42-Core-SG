#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
class Intern{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm* makeForm(std::string formname, std::string target);
        class InvalidName;
};

class FormTypes{
    public:
        FormTypes(std::string name, std::string target);
        ~FormTypes();
        AForm **getTypes();
    private:
        std::string name;
        AForm* types[3];
};
class Intern::InvalidName : public std::exception{
    public:
        const char* what() const throw() {
            return "Grade too high";
        }
};
#endif