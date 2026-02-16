#include "Time.h"
#include <chrono>
#include <iostream>
using namespace std;

Time::Time(bool pipe) {
    handle = "time";
}

void Time::execute() {
    const auto now = chrono::system_clock::now();
    const time_t t = chrono::system_clock::to_time_t(now);
    const tm* tm = localtime(&t);

    *outputStream << tm->tm_hour << ":"
              << tm->tm_min << ":"
              << tm->tm_sec
              << endl;
}

std::string Time::getHandle() {
    return handle;
}
