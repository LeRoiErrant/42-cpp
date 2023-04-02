

#ifndef INC_42_RPN_HPP
# define INC_42_RPN_HPP
# include <stack>
# include <sstream>
# include <cctype>
# include <iostream>
# include <string>

class RPN {
private:
    const static std::string _operand;
    std::string _exp;
    std::stack<int> _solver;


    RPN( void );
    RPN( RPN & src );
    RPN &operator=( RPN & src );

    void    handleOperand( char operand );

public:
    RPN( std::string exp );
    ~RPN();

    class InvalidExpressionException: public std::exception {
        virtual const char* what() const throw();
    };
};
#endif //INC_42_RPN_HPP
