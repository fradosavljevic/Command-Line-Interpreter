#ifndef CLI_WC_H
#define CLI_WC_H
#include "TextCommand.h"

// Komanda wc broji koliko karaktera/reci ima u stringu u zavisnosti od prosledjene opcije.
class Wc : public TextCommand {
public:
    explicit Wc(const Token& option, const Token& text);
    void execute() override;
    std::string getHandle() override;
};


#endif //CLI_WC_H