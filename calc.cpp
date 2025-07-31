#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include "Stack.h"

//check to see if the op given is a valid operator 
bool isOperator(const std::string& op) {
    return op == "+" || op == "-" || op == "*" ||
           op == "/" || op == "%" || op == "^" ||
           op == "~";
}

//check to see if a number 

bool isNumber(const std::string& op, double& value) {
    char* end;
    value = std::strtod(op.c_str(), &end);
    return *end == '\0';
}



int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            std::cout << "No expression." << std::endl;
            continue;
        }

Stack* stack = Stack::create();
        std::stringstream ss(line);
        std::string op;
        bool error = false;

        while (ss >> op) {
            double num;
            if (isOperator(op)) {
                try {
                    if (op == "~") {
                        double a = stack->pop();
                        stack->push(-a);
                    } else {
                        double b = stack->pop();
                        double a = stack->pop();

                        if ((op == "/" || op == "%") && b == 0) {
                            std::cout << "Division by zero." << std::endl;
                            error = true;
                            break;
                        }

                        double result = 0;
                        //OPERATION 
                        if (op == "+") result = a + b;
                        else if (op == "-") result = a - b;
                        else if (op == "*") result = a * b;
                        else if (op == "/") result = a / b;
                        else if (op == "%") result = std::fmod(a, b);
                        else if (op == "^") result = std::pow(a, b);

                        stack->push(result);
                    }
                } catch (std::underflow_error&) {
                    std::cout << "Not enough operands." << std::endl;
                    error = true;
                    break;
                }
            } else if (isNumber(op, num)) {
                stack->push(num);
            } else {
                std::cout << "Unknown token." << std::endl;
                error = true;
                break;
            }
        }

        if (!error) {
            if (stack->is_empty()) {
                std::cout << "No expression." << std::endl;
            } else {
                try {
                    double result = stack->pop();
                    if (!stack->is_empty()) {
                        std::cout << "Too many operands." << std::endl;
                    } else {
                        std::cout << "= " << result << std::endl;
                    }
                } catch (std::underflow_error&) {
                    std::cout << "No expression." << std::endl;
                }
            }
        }

        delete stack;
    }

    return 0;
}
