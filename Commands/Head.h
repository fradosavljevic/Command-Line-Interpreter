#ifndef CLI_HEAD_H
#define CLI_HEAD_H
#include "TextCommand.h"

// Komanda head ispisuje prvih n linija koje zada korisnik.
class Head : public TextCommand {
public:
    Head(const Token& nCount, const Token& textSource);
    void execute() override;
    std::string getHandle() override;
private:
    int lineCount;
};


#endif //CLI_HEAD_H