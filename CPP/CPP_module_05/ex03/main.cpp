#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
    try{
        Bureaucrat joe("joe", 1);
        Bureaucrat jane("jane", 150);

        Intern intern;

        AForm *shrubform = intern.makeForm("shrubbery creation", "yoyo");
        std::cout << *shrubform;
        // shrubform->action();
        AForm *roboform = intern.makeForm("robotomy request", "yoyo");
        std::cout << *roboform;
        AForm *presform = intern.makeForm("presidential pardon", "yoyo");
        std::cout << *presform;
    }
    catch (const std::exception &e){
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}