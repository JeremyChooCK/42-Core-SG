#include <iostream>
#include <string>
#include "Harl.hpp"

class Harl{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        typedef void (Harl::*f)(void);
    public:
        void complain( std::string level );
};

void Harl::debug( void )
{
    std::cout << "[DEBUG] This is a debug message" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[INFO] This is an info message" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[WARNING] This is a warning message" << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ERROR] This is an error message" << std::endl;
}

void Harl::complain( std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    f functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level){
            (this->*functions[i])();
            return ;
        }
    }
    std::cout << "Invalid Complaint" << std::endl;
}


int main()
{
    Harl harl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("invalid");
    return 0;
}