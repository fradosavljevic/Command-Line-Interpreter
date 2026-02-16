#include "SimpleCommand.h"
#include <iostream>

SimpleCommand::SimpleCommand() : Command(&std::cin, &std::cout) {}
