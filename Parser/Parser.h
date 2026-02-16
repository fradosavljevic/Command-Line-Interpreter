#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include "../Lexer/Token.h"
#include "../Commands/Command.h"
#include <memory>
#include <vector>

// Parser je klasa koja na osnovu tokena dobijenih od Lexera proverava
// da li komanda postoji i da li je ispravan broj argumenata.
// Sve vaznije informacije o komandama Parser dobija od klase CommandDB.
class Parser {
public:
    Parser();

    // Na osnovu tokena dobijenih od Lexera vrsi proveru ispravnosti i kao rezultat vraca kreiranu komandu ako ona postoji.
    static std::unique_ptr<Command> parse(const std::vector<Token>& tokens);
};


#endif //CLI_PARSER_H