#ifndef CLI_TOUCH_H
#define CLI_TOUCH_H
#include "SingleFileCommand.h"

//Komanda touch kreira novi fajl ako on ne postoji. U suprotnom baca gresku.
class Touch : public SingleFileCommand {
public:
    explicit Touch(const Token &filename, bool pipe);
    void execute() override;
    std::string getHandle() override;
};


#endif //CLI_TOUCH_H