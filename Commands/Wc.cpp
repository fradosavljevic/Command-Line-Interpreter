#include "Wc.h"
#include <iostream>
#include <ostream>
using namespace std;

Wc::Wc(const Token &option, const Token &text) : TextCommand(text) {
    if (option.getValue().empty())
        throw runtime_error("Greska! Nije prosledjena opcija!");
    options.insert(option.getValue());
}

void Wc::execute() {
    int counter = 0;
    string text = getText();
    if (text.empty()) getline(*inputStream, text);
    string option = *options.begin();
    if (option == "c") {
        counter = static_cast<int>(text.length());
    }
    else if (option == "w") {
        bool word = false;
        for (auto ch : text) {
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
