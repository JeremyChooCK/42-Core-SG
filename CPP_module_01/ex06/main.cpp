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
    int i = 0;
    level == "DEBUG" ? i = 1 : level == "INFO" ? i = 2 : level == "WARNING" ? i = 3 : level == "ERROR" ? i = 4 : i = 0;

    switch (i)
    {
        case 1:
            debug();
            break;
        case 2:
            info();
            break;
        case 3:
            warning();
            break;
        case 4:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}


int main(int ac, char **av)
{
    if (ac == 2)
    {
        Harl harl;
        harl.complain(std::string(av[1]));
    }
    return 0;
}