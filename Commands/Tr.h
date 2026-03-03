#ifndef CLI_TR_H
#define CLI_TR_H
#include "TextCommand.h"

// Vrsi zamenu ili brisanje delove teksta u zavisnosti od toga sta korisnik prosledi.
class Tr : public TextCommand {
public:
    Tr(const Token& textSource, const Token& what, const Token& with);
    void execute() override;
    std::string getHandle() override;
private:
    std::string what;
    std::string with;
};


#endif