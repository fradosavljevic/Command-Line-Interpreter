#include "CommandDB.h"

#include "../Commands/Batch.h"
#include "../Commands/Date.h"
#include "../Commands/Echo.h"
#include "../Commands/Head.h"
#include "../Commands/Prompt.h"
#include "../Commands/Rm.h"
#include "../Commands/Time.h"
#include "../Commands/Touch.h"
#include "../Commands/Truncate.h"
#include "../Commands/Wc.h"
#include "../Commands/Tr.h"
using namespace std;

CommandDB::CommandDB() {
    commands["date"] = {
        {},
        {},
        [](const vector<Token>& args, const bool pipe) { return new Date(pipe); }
    };
    commands["time"] = {
        {},
        {},
        [](const vector<Token>& args, const bool pipe) { return new Time(pipe); }
    };
    commands["touch"] = {
        {TokenType::FILENAME},
        {false},
        [](const vector<Token>& args, const bool pipe) { return new Touch(args[0], pipe); }
    };
    commands["echo"] = {
        {TokenType::FILE_OR_ARGUMENT},
        {true},
        [](const vector<Token>& args, const bool pipe) { return new Echo(args[0], pipe); }
    };
    commands["wc"] = {
        {TokenType::OPTION, TokenType::FILE_OR_ARGUMENT},
        {true, true},
        [](const vector<Token>& args, const bool pipe) { return new Wc(args[0], args[1], pipe); }
    };
    commands["prompt"] = {
        {TokenType::ARGUMENT},
        {false},
        [](const vector<Token>& args, const bool pipe) { return new Prompt(args[0], pipe); }
    };
    commands["rm"] = {
        {TokenType::FILENAME},
        {false},
        [](const vector<Token>& args, const bool pipe) { return new Rm(args[0], pipe); }
    };
    commands["truncate"] = {
        {TokenType::FILENAME},
        {false},
        [](const vector<Token>& args, const bool pipe) { return new Truncate(args[0], pipe); }
    };
    commands["tr"] = {
        {TokenType::FILE_OR_ARGUMENT, TokenType::OPTION_OR_ARGUMENT, TokenType::ARGUMENT},
        {true, false, true},
        [](const vector<Token>& args, const bool pipe) { return new Tr(args[0], args[1], args[2], pipe); },
    };
    commands["batch"] = {
        {TokenType::FILENAME},
        {false},
        [](const vector<Token>& args, const bool pipe) { return new Batch(args[0], pipe); }
    };
    commands["head"] = {
        {TokenType::OPTION, TokenType::FILE_OR_ARGUMENT},
        {false, true},
        [](const vector<Token>& args, const bool pipe) { return new Head(args[0], args[1], pipe); }
    };
}

void CommandDB::checkAndValidate(const CommandSpecification& specification, std::vector<Token> &args) {
    vector<Token> validArguments;
    size_t ptr = 0;

    for (size_t i = 0; i < specification.format.size(); i++) {
        bool match = false;

        if (ptr < args.size()) {
            int argType = static_cast<int>(args[ptr].getType());
            int formatField = static_cast<int>(specification.format[i]);

            if (argType & formatField) {
                validArguments.push_back(args[ptr]);
                ptr++;
                match = true;
            }
        }

        if (!match) {
            if (specification.optional[i]) {
                validArguments.emplace_back(TokenType::NIL, "");
            } else {
                throw runtime_error("Nije prosledjen obavezan argument!");
            }
        }
    }

    args = validArguments;
}

size_t CommandDB::getNumberOfArguments(const string &command) const {
    return commands.find(command)->second.format.size();
}

bool CommandDB::exists(const string &command) {
    return commands.find(command) != commands.end();
}

unique_ptr<Command> CommandDB::makeCommand(const string &command, vector<Token> &args, bool pipe) const {
    const CommandSpecification* specification = &commands.find(command)->second;
    checkAndValidate(*specification, args);
    return std::unique_ptr<Command>(commands.find(command)->second.commands(args, pipe));
}
