#include "InterpreterEngine.h"
#include "../Lexer/Lexer.h"
#include "../Parser/Parser.h"
#include <iostream>
#include <string>

InterpreterEngine* InterpreterEngine::instance = nullptr;
std::stack<std::istream*> InterpreterEngine::inputStream;

InterpreterEngine::InterpreterEngine() : readySymbol("$"), usingDefaultSource(true), isRunning(true) { inputStream.push(&std::cin); }

bool InterpreterEngine::switchContext() {
    if (inputStream.top()->eof() && !usingDefaultSource) {
        delete inputStream.top();
        inputStream.pop();
        usingDefaultSource = (inputStream.size() == 1);
        return true;
    }
    return false;
}

void InterpreterEngine::Start() {
    while (isRunning) {
        if (usingDefaultSource) std::cout << readySymbol << " ";

        if (switchContext()) continue;

        std::string s; getline(*inputStream.top(), s);

        try {
            if (const std::unique_ptr<Command> cmd = Parser::parse( Lexer::process(s)))
                cmd->execute();
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
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

void InterpreterEngine::pushInputStream(std::istream *inStream) {
    InterpreterEngine* interpreterEngine = getInstance();
    interpreterEngine->usingDefaultSource = false;
    inputStream.push(inStream);
}