#include "Parser.h"

#include <stdexcept>
#include <string>
#include "../CommandDB/CommandDB.h"
#include "../Commands/Pipe.h"
using namespace std;

Parser::Parser() = default;

unique_ptr<Command> Parser::parse(const vector<Token>& tokens) {
    if (tokens.empty()) return nullptr;
    CommandDB commandDB;

    bool pipeDetected = false;
    vector<Token> subTokens;
    vector<unique_ptr<Command>> subCommands;
    for (const auto& token : tokens) {
        if (token.getType() == TokenType::PIPE_SEPARATOR || token.getType() == TokenType::END_OF_FILE) {
            const string CMD = subTokens[0].getValue();

            const bool status = commandDB.exists(CMD);
            if (!status) throw runtime_error("Unknown command: " + CMD);

            const size_t numArgs = commandDB.getNumberOfArguments(CMD);
            vector<Token> args;
            args.resize(numArgs, Token());

            if (subTokens.size() - 1 > numArgs)
                throw runtime_error("Too many arguments");

            for (int i = 1; i < subTokens.size(); i++) { args[i - 1] = subTokens[i]; }

            subCommands.push_back(std::move(commandDB.makeCommand(CMD, args, pipeDetected)));
            subTokens.clear();

            if (token.getType() == TokenType::PIPE_SEPARATOR) pipeDetected = true;
        }
        else subTokens.push_back(token);
    }

    if (pipeDetected) return unique_ptr<Command>(new Pipe(std::move(subCommands)));
    return std::move(subCommands[0]);
}