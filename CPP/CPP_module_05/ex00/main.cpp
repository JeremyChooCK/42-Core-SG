#include "Bureaucrat.hpp"

int main(){
    //test low
    std::cout << "Test for grade set too low : ";
    try{
        Bureaucrat josh("josh", 1);
        Bureaucrat jane("jane", 150);
        Bureaucrat jack("jack", 0);
        Bureaucrat john("john", 151);
    }
    catch (const std::exception &e){
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    catch (...){
        std::cout << "Error occured" << std::endl;
    }
    //test high
    std::cout << "Test for grade set too high : ";
    try{
        Bureaucrat josh("josh", 1);
        Bureaucrat jane("jane", 150);
        Bureaucrat john("john", 151);
    }
    catch (const std::exception &e){
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    catch (...){
        std::cout << "Error occured" << std::endl;
    }
    //test decrementing
    std::cout << std::endl << "Test for decrementing : " << std::endl;
    try{
        Bureaucrat josh("josh", 150);
        std::cout << "Before decrementing :" << std::endl;
        std::cout << josh;
        std::cout << "After decrementing:" << std::endl;
        josh.decrementGrade(100);
        std::cout << josh;
    }
    catch (const std::exception &e){
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    catch (...){
        std::cout << "Error occured" << std::endl;
    }
    //test increment
        std::cout << std::endl << "Test for decrement : " << std::endl;
    try{
        Bureaucrat joe("joe", 1);
        std::cout << "Before incrementing :" << std::endl;
        std::cout << joe;
        joe.incrementGrade(100);
        std::cout << joe;
        std::cout << "After incrementing:" << std::endl;
        std::cout << joe;
    }
    catch (const std::exception &e){
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    catch (...){
        std::cout << "Error occured" << std::endl;
    }
}