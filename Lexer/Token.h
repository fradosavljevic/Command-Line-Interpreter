#ifndef CLI_TOKEN_H
#define CLI_TOKEN_H
#include <string>

enum class TokenType {
    COMMAND,
    OPTION,
    ARGUMENT,
    REDIRECT_INPUT,
    NIL,
    FILENAME,
    PIPE_SEPARATOR,
    END_OF_FILE
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