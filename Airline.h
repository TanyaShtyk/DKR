#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>

class Airline {
private:
    std::string destination;
    std::string flightNumber;
    std::string aircraftType;
    std::string departureTime;
    std::string daysOfWeek;

public:
    Airline(const std::string& destination, const std::string& flightNumber, const std::string& aircraftType,
            const std::string& departureTime, const std::string& daysOfWeek);

    std::string getDestination() const;
    std::string getFlightNumber() const;
    std::string getAircraftType() const;
    std::string getDepartureTime() const;
    std::string getDaysOfWeek() const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Airline& airline);
};

#endif // AIRLINE_H
