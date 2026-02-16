#ifndef CLI_PROMPT_H
#define CLI_PROMPT_H
#include "SingleArgumentCommand.h"

class Prompt : public SingleArgumentCommand {
public:
    explicit Prompt(const Token& Symbol, bool pipe);
    void execute() override;
    std::string getHandle() override;
};


#endif //CLI_PROMPT_H