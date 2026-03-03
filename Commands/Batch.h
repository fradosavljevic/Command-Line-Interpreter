#ifndef CLI_BATCH_H
#define CLI_BATCH_H
#include "SingleFileCommand.h"


class Batch : public SingleFileCommand {
public:
    explicit Batch(const Token& batchFile);
    void execute() override;
    std::string getHandle() override;
};


#endif