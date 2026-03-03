#include "Prompt.h"
#include "../Engine/InterpreterEngine.h"
using namespace std;

Prompt::Prompt(const Token& Symbol) : SingleArgumentCommand(Symbol) {
    handle = "prompt";
}

void Prompt::execute() {
    InterpreterEngine* engine = InterpreterEngine::getInstance();
    engine->setReadySymbol(getArgument());
}

std::string Prompt::getHandle() {
    return handle;
}
