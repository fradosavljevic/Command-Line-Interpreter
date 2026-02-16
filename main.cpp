#include "Engine/InterpreterEngine.h"

// Ulazna tacka programa. Inicijalizuje InterpreterEngine i pokrece glavnu petlju
int main() {
    InterpreterEngine* Engine = InterpreterEngine::getInstance();
    Engine->Start();
    delete Engine;
    return 0;
}