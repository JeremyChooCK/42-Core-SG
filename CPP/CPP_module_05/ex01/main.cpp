#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    try{
        std::cout << std::endl << "test for forms" << std::endl;
        Bureaucrat joe("joe", 150);
        Bureaucrat kate("kate", 1);
        std::cout << joe;
        std::cout << kate;
        Form g75("g75", 75, 75);
        std::cout << g75;
        kate.signForm(&g75);
        std::cout << g75;
        Form g752("g75", 75, 75);
        joe.signForm(&g752);
        std::cout << g752;
    }
    catch (const std::exception &e){
        std::cerr << "Caught an exception: " << e.what() << " to sign" << std::endl;
    }

}