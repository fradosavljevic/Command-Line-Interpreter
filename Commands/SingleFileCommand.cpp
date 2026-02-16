#include "SingleFileCommand.h"
#include <iostream>
using namespace std;

SingleFileCommand::SingleFileCommand(const Token &filename, bool pipe) : Command(&std::cin, &std::cout) {
    if (pipe) SingleFileCommand::filename = "";
    else SingleFileCommand::filename = filename.getValue();
}

const string &SingleFileCommand::getFilename() {
    return filename;
}


