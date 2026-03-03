#ifndef CLI_TRUNCATE_H
#define CLI_TRUNCATE_H
#include "SingleFileCommand.h"

// Komanda truncate otvara postojeci fajl i brise njegov sadrzaj.
class Truncate : public SingleFileCommand {
public:
    explicit Truncate(const Token& fileName);
    void execute() override;
    std::string getHandle() override;
};


#endif //CLI_TRUNCATE_H