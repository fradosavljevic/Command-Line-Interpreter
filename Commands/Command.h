#ifndef CLI_COMMAND_H
#define CLI_COMMAND_H
#include <set>
#include <istream>
#include "../Lexer/Token.h"

/* Apstraktna klasa Command. Roditeljska klasa za sve komande koje postoje u programu.
   Definise obavezan interfejs koju svaka konkretna komanda mora da implementira. */
class Command {
public:
    virtual ~Command() = default;

    Command(std::istream* inStream, std::ostream* outStream) {
        inputStream = inStream;
        outputStream = outStream;
    };

    virtual void execute() = 0;

    virtual std::string getHandle() = 0;

    void setInputStream(std::istream* stream) { inputStream = stream; };

    void setOutputStream(std::ostream* stream) { outputStream = stream; }
protected:
    std::set<std::string> options;
    std::string handle;
    std::istream *inputStream;
    std::ostream *outputStream;
};


#endif //CLI_COMMAND_H