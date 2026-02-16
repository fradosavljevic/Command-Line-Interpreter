#include "Echo.h"
#include <iostream>
#include <ostream>
using namespace std;

Echo::Echo(const Token &text, bool pipe) : TextCommand(text, pipe) {
    outputStream = &std::cout;
}

void Echo::execute() {
    string text = getText();
    if (text.empty()) getline(*inputStream, text);
    *outputStream << text << endl;
}

std::string Echo::getHandle() {
    return handle;
}