#ifndef CLI_ECHO_H
#define CLI_ECHO_H
#include <string>
#include "TextCommand.h"

// Komanda echo ispisuje prosledjeni tekst na standardni izlaz.
class Echo : public TextCommand {
public:
    explicit Echo(const Token& option, const Token& textSource);
    void execute() override;
    std::string getHandle() override;
};


#endif //CLI_ECHO_H