#ifndef CLI_INTERPRETERENGINE_H
#define CLI_INTERPRETERENGINE_H
#include <ios>
#include <string>
#include <stack>
// InterpreterEngine je centralna klasa koja kontrolise tok celog programa.
// Ova klasa je takodje mesto gde se hvataju sve greske koje mogu da nastanu prilikom obrade/izvrsavanja komandi
class InterpreterEngine {
public:
    static InterpreterEngine* getInstance();

    void Start();

    void setReadySymbol(const std::string& symbol);

    static void pushInputStream(std::istream* inStream);
private:
    bool switchContext();
    InterpreterEngine();
    static InterpreterEngine* instance;
    static std::stack<std::istream*> inputStream;
    std::string readySymbol;
    bool usingDefaultSource;
    bool isRunning;
};


#endif //CLI_INTERPRETERENGINE_H