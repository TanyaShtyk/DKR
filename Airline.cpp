#include "Airline.h"

Airline::Airline(const std::string& destination, const std::string& flightNumber, const std::string& aircraftType,
                 const std::string& departureTime, const std::string& daysOfWeek)
    : destination(destination), flightNumber(flightNumber), aircraftType(aircraftType),
      departureTime(departureTime), daysOfWeek(daysOfWeek) {}

std::string Airline::getDestination() const {
    return destination;
}

std::string Airline::getFlightNumber() const {
    return flightNumber;
}

std::string Airline::getAircraftType() const {
    return aircraftType;
}

std::string Airline::getDepartureTime() const {
    return departureTime;
}

std::string Airline::getDaysOfWeek() const {
    return daysOfWeek;
}

std::string Airline::toString() const {
    return "Destination: " + destination + ", Flight Number: " + flightNumber +
           ", Aircraft Type: " + aircraftType + ", Departure Time: " + departureTime +
           ", Days of the Week: " + daysOfWeek;
}

std::ostream& operator<<(std::ostream& os, const Airline& airline) {
    os << airline.toString();
    return os;
}
