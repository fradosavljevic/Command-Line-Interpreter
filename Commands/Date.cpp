#include "Date.h"
#include <chrono>
#include <iostream>
#include <ostream>
using namespace std;

Date::Date(bool pipe) {
    handle = "date";
    if (pipe)
        throw runtime_error("Komanda date ne sme da bude unutar pipe-a");
}

void Date::execute() {
    const auto now = chrono::system_clock::now();
    const time_t t = chrono::system_clock::to_time_t(now);
    const tm* tm = localtime(&t);

    *outputStream << tm->tm_mday << "."
              << tm->tm_mon + 1 << "."
              << tm->tm_year + 1900 << "."
              << endl;
}

string Date::getHandle() {
    return handle;
}
