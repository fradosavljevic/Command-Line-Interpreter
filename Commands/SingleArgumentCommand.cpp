#include "SingleArgumentCommand.h"
#include <iostream>
using namespace std;

SingleArgumentCommand::SingleArgumentCommand(const Token &Argument) : Command(&std::cin, &std::cout) {
    argument = Argument.getValue();
}

std::string SingleArgumentCommand::getArgument() {
    return argument;
}
