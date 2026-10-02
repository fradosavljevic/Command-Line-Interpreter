#include "Tr.h"

#include <iostream>
#include <ostream>

#include "../CustomExceptions/SyntaxError.h"
#include "../Reader/StreamReader.h"
using namespace std;

Tr::Tr(const Token &textSource, const Token &what, const Token &with) : TextCommand(textSource) {
    handle = "tr";
    this->what = what.getValue();
    if (this->what[0] == '"') this->what = this->what.substr(1, this->what.length() - 2);
    this->with = with.getValue();
}

void Tr::execute() {
    string text = getText();
    if (text.empty()) text = inputText(inputStream);

    if (what.empty()) {
        *outputStream << text << endl;
        return;
    }

    if (with.empty()) {
        size_t pos;
        while ((pos = text.find(what)) != std::string::npos) {
            text.erase(pos, what.length());
        }
    }
    else {
        size_t pos = text.find(what);
        while (pos != std::string::npos) {
            text.replace(pos, what.length(), with);
            pos = text.find(what, pos + with.length());
        }
    }
    *outputStream << text << endl;
}

std::string Tr::getHandle() {
    return handle;
}
