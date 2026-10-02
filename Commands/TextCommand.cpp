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
        if (textSource.getType() == TokenType::FILENAME) {
            FileReader fr(textSource.getValue());
            this->text = fr.readMultiLine();
        }
        else if (textSource.getType() == TokenType::NIL && textSource.getValue().empty()) {
            ConsoleReader cr;
            this->text = cr.readMultiLine();
        }
    }
    return this->text;
}

std::string TextCommand::inputText(std::istream *stream) {
    StreamReader reader(stream);
    this->text = reader.readMultiLine();
    return this->text;
}
