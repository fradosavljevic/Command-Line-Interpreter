#ifndef CLI_TOKEN_H
#define CLI_TOKEN_H
#include <string>

enum class TokenType {
    NIL =              0,
    COMMAND =          1 << 1,
    OPTION =           1 << 2,
    ARGUMENT =         1 << 3,
    REDIRECT_INPUT =   1 << 4,
    REDIRECT_OUTPUT =  1 << 5,
    FILENAME =         1 << 6,
    PIPE_SEPARATOR =   1 << 7,
    END_OF_FILE =      1 << 8,
    FILE_OR_ARGUMENT = (FILENAME | ARGUMENT),
    OPTION_OR_ARGUMENT = (OPTION | ARGUMENT),
};

// Token je klasa koja sluzi za lakse prepoznavanje logickih celina u stringu koji prosledi korisnik.
// U sebi sadrzi tip tokena kao i sadrzaj koji mu se dodeljuje u Lexeru.
class Token {
public:
    Token();
    Token(TokenType type, const std::string &value);
    [[nodiscard]] std::string getValue() const;
    [[nodiscard]] TokenType getType() const;
private:
    TokenType type;
    std::string value;
};


#endif //CLI_TOKEN_H