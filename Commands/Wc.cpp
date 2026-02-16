#include "Wc.h"
#include <iostream>
#include <ostream>
using namespace std;

Wc::Wc(const Token &option, const Token &text, bool pipe) : TextCommand(text, pipe) {
    options.insert(option.getValue());
}

void Wc::execute() {
    int counter = 0;
    string line = getText();
    if (line.empty()) getline(*inputStream, line);
    string option = *options.begin();
    if (option == "c") {
        counter = static_cast<int>(line.length());
    }
    else if (option == "w") {
        bool word = false;
        for (auto ch : line) {
            if (std::isspace(ch)) {
                word = false;
            } else {
                if (!word) {
                    counter++;
                    word = true;
                }
            }
        }
    } else {
        throw runtime_error("Nepoznata opcija -" + option);
    }
    *outputStream << counter << endl;
}

std::string Wc::getHandle() {
    return "wc";
}
