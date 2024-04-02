#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137){};
ShrubberyCreationForm::~ShrubberyCreationForm(){};
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), target(target){};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : AForm("Shrubbery Creation Form", 145, 137){
    this->target = form.target;
}
int ShrubberyCreationForm::abstract(){
    return 0;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
        this->target = other.target;
    return *this;
}

void ShrubberyCreationForm::action() const{
    //open a file and draw ascii art of trees
    std::ofstream outputFile((this->target + "_shrubbery").c_str());
    if (outputFile.is_open()) {
        outputFile << "   ^   " << "    ^   " << "    ^   " << std::endl;
        outputFile << "  ^^^  " << "   ^^^  " << "   ^^^  " << std::endl;
        outputFile << " ^^^^^ " << "  ^^^^^ " << "  ^^^^^ " << std::endl;
        outputFile << "^^^^^^^" << " ^^^^^^^" << " ^^^^^^^" << std::endl;
        outputFile << "   |   " << "    |   " << "    |   " << std::endl;
        outputFile.close();
    }
}