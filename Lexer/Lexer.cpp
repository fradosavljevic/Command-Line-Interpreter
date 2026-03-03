#include "Lexer.h"
#include "Token.h"
#include <iostream>
#include <string>

#include "../CustomExceptions/SyntaxError.h"
using namespace std;

Lexer::Lexer() = default;

vector<Token> Lexer::process(const std::string& line) {
    return tokenize(split(line));
}

void updateParts(std::vector<string>& parts, string& current) {
    if (!current.empty()) {
        parts.push_back(current);
        current.clear();
    }
}

vector<string> Lexer::split(const std::string& line) {
    if (line.empty()) return {};
    vector<string> parts;
    string current;
    bool quote = false;
    for (size_t i = 0; i < line.size(); i++) {
        char c = line[i];

        if (c == '"') {
            current += '"';
            quote = !quote;
        }
        else if ((c == '|' || c == '<' || std::isspace(c)) && !quote) {
            updateParts(parts, current);
            if (!std::isspace(c)) parts.emplace_back(1, c);
        }
        else if (c == '>' && !quote) {
            updateParts(parts, current);
            if (i + 1 < line.size() && line[i + 1] == '>') {
                parts.emplace_back(">>"); i++;
            }
            else parts.emplace_back(">");
        }
        else {
            current += c;
        }
    }
    updateParts(parts, current);
    return parts;
}

bool endsWith(const std::string& str, const std::string& suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

vector<Token> Lexer::tokenize(const vector<string>& line) {
    if (line.empty()) return {};
    vector<Token> tokens;
    vector<string> invalidValues;
    const Token cmdToken(TokenType::COMMAND, line[0]);
    tokens.push_back(cmdToken);
    bool nextCommand = false;

    for (int i = 1; i < line.size(); i++) {
        TokenType type = TokenType::NIL; string value = line[i];

        if (nextCommand) {
            type = TokenType::COMMAND;
            value = line[i];
            nextCommand = false;
        }
        else {
            if (line[i][0] == '"' && line[i][line[i].size() - 1] == '"') {
                type = TokenType::ARGUMENT;
                value = line[i].substr(1, line[i].length() - 2);
            }
            else if (line[i][0] == '-') {
                type = TokenType::OPTION;
                value = line[i].substr(1, line[i].length());
            }
            else if (endsWith(line[i], ".txt") || endsWith(line[i], ".out")) {
                type = TokenType::FILENAME;
                value = line[i];
            }
            else if (line[i][0] == '|') {
                type = TokenType::PIPE_SEPARATOR;
                value = line[i];
                nextCommand = true;
            }
            else if (line[i] == ">") {
                type = TokenType::REDIRECT_OUTPUT;
                value = line[i];
            }
            else if (line[i] == "<") {
                type = TokenType::REDIRECT_INPUT;
                value = line[i];
            }
            else if (line[i] == ">>") {
                type = TokenType::APPEND_OUTPUT;
                value = line[i];
            }
        }

        if (type == TokenType::NIL && !value.empty()) { invalidValues.push_back(value); }
        tokens.emplace_back(type, value);
    }

    if (!invalidValues.empty())
        throw SyntaxError(invalidValues);

    tokens.emplace_back(TokenType::END_OF_LINE, "EOL");
    return tokens;
}