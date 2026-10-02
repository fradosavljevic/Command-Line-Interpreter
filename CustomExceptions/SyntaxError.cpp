#include "SyntaxError.h"
#include "../Engine/InterpreterEngine.h"
using namespace std;

string SyntaxError::processError(const vector<string> &invalidValues) {
    InterpreterEngine* engine = InterpreterEngine::getInstance();
    string currentlyProcessing = engine->currentProcessedCommand();
    string errorMessage = "Greska! Delovi komande nisu prepoznati:\n" + currentlyProcessing + "\n";
    string pointers(currentlyProcessing.length(), ' ');

    size_t currentSearchPos = 0;

    for (const auto & val : invalidValues) {
        size_t pos = currentlyProcessing.find(val, currentSearchPos);

        if (pos != string::npos) {
            for (size_t i = 0; i < val.length(); ++i) {
                pointers[pos + i] = '^';
            }

            currentSearchPos = pos + val.length();
        }
    }

    errorMessage += pointers;
    return errorMessage;
}
