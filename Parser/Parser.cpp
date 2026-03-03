#include "Parser.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include "../CommandDB/CommandDB.h"
#include "../Commands/Pipe.h"
using namespace std;

Parser::Parser() = default;

bool classifyRedirection(size_t &i, const Token& token, const vector<Token>& tokens, const TokenType& redirection, string &file) {
    if (token.getType() == redirection) {
        if (i + 1 >= tokens.size()) throw runtime_error("[Parser]: No redirection given");
        if (tokens[i + 1].getType() == TokenType::FILENAME) { file = tokens[i + 1].getValue(); i++; }
        else throw runtime_error("[Parser]: Invalid redirection given");
        return true;
    }
    return false;
}

unique_ptr<Command> processSubCommand(const vector<Token>& subTokens, CommandDB& db, const bool piped) {
    string inFile, outFile;
    bool inputRedirection = false, outputRedirection = false, appendFlag = false;
    vector<Token> clean;

    for (size_t i = 0; i < subTokens.size(); ++i) {
        if (classifyRedirection(i, subTokens[i], subTokens, TokenType::REDIRECT_INPUT, inFile)) inputRedirection = true;
        else if (classifyRedirection(i, subTokens[i], subTokens, TokenType::REDIRECT_OUTPUT, outFile)) appendFlag = false, outputRedirection = true;
        else if (classifyRedirection(i, subTokens[i], subTokens, TokenType::APPEND_OUTPUT, outFile)) outputRedirection = appendFlag = true;
        else clean.push_back(subTokens[i]);
    }

    const string CMD = clean[0].getValue();

    if (!db.exists(CMD)) throw runtime_error("[Parser]: Unknown command: " + CMD);

    vector args(clean.begin() + 1, clean.end());
    if (clean.size() - 1 > db.getNumberOfArguments(CMD)) throw runtime_error("[Parser]: Too many arguments");

    auto cmd = db.makeCommand(CMD, args);

    if (inputRedirection) cmd->setInputStream(new ifstream(inFile));
    if (outputRedirection) cmd->setOutputStream(new ofstream(outFile, appendFlag ? ios::app : ios::out));

    cmd->setState(inputRedirection, outputRedirection, piped);
    return cmd;
}

unique_ptr<Command> Parser::parse(const vector<Token>& tokens) {
    if (tokens.empty()) return nullptr;
    static CommandDB commandDB;

    bool pipeDetected = false;

    vector<Token> subTokens;
    vector<unique_ptr<Command>> subCommands;

    for (const auto & token : tokens) {
        if (token.getType() == TokenType::PIPE_SEPARATOR || token.getType() == TokenType::END_OF_LINE) {
            subCommands.push_back(std::move(processSubCommand(subTokens, commandDB, pipeDetected)));

            subTokens.clear();

            if (token.getType() == TokenType::PIPE_SEPARATOR) pipeDetected = true;
        }
        else subTokens.push_back(token);
    }

    if (pipeDetected) return unique_ptr<Command>(new Pipe(std::move(subCommands)));
    return std::move(subCommands[0]);
}