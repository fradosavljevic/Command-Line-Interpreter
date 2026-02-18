#include "Head.h"
#include <sstream>
using namespace std;

Head::Head(const Token &nCount, const Token &textSource, const bool pipe) : TextCommand(textSource, pipe) {
    handle = "head";
    if (nCount.getValue()[0] != 'n')
        throw runtime_error("Invalid argument: " + nCount.getValue());
    lineCount = stoi(nCount.getValue().substr(1));
}

void Head::execute() {
    string text = getText();
    if (text.empty()) text = inputText(inputStream);
    int c = 0;
    stringstream ss(text);
    string line;
    while (c++ < lineCount && getline(ss, line)) {
        *outputStream << line << endl;
    }
}

std::string Head::getHandle() {
    return handle;
}
