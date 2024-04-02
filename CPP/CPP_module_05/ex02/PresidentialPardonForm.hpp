#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
class PresidentialPardonForm : public AForm{
    private:
        std::string target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        void action() const;
        virtual int abstract();
};
#endif