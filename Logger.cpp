#include "Logger.h"

#include <fstream>

Logger::Logger(const std::string& filename) : logFileName(filename) {}

void Logger::log(const std::string& message) {
    std::ofstream logFile(logFileName, std::ios::app);
    if (logFile) {
        logFile << message << std::endl;
        logFile.close();
    }
}
