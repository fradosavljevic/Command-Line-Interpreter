#ifndef CLI_DATE_H
#define CLI_DATE_H
#include "SimpleCommand.h"

// Komanda date prikazuje danasnji datum u formatu dd.mm.yyyy
class Date : public SimpleCommand {
public:
    Date();
    std::string getHandle() override;
    void execute() override;
};


#endif //CLI_DATE_H