#ifndef CLI_SINGLEARGUMENTCOMMAND_H
#define CLI_SINGLEARGUMENTCOMMAND_H
#include "Command.h"
#include <string>

// Klasa namenjena za komande koje imaju samo jedan argument.
class SingleArgumentCommand : public Command {
public:
    explicit SingleArgumentCommand(const Token& Argument);
    std::string getArgument();
private:
    std::string argument;
};


#endif //CLI_SINGLEARGUMENTCOMMAND_H