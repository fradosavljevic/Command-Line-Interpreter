#include "TextCommand.h"

#include "../Reader/ConsoleReader.h"
#include "../Reader/FileReader.h"
#include <iostream>

#include "../Reader/StreamReader.h"

TextCommand::TextCommand(const Token &textSource, const bool pipe) : Command(&std::cin, &std::cout) {
    if (pipe) this->text = "";
    else
    {
        this->text = textSource.getValue();
        if (textSource.getType() == TokenType::ARGUMENT)
            this->text = textSource.getValue();
        else if (textSource.getType() == TokenType::FILENAME) {
            auto *fr = new FileReader(textSource.getValue());
            this->text = fr->readMultiLine();
            delete fr;
        }
        else if (textSource.getType() == TokenType::NIL && textSource.getValue().empty()) {
            auto *cr = new ConsoleReader();
            this->text = cr->readMultiLine();
            delete cr;
        }
        else {
            throw std::runtime_error("Greska! Nije prepoznat argument");
        }
    }
}

std::string TextCommand::getText() {
    return this->text;
}

std::string TextCommand::inputText(std::istream *stream) {
    auto* reader = new StreamReader(stream);
    this->text = reader->readMultiLine();
    delete reader;
    return this->text;
}
