#include "SingleFileCommand.h"
#include <iostream>
using namespace std;

SingleFileCommand::SingleFileCommand(const Token &filename) : Command(&std::cin, &std::cout) {
    if (isInPipe) SingleFileCommand::filename = "";
    else SingleFileCommand::filename = filename.getValue();
}

const string &SingleFileCommand::getFilename() {
    return filename;
}


