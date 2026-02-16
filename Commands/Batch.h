#ifndef CLI_BATCH_H
#define CLI_BATCH_H
#include "SingleFileCommand.h"


class Batch : public SingleFileCommand {
public:
    Batch(const Token& inputFile, bool pipe);
    void execute() override;
    std::string getHandle() override;
};


#endif