#include "Command.h"
using namespace std;

Command::Command(istream* inStream, ostream* outStream) {
    inputStream = inStream;
    outputStream = outStream;
};

void Command::setState(const bool redirectInput, const bool redirectOutput, const bool inPipe) {
    this->redirectedInput = redirectInput;
    this->redirectedOutput = redirectOutput;
    this->isInPipe = inPipe;
}

tuple<bool, bool, bool> Command::getState() {
    return make_tuple(redirectedInput, redirectedOutput, isInPipe);
}

void Command::setInputStream(std::istream *stream) {
    if (stream) inputStream = stream;
}

void Command::setOutputStream(std::ostream *stream) {
    if (stream) outputStream = stream;
}
