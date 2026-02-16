#ifndef CLI_SIMPLECOMMAND_H
#define CLI_SIMPLECOMMAND_H
#include "Command.h"

// Klasa namenjena za komande koje nemaju ni argumente ni opcije.
class SimpleCommand : public Command {
public:
    SimpleCommand();
};


#endif //CLI_SIMPLECOMMAND_H