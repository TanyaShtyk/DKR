#ifndef INTERFACE_H
#define INTERFACE_H

#include "Airline.h"
#include "Logger.h"

#include <vector>

class Interface {
private:
    std::vector<Airline> airlines;
    Logger logger;

public:
    Interface();
    void start();

private:
    void initializeAirlines();
    void displayFlightsByDestination(const std::string& destination);
    void displayFlightsByDayOfWeek(const std::string& dayOfWeek);
    void displayFlightsByDayOfWeekAndDepartureTime(const std::string& dayOfWeek, const std::string& departureTime);
    void addFlight();
    void removeFlight();
    void saveAirlinesToFile(const std::string& filename, const std::string& encryptionKey);
    std::string xorEncryptDecrypt(const std::string& data, const std::string& key);
};

#endif // INTERFACE_H
