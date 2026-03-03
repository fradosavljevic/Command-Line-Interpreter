#ifndef CLI_INTERPRETERENGINE_H
#define CLI_INTERPRETERENGINE_H
#include <ios>
#include <string>
#include <stack>
#include "Context.h"

// InterpreterEngine je centralna klasa koja kontrolise tok celog programa.
// Ova klasa je takodje mesto gde se hvataju sve greske koje mogu da nastanu prilikom obrade/izvrsavanja komandi
class InterpreterEngine {
public:
    static InterpreterEngine* getInstance();

    void Start();

    void setReadySymbol(const std::string& symbol);

    static void pushNewContext(std::istream* inStream, Context* context);
private:
    InterpreterEngine();
    bool switchContext();
    static InterpreterEngine* instance;
    static std::stack<std::pair<std::istream*, Context*>> contextStack;
    std::string readySymbol, currentlyProcessing;
    bool usingDefaultSource, isRunning, interactiveMode;
    std::tuple<bool, bool, bool> lastExecutedState;
};

#endif //CLI_INTERPRETERENGINE_H