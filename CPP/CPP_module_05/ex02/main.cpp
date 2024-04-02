#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    try{
        std::cout << "test with signing form..." << std::endl;
        ShrubberyCreationForm tree("cool");
        std::cout << tree.getName() << " " << tree.getGradeRequiredToSign() << " " << tree.getGradeRequiredToExecute() << std::endl;
        RobotomyRequestForm robo1("robo1");
        RobotomyRequestForm robo2("robo2");
        RobotomyRequestForm robo3("robo3");
        RobotomyRequestForm robo4("robo4");
        PresidentialPardonForm pres("pres");

        Bureaucrat joe("joe", 1);
        Bureaucrat jane("jane", 150);

        joe.signForm(&tree);
        joe.executeForm(tree);
        std::cout << std::endl;
        joe.signForm(&robo1);
        joe.executeForm(robo1);
        std::cout << std::endl;
        joe.signForm(&robo2);
        joe.executeForm(robo2);
        std::cout << std::endl;
        joe.signForm(&robo3);
        joe.executeForm(robo3);
        std::cout << std::endl;
        joe.signForm(&robo4);
        joe.executeForm(robo4);
        std::cout << std::endl;
        joe.signForm(&pres);
        joe.executeForm(pres);
    }
    catch (const std::exception &e){
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    //form is not signed
    try{
        std::cout << std::endl << "test without signing form..." << std::endl;
        ShrubberyCreationForm tree("cool");
        std::cout << tree.getName() << " " << tree.getGradeRequiredToSign() << " " << tree.getGradeRequiredToExecute() << std::endl;
        RobotomyRequestForm robo1("robo1");
        RobotomyRequestForm robo2("robo2");
        RobotomyRequestForm robo3("robo3");
        RobotomyRequestForm robo4("robo4");

        Bureaucrat joe("joe", 1);
        Bureaucrat jane("jane", 150);

        joe.executeForm(tree);
    }
    catch (const std::exception &e){
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    //grade too low
    try{
        std::cout << std::endl << "test grade too low to sign..." << std::endl;
        ShrubberyCreationForm tree("cool");
        std::cout << tree.getName() << " " << tree.getGradeRequiredToSign() << " " << tree.getGradeRequiredToExecute() << std::endl;
        RobotomyRequestForm robo1("robo1");
        RobotomyRequestForm robo2("robo2");
        RobotomyRequestForm robo3("robo3");
        RobotomyRequestForm robo4("robo4");

        Bureaucrat joe("joe", 1);
        Bureaucrat jane("jane", 150);

        jane.signForm(&tree);
    }
    catch (const std::exception &e){
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}