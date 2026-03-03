#include "InterpreterEngine.h"
#include "../Lexer/Lexer.h"
#include "../Parser/Parser.h"
#include <iostream>
#include <string>

InterpreterEngine* InterpreterEngine::instance = nullptr;
std::stack<std::pair<std::istream*, Context*>> InterpreterEngine::contextStack;

InterpreterEngine::InterpreterEngine() : readySymbol("$"), usingDefaultSource(true), isRunning(true), interactiveMode(true) {
    contextStack.emplace(&std::cin, new Context());
}

bool InterpreterEngine::switchContext() {
    if (contextStack.top().first->eof() && !usingDefaultSource) {
        std::istream* streamPointer = contextStack.top().first;
        Context* contextPointer = contextStack.top().second;

        contextStack.pop();

        if (streamPointer != &std::cin) { delete streamPointer; }
        delete contextPointer;

        usingDefaultSource = interactiveMode = (contextStack.size() == 1);
        return true;
    }
    return false;
}

void InterpreterEngine::Start() {
    while (isRunning) {
        if (usingDefaultSource) std::cout << readySymbol << " ";

        if (switchContext()) continue;

        std::string s; getline(*contextStack.top().first, s);
        this->currentlyProcessing = s;

        try {
            if (const std::unique_ptr<Command> cmd = Parser::parse( Lexer::process(s))) {
                lastExecutedState = cmd->getState();
                if (!std::get<0>(lastExecutedState)) cmd->setInputStream(contextStack.top().second->inputStream);
                if (!std::get<1>(lastExecutedState)) cmd->setOutputStream(contextStack.top().second->outputStream);

                cmd->execute();

                cmd->flushOutputStream();
                if (cmd->wroteToCout()) std::cout << std::endl;
            }
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }

        this->currentlyProcessing = "";
    }
}

InterpreterEngine* InterpreterEngine::getInstance() {
    if (!instance) {
        instance = new InterpreterEngine();
    }
    return instance;
}

void InterpreterEngine::setReadySymbol(const std::string& symbol) {
    this->readySymbol = symbol;
}

void InterpreterEngine::pushNewContext(std::istream *inStream, Context* context) {
    InterpreterEngine* interpreterEngine = getInstance();
    interpreterEngine->usingDefaultSource = false;
    interpreterEngine->interactiveMode = false;
    contextStack.emplace(inStream, context);
}

std::string InterpreterEngine::currentProcessedCommand() {
    return currentlyProcessing;
}
