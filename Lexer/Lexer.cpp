#include "Lexer.h"
#include "Token.h"
#include <iostream>
#include <string>
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
    for (const char c : line) {
        if (c == '"') {
            current += '"';
            quote = !quote;
        }
        else if (std::isspace(c) && !quote) {
            updateParts(parts, current);
        }  // echo "test" | echo "test"
        else if (c == '|' && !quote) {
            updateParts(parts, current);
            parts.emplace_back("|");
        }
        else {
            current += c;
        }
    }
    parts.push_back(current);
    return parts;
}

bool endsWith(const std::string& str, const std::string& suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

vector<Token> Lexer::tokenize(const vector<string>& line) {
    if (line.empty()) return {};
    vector<Token> tokens;
    const Token cmdToken(TokenType::COMMAND, line[0]);
    tokens.push_back(cmdToken);
    bool nextCommand = false;

    for (int i = 1; i < line.size(); i++) {
        TokenType type = {}; string value;

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
            else if (endsWith(line[i], ".txt")) {
                type = TokenType::FILENAME;
                value = line[i];
            }
            else if (line[i][0] == '|') {
                type = TokenType::PIPE_SEPARATOR;
                value = line[i];
                nextCommand = true;
            }
        }

        tokens.emplace_back(type, value);
    }
    tokens.emplace_back(TokenType::END_OF_FILE, "EOF");
    return tokens;
}