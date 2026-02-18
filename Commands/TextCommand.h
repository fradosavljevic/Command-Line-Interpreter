#ifndef CLI_TEXTCOMMAND_H
#define CLI_TEXTCOMMAND_H
#include "Command.h"

//Obezbedjuje tekst komandama koje rade sa tekstom
class TextCommand : public Command {
public:
    explicit TextCommand(const Token& textSource, bool pipe = false);

    // Getter za text
    std::string getText();

    std::string inputText(std::istream* stream);
private:
    std::string text;
};


#endif //CLI_TEXTCOMMAND_H