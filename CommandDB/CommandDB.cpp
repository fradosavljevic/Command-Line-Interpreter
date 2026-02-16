#include "CommandDB.h"

#include "../Commands/Batch.h"
#include "../Commands/Date.h"
#include "../Commands/Echo.h"
#include "../Commands/Prompt.h"
#include "../Commands/Rm.h"
#include "../Commands/Time.h"
#include "../Commands/Touch.h"
#include "../Commands/Truncate.h"
#include "../Commands/Wc.h"
#include "../Commands/Tr.h"
using namespace std;

CommandDB::CommandDB() {
    commands["date"] = [](const vector<Token>& args, bool pipe) { return new Date(pipe); };
    commands["time"] = [](const vector<Token>& args, bool pipe) { return new Time(pipe); };
    commands["touch"] = [](const vector<Token>& args, bool pipe) { return new Touch(args[0], pipe); };
    commands["echo"] = [](const vector<Token>& args, bool pipe) { return new Echo(args[0], pipe); };
    commands["wc"] = [](const vector<Token>& args, bool pipe) { return new Wc(args[0], args[1], pipe); };
    commands["prompt"] = [](const vector<Token>& args, bool pipe) { return new Prompt(args[0], pipe); };
    commands["rm"] = [](const vector<Token>& args, bool pipe) { return new Rm(args[0], pipe); };
    commands["truncate"] = [](const vector<Token>& args, bool pipe) { return new Truncate(args[0], pipe); };
    commands["tr"] = [](const vector<Token>& args, bool pipe) { return new Tr(args[0], args[1], args[2], pipe); };
    commands["batch"] = [](const vector<Token>& args, bool pipe) { return new Batch(args[0], pipe); };

    numArgs["date"] = numArgs["time"] = 0;
    numArgs["touch"] = numArgs["echo"] = numArgs["prompt"] = numArgs["rm"] = numArgs["truncate"] = numArgs["batch"] = 1;
    numArgs["wc"] = 2;
    numArgs["tr"] = 3;
}

int CommandDB::getNumberOfArguments(const string &command) const {
    return numArgs.find(command)->second;
}

bool CommandDB::exists(const string &command) {
    return commands.find(command) != commands.end();
}

unique_ptr<Command> CommandDB::makeCommand(const string &command, const std::vector<Token>& args, bool pipe) const {
    return std::unique_ptr<Command>(commands.find(command)->second(args, pipe));
}
