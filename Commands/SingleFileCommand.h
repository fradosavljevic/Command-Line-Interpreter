#ifndef CLI_SINGLEFILECOMMAND_H
#define CLI_SINGLEFILECOMMAND_H
#include "Command.h"
#include <fstream>
#include <filesystem>

// Klasa namenjena za komande koje rade sa samo jednim fajlom.
class SingleFileCommand : public Command {
public:
    explicit SingleFileCommand(const Token& filename, bool pipe);

    // Getter za filename
    const std::string& getFilename();
private:
    std::string filename;
};


#endif //CLI_SINGLEFILECOMMAND_H