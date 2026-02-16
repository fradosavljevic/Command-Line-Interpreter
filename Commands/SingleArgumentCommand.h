#ifndef CLI_SINGLEARGUMENTCOMMAND_H
#define CLI_SINGLEARGUMENTCOMMAND_H
#include "Command.h"
#include <string>

class SingleArgumentCommand : public Command {
public:
    explicit SingleArgumentCommand(const Token& Argument);
    std::string getArgument();
private:
    std::string argument;
};


#endif //CLI_SINGLEARGUMENTCOMMAND_H