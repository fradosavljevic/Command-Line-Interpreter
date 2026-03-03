#include "Echo.h"
#include <iostream>
using namespace std;

Echo::Echo(const Token &textSource) : TextCommand(textSource) {
    outputStream = &std::cout;
}

void Echo::execute() {
    string text = getText();
    if (text.empty()) text = inputText(inputStream);
    *outputStream << text;
    if (outputStream == &std::cout) writtenToCout = true;
}

std::string Echo::getHandle() {
    return handle;
}