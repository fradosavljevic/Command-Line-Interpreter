#ifndef CLI_PROMPT_H
#define CLI_PROMPT_H
#include "SingleArgumentCommand.h"

// Komanda prompt menja simbol spremnosti u klasi InterpreterEngine.
class Prompt : public SingleArgumentCommand {
public:
    explicit Prompt(const Token& Symbol);
    void execute() override;
    std::string getHandle() override;
};


#endif //CLI_PROMPT_H