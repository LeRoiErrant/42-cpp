

#include "RPN.hpp"

const std::string RPN::_operand = "+-/*";

RPN::RPN( std::string exp ) : _exp(exp) {
    std::stringstream parse(_exp);

    std::string token;

    while (std::getline(parse, token, ' ')) {
        if (token.size() == 1 && isdigit(token[0])) {
            _solver.push(std::stoi(token));
        } else if ( _operand.find(token) != std::string::npos) {
            handleOperand((token[0]));
        } else {
            throw RPN::InvalidExpressionException();
        }
    }
    if (_solver.size() != 1) {
        throw RPN::InvalidExpressionException();
    }
}

RPN::~RPN( void ) {

}

void    RPN::handleOperand(char operand) {
    int n1 = _solver.top();
    _solver.pop();
    int n2 = _solver.top();
    _solver.pop();
    switch (operand) {
        case '+':
            _solver.push(n2 + n1);
            break;
        case '-':
            _solver.push(n2 - n1);
            break;
        case '*':
            _solver.push(n2 * n1);
            break;
        case '/':
            _solver.push(n2 / n1);
            break;
    }
}

const char* RPN::InvalidExpressionException::what() const throw()
{
    return "ERROR: Invalid Expression";
}

