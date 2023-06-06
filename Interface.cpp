#include "Interface.h"

#include <iostream>
#include <fstream>
#include <algorithm>

Interface::Interface() : logger("log.txt") {}

void Interface::start() {
    initializeAirlines();

    std::string destination;
    std::string dayOfWeek;
    std::string departureTime;

    std::cout << "=== Airline Management System ===" << std::endl;

    while (true) {
        std::cout << "\nSelect an option:" << std::endl;
        std::cout << "1. Display flights by destination" << std::endl;
        std::cout << "2. Display flights by day of the week" << std::endl;
        std::cout << "3. Display flights by day of the week and departure time" << std::endl;
        std::cout << "4. Add a flight" << std::endl;
        std::cout << "5. Remove a flight" << std::endl;
        std::cout << "6. Save airlines to file with encryption" << std::endl;
        std::cout << "7. Exit" << std::endl;

        int option;
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Enter destination: ";
                std::cin >> destination;
                displayFlightsByDestination(destination);
                break;
            case 2:
                std::cout << "Enter day of the week: ";
                std::cin >> dayOfWeek;
                displayFlightsByDayOfWeek(dayOfWeek);
                break;
            case 3:
                std::cout << "Enter day of the week: ";
                std::cin >> dayOfWeek;
                std::cout << "Enter departure time: ";
                std::cin >> departureTime;
                displayFlightsByDayOfWeekAndDepartureTime(dayOfWeek, departureTime);
                break;
            case 4:
                addFlight();
                break;
            case 5:
                removeFlight();
                break;
            case 6: {
                std::string filename;
                std::string encryptionKey;
                std::cout << "Enter filename to save: ";
                std::cin >> filename;
                std::cout << "Enter encryption key: ";
                std::cin >> encryptionKey;
                saveAirlinesToFile(filename, encryptionKey);
                break;
            }
            case 7:
                std::cout << "Exiting... Thank you!" << std::endl;
                return;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
    }
}

void Interface::initializeAirlines() {
    airlines.emplace_back("New York", "NY123", "Boeing 747", "09:00", "Monday");
    airlines.emplace_back("London", "LN456", "Airbus A380", "13:30", "Tuesday");
    airlines.emplace_back("Paris", "PR789", "Boeing 737", "17:45", "Wednesday");
    airlines.emplace_back("Tokyo", "TK012", "Boeing 777", "20:15", "Thursday");
    airlines.emplace_back("Sydney", "SD345", "Airbus A350", "10:30", "Friday");
}

void Interface::displayFlightsByDestination(const std::string& destination) {
    std::cout << "\nFlights to " << destination << ":" << std::endl;

    for (const auto& airline : airlines) {
        if (airline.getDestination() == destination)
            std::cout << airline.toString() << std::endl;
    }
}

void Interface::displayFlightsByDayOfWeek(const std::string& dayOfWeek) {
    std::cout << "\nFlights on " << dayOfWeek << ":" << std::endl;

    for (const auto& airline : airlines) {
        if (airline.getDaysOfWeek() == dayOfWeek)
            std::cout << airline.toString() << std::endl;
    }
}

void Interface::displayFlightsByDayOfWeekAndDepartureTime(const std::string& dayOfWeek, const std::string& departureTime) {
    std::cout << "\nFlights on " << dayOfWeek << " with departure time after " << departureTime << ":" << std::endl;

    for (const auto& airline : airlines) {
        if (airline.getDaysOfWeek() == dayOfWeek && airline.getDepartureTime() > departureTime)
            std::cout << airline.toString() << std::endl;
    }
}

void Interface::addFlight() {
    std::string destination;
    std::string flightNumber;
    std::string aircraftType;
    std::string departureTime;
    std::string daysOfWeek;

    std::cout << "\nEnter flight details:" << std::endl;
    std::cout << "Destination: ";
    std::cin >> destination;
    std::cout << "Flight number: ";
    std::cin >> flightNumber;
    std::cout << "Aircraft type: ";
    std::cin >> aircraftType;
    std::cout << "Departure time: ";
    std::cin >> departureTime;
    std::cout << "Days of the week: ";
    std::cin >> daysOfWeek;

    airlines.emplace_back(destination, flightNumber, aircraftType, departureTime, daysOfWeek);
    std::cout << "Flight added successfully!" << std::endl;
    logger.log("Flight added: " + destination + " - " + flightNumber);
}

void Interface::removeFlight() {
    std::string flightNumber;

    std::cout << "\nEnter the flight number to remove: ";
    std::cin >> flightNumber;

    auto it = std::find_if(airlines.begin(), airlines.end(), [&flightNumber](const Airline& airline) {
        return airline.getFlightNumber() == flightNumber;
    });

    if (it != airlines.end()) {
        std::string destination = it->getDestination();
        airlines.erase(it);
        std::cout << "Flight " << flightNumber << " removed successfully!" << std::endl;
        logger.log("Flight removed: " + destination + " - " + flightNumber);
    } else {
        std::cout << "Flight number not found. Unable to remove." << std::endl;
    }
}

void Interface::saveAirlinesToFile(const std::string& filename, const std::string& encryptionKey) {
    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    for (const auto& airline : airlines) {
        std::string encryptedData = xorEncryptDecrypt(airline.toString(), encryptionKey);
        outputFile << encryptedData << std::endl;
    }

    outputFile.close();
    std::cout << "Airlines saved to file: " << filename << std::endl;
    logger.log("Airlines saved to file: " + filename);
}

std::string Interface::xorEncryptDecrypt(const std::string& data, const std::string& key) {
    std::string result = data;
    int keyLength = key.length();
    int dataLength = data.length();

    for (int i = 0; i < dataLength; i++) {
        result[i] = data[i] ^ key[i % keyLength];
    }

    return result;
}
