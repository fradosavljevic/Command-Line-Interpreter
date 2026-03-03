#include "TextCommand.h"

#include "../Reader/ConsoleReader.h"
#include "../Reader/FileReader.h"
#include <iostream>

#include "../Reader/StreamReader.h"

TextCommand::TextCommand(const Token &textSource) : Command(&std::cin, &std::cout) {
    this->textSource = textSource;
}

std::string TextCommand::getText() {
    if (!textSource.getValue().empty() && redirectedInput) throw std::runtime_error("Ne mogu da budu zajedno argument i ulazna redirekcija");
    if (isInPipe || redirectedInput) this->text = "";
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
    }
    return this->text;
}

std::string TextCommand::inputText(std::istream *stream) {
    auto* reader = new StreamReader(stream);
    this->text = reader->readMultiLine();
    delete reader;
    return this->text;
}
