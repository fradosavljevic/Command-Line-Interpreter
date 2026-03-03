#ifndef CLI_COMMAND_H
#define CLI_COMMAND_H
#include <set>
#include <istream>
#include "../Lexer/Token.h"

// Apstraktna klasa Command. Roditeljska klasa za sve komande koje postoje u programu.
// Definise obavezan interfejs koju svaka konkretna komanda mora da implementira.
class Command {
public:
    virtual ~Command() = default;

    Command(std::istream* inStream, std::ostream* outStream);

    virtual void execute() = 0;

    virtual std::string getHandle() = 0;

    void setState(bool redirectInput, bool redirectOutput, bool inPipe);

    std::tuple<bool, bool, bool> getState();

    void setInputStream(std::istream* stream);

    void setOutputStream(std::ostream* stream);

    void flushOutputStream() const { if (outputStream) outputStream->flush(); }

    [[nodiscard]] bool wroteToCout() const { return writtenToCout; }
protected:
    std::set<std::string> options;
    std::string handle;
    std::istream *inputStream;
    std::ostream *outputStream;
    bool redirectedInput{}, redirectedOutput{}, isInPipe{}, writtenToCout{};
};


#endif //CLI_COMMAND_H