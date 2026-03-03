#ifndef CLI_BATCH_H
#define CLI_BATCH_H
#include "SingleFileCommand.h"

// Komanda batch preusmerava tok sa kog InterpreterEngine cita komande.
class Batch : public SingleFileCommand {
public:
    explicit Batch(const Token& batchFile);
    void execute() override;
    std::string getHandle() override;
};


#endif