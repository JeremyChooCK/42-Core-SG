#include "main.hpp"

void ScalarConverter::convert(const std::string& literal) {
    // Convert to char
	if (literal.length() == 1 && isdigit(literal[0])) {
		int li = literal[0] - '0';
		if (li >= 0 && li <= 31) {
			std::cout << "char: Non displayable" << std::endl;
		} else {
			std::cout << "char: '" << static_cast<char>(li) << "'" << std::endl;
		}
    } else {
        char* end;
        long int li = std::strtol(literal.c_str(), &end, 10);
        if (end != literal.c_str() && *end == '\0' && li >= std::numeric_limits<char>::min() && li <= std::numeric_limits<char>::max()) {
            if (li < 32 || li == 127) {
                std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: '" << static_cast<char>(li) << "'" << std::endl;
            }
        } else {
            std::cout << "char: impossible" << std::endl;
        }
    }

    // Convert to int
    char* end;
    errno = 0; // To detect overflow
    long int li = std::strtol(literal.c_str(), &end, 10);
    if (errno == 0 && li >= INT_MIN && li <= INT_MAX && literal != "nan") {
        std::cout << "int: " << static_cast<int>(li) << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }

    // Convert to float
    std::string floatLiteral = literal;
	float f = std::strtof(floatLiteral.c_str(), &end);
	errno = 0; // Reset errno

    if ((end != literal.c_str() && (*end == '\0' || *end == 'f')) || literal == "nan" || literal == "+inf" || literal == "-inf") {
        // Check if the number is a whole number
        if (f == static_cast<float>(static_cast<int>(f))) {
            // It's a whole number, set precision to 1 to ensure .0 is printed
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        } else {
            // It's not a whole number, print as is
            std::cout << "float: " << f << "f" << std::endl;
        }
    } else {
        std::cout << "float: impossible" << std::endl;
    }
    // Convert to double
    errno = 0; // Reset errno
    double d = std::strtod(literal.c_str(), &end);
    if ((end != literal.c_str() && (*end == '\0' || *end == 'f')) || literal == "nan" || literal == "+inf" || literal == "-inf") {
        std::cout << "double: " << d << std::endl;
    } else {
        std::cout << "double: impossible" << std::endl;
    }
}


int main(int ac, char **av) {
	if (ac == 2){
		ScalarConverter::convert(av[1]);
	}
    return 0;
}
