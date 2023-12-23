#include <iostream>
#include "Company.h"  
#include "stations.h"
class UI {
private:
    Company company;
    StationsDLL<int> s;

public:
    void run() {
        char userInput;
        do {
            displayStationStatus();
            cout << "Do you want to continue? (y/n): ";
            cin >> userInput;
            cin.ignore();  // Ignore the newline character
        } while (userInput == 'y' || userInput == 'Y');
    }

    void displayStationStatus() {
        int currentHour = company.getCurrentHour();
        int currentMinute = company.getCurrentMinute();

        cout << "Current Time (Hour:Min)==> " << currentHour << ":" << currentMinute << endl;
        cout << "============== STATION #" << s.getCurrentStation() << " =================" << endl;

        // Display waiting passengers
        company.PrintWaitingPassengers();

        // // Display buses at this station
        // company.PrintBusesAtStation();

        // // Display in-checkup buses
        // company.PrintInCheckupBuses();

        // // Display finished passengers
        // company.PrintFinishedPassengers();

        cout << "Press any key to display the next station..." << endl;
        cin.ignore();
        s.moveToNextStation(); 
        system("cls");
    }
};