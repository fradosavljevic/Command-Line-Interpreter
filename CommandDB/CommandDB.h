#ifndef CLI_COMMANDDB_H
#define CLI_COMMANDDB_H
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>

#include "../Commands/Command.h"

// Klasa CommandDB. Sluzi kao 'baza podataka' svih dostupnih komandi u programu.
// Cuva pozive funkcija pomocu kojih se pravi konkretna instanca neke komande, kao i njen broj argumenata.
class CommandDB {
public:
    CommandDB();

    // Proverava da li trazena komanda postoji
    bool exists(const std::string &command);

    // Kreira novu instancu trazene komande i vraca je kao unique_ptr
    std::unique_ptr<Command> makeCommand(const std::string &command, std::vector<Token> &args, bool pipe) const;

    size_t getNumberOfArguments(const std::string &command) const;
private:
    typedef struct CommandSpecification {
        std::vector<TokenType> format;
        std::vector<bool> optional;
        std::function<Command*(std::vector<Token>, bool)> commands;
    } CommandSpecification;

    static void checkAndValidate(const CommandSpecification& specification, std::vector<Token> &args);

    std::unordered_map<std::string, CommandSpecification> commands;
};


#endif //CLI_COMMANDDB_H