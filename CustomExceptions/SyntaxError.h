#ifndef CLI_SYNTAXERROR_H
#define CLI_SYNTAXERROR_H
#include <stdexcept>
#include <vector>
#include "../Lexer/Token.h"

// Ispisuje specijalnu poruku koja pomaze korisniku da vidi gde je napravio gresku.
class SyntaxError : public std::runtime_error {
public:
    explicit SyntaxError(const std::vector<std::string>& invalidValues) : std::runtime_error(processError(invalidValues)) {}
private:
    static std::string processError(const std::vector<std::string>& invalidValues);
};


#endif //CLI_SYNTAXERROR_H