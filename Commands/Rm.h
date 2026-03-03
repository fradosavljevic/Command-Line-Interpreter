#ifndef CLI_RM_H
#define CLI_RM_H
#include "SingleFileCommand.h"

// Komdnda rm, ukoliko postoji, brise fajl koji je korisnik zadao iz fajl sistema.
class Rm : public SingleFileCommand {
public:
    explicit Rm(const Token& filename);
    void execute() override;
    std::string getHandle() override;
};


#endif //CLI_RM_H