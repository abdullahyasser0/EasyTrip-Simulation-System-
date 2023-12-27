// #pragma once

// #include <iostream>
// #include "Company.h"  
// #include "stations.h"
// class UI {
// private:
//     Company company;
//     Stations<int> s;

// public:
//     void run() {
//         char userInput;
//         do {
//             displayStationStatus();
//             cout << "Do you want to continue? (y/n): ";
//             cin >> userInput;
//             cin.ignore();  // Ignore the newline character
//         } while (userInput == 'y' || userInput == 'Y');
//     }

//     void displayStationStatus() {
//         int currentHour = company.getCurrentHour();
//         int currentMinute = company.getCurrentMinute();

//         cout << "Current Time (Hour:Min)==> " << currentHour << ":" << currentMinute << endl;
//         cout << "============== STATION #" << s.getCurrentStation() << " =================" << endl;

//         // Display waiting passengers
//         company.PrintWaitingPassengers();

//         // // Display buses at this station
//         // company.PrintBusesAtStation();

//         // // Display in-checkup buses
//         // company.PrintInCheckupBuses();

//         // // Display finished passengers
//         // company.PrintFinishedPassengers();

//         cout << "Press any key to display the next station..." << endl;
//         cin.ignore();
//         s.moveToNextStation(); 
//         system("cls");
//     }
// };

#include <iostream>
#include <fstream>
#include "Company.h"
#include "Stations.h"

class UI {
private:
    Company company;
    Stations<int> s;
    bool interactiveMode;

public:
    // Constructor to initialize interactiveMode
    UI(bool isInteractiveMode) : interactiveMode(isInteractiveMode) {}

    void run() {
        if (interactiveMode) {
            runInteractiveMode();
        } else {
            runSilentMode();
        }
    }

private:
    void runInteractiveMode() {
        char userInput;
        do {
            displayStationStatus();
            cout << "Press Enter to display the next station or 'q' to quit: ";
            userInput = cin.get();
            cin.ignore();  // Ignore the newline character
        } while (userInput != 'q' && userInput != 'Q');
    }

    void runSilentMode() {
        // Redirect cout to a file
        ofstream outputFile("output.txt");
        streambuf* coutBuffer = cout.rdbuf();
        cout.rdbuf(outputFile.rdbuf());

        // Run the simulation for a fixed duration (e.g., 10 stations)
        for (int i = 0; i < s.getStationSize(); ++i) {
            displayStationStatus();
            s.moveToNextStation();
        }

        // Restore cout
        cout.rdbuf(coutBuffer);

        cout << "Simulation ends. Output file created: output.txt" << endl;
    }

    void displayStationStatus() {
        int currentHour = company.getCurrentHour();
        int currentMinute = company.getCurrentMinute();

        cout << "Current Time (Hour:Min) ==> " << currentHour << ":" << currentMinute << endl;
        cout << "============== STATION #" << s.getCurrentStation() << " =================" << endl;

        // Display waiting passengers, buses, in-checkup buses, finished passengers, etc.
        company.PrintWaitingPassengers();
        if (interactiveMode) {
            cout << "Press Enter to display the next station..." << endl;
            cin.ignore();
        }
        
        system("cls"); 
    }
};
