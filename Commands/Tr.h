#ifndef CLI_TR_H
#define CLI_TR_H
#include "TextCommand.h"


class Tr : public TextCommand {
public:
    Tr(const Token& textSource, const Token& what, const Token& with, bool pipe);
    void execute() override;
    std::string getHandle() override;
};


#endif