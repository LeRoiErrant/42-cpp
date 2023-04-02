#include "RPN.hpp"

int main(int argc, char **argv) {
    (void) argc;
    std::string exp(argv[1]);
    try {
        RPN solver(exp);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
}
