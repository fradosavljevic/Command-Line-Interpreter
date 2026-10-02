#include "Echo.h"

#include <algorithm>
#include <iostream>
using namespace std;

Echo::Echo(const Token& option, const Token &textSource) : TextCommand(textSource) {
    outputStream = &std::cout;
    options.insert(option.getValue());
}

void Echo::execute() {
    string text = getText();
    if (text.empty() && !isInPipe) text = inputText(inputStream);
    if (*options.begin() == "r") reverse(text.begin(), text.end());
    *outputStream << text;
    if (outputStream == &std::cout) writtenToCout = true;
}

std::string Echo::getHandle() {
    return handle;
}