#ifndef CLI_TIME_H
#define CLI_TIME_H
#include "SimpleCommand.h"

// Komanda time prikazuje trenutno vreme u formatu hh:mm:ss
class Time : public SimpleCommand {
public:
    Time();
    void execute() override;
    std::string getHandle() override;
};


#endif //CLI_TIME_H