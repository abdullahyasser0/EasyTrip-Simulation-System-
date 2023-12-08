#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



int main() {
    ifstream inputFile("input.txt");

    int numStations, minsStations;
    int numWbuses, numMbuses, capacityWBus, capacityMBus;
    int CheckupTrips, checkupDWBus, checkupDMBus;
    int MaxW, OnOffTime, EventsNum;
    char type;
    string PType,time,id,STRT,END;

    inputFile >> numStations >> minsStations >> numWbuses >> numMbuses >> capacityWBus >> capacityMBus >> CheckupTrips >> checkupDWBus >> checkupDMBus >> MaxW >> OnOffTime >> EventsNum >> type >> PType >> time >> id >> STRT >> END;
    int hours, minutes;
    char colon;

    istringstream iss(time);
    iss >> hours >> colon >> minutes;
        
    cout << "events: " << EventsNum << endl;

    cout << "type : " << type << endl;
    cout << "PType: " << PType << endl;
    cout << "time: " << time << endl;
    cout << "id: " << id << endl;
    cout << "STRT: " << STRT << endl;
    cout << "END: " << END << endl;

    cout << "Parsed time: Hours = " << hours << ", Minutes = " << minutes << endl;

    inputFile.close();

    /*while (true) {
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes == 60) {
            minutes = 0;
            hours++;
        }
        cout << "time: " << hours << ":" << minutes << endl;
        if (hours == 24)break;
    }*/

    return 0;
}