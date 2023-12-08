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
        ifstream input("input.txt");

            input >> numStations >> minsStations >> numWbuses >> numMbuses >> capacityWBus >> capacityMBus >> CheckupTrips >> checkupDWBus >> checkupDMBus >> MaxW >> OnOffTime >> EventsNum;
            cout << "events: " << EventsNum << endl;
            input.close();
        }
};
