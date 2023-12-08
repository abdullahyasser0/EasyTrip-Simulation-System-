#include <iostream>
#include <fstream>
using namespace std;

class Company {
private:
    int numStations, minsStations;
    int numWbuses, numMbuses, capacityWBus, capacityMBus;
    int CheckupTrips, checkupDWBus, checkupDMBus;
    int MaxW, OnOffTime, EventsNum;

public:
    Company() {
        ifstream inputFile("input.txt");

        if (inputFile.is_open()) {
            inputFile >> numStations >> minsStations >> numWbuses >> numMbuses >> capacityWBus >> capacityMBus >> CheckupTrips >> checkupDWBus >> checkupDMBus >> MaxW >> OnOffTime >> EventsNum;
            std::cout << "events: " << EventsNum << std::endl;
            inputFile.close();
        }
        else {
            std::cerr << "Error opening input file." << std::endl;
        }
    }
};
