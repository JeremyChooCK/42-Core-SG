#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
class RobotomyRequestForm : public AForm{
    private:
        std::string target;
    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& form);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        void action() const;
        virtual int abstract();
};
#endif