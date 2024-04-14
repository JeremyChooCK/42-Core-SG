#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib> // For atoi function

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    std::string input(argv[1]);
    std::istringstream iss(input);
    std::stack<int> evalStack;
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) { // Check if the token is a number
            evalStack.push(atoi(token.c_str()));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (evalStack.size() < 2) {
                std::cerr << "Error: insufficient values in the expression" << std::endl;
                return 1;
            }
            int val2 = evalStack.top();
            evalStack.pop();
            int val1 = evalStack.top();
            evalStack.pop();

            switch (token[0]) {
                case '+':
                    evalStack.push(val1 + val2);
                    break;
                case '-':
                    evalStack.push(val1 - val2);
                    break;
                case '*':
                    evalStack.push(val1 * val2);
                    break;
                case '/':
                    if (val2 == 0) {
                        std::cerr << "Error: division by zero" << std::endl;
                        return 1;
                    }
                    evalStack.push(val1 / val2);
                    break;
                default:
                    std::cerr << "Error: invalid operation" << std::endl;
                    return 1;
            }
        } else {
            std::cerr << "Error: invalid token '" << token << "'" << std::endl;
            return 1;
        }
    }

    if (evalStack.size() != 1) {
        std::cerr << "Error: the input RPN expression does not resolve to a single result" << std::endl;
        return 1;
    }

    std::cout << evalStack.top() << std::endl;
    return 0;
}
