#ifndef CLI_LEXER_H
#define CLI_LEXER_H
#include "Lexer.h"
#include "Token.h"
#include <vector>
#include <string>

// Lexer ima ulogu da razbije tekst koji dobije na niz smislenih tokena
// koji se koriste za dalju analizu.
class Lexer {
public:
    Lexer();

    // Glavna funkcija Lexera kojom se zapocinje proces formiranja tokena
    static std::vector<Token> process(const std::string& line);

private:
    // Razbija tekst na delove i pritom pazi na navodnike
    static std::vector<std::string> split(const std::string& line);

    // Na oznovu rezultat iz funkcije split formira tokene i smesta ih u vektor
    static std::vector<Token> tokenize(const std::vector<std::string>& line);
};


#endif //CLI_LEXER_H