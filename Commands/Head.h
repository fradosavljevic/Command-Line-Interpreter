#ifndef CLI_HEAD_H
#define CLI_HEAD_H
#include "TextCommand.h"


class Head : public TextCommand {
public:
    Head(const Token& nCount, const Token& textSource, bool pipe);
    void execute() override;
    std::string getHandle() override;
private:
    int lineCount;
};


#endif //CLI_HEAD_H