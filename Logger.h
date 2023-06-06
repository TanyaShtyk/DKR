#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
private:
    std::string logFileName;

public:
    Logger(const std::string& filename);
    void log(const std::string& message);
};

#endif // LOGGER_H
