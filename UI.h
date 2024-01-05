#include <iostream>
#include <fstream>
#include "Company.h"


class UI {
private:
    Company company;
    Stations<int> s;
    Nodestation n;
    bool interactiveMode;
    int stationNumber;
public:
    // Constructor to initialize interactiveMode
    UI(bool isInteractiveMode) : interactiveMode(isInteractiveMode) {}

    void run() {
        char ask;
        cout << "Do you want to run interactive mode(Y/N) ? " << endl;
        cin >> ask;
        if (ask == 'Y' || ask == 'y') {
            runInteractiveMode();
        } else {
            runSilentMode();
        }
    }
    void runInteractiveMode() {
        char userInput;
        do {
            s.printWaitingSP(stationNumber);
            s.printWaitingWPandNP(stationNumber);
            cout << "Press Enter to display the next station or 'q' to quit: ";
            userInput = cin.get();
            cin.ignore();  // Ignore the newline character
        } 
        while 
        (userInput != 'q' && userInput != 'Q');
    }

    void runSilentMode() {
        ofstream outputFile("output.txt");
        streambuf* coutBuffer = cout.rdbuf();
        cout.rdbuf(outputFile.rdbuf());

        for (int i = 0; i <= s.getStationSize(); ++i) {
            s.printWaitingSP(i);
            s.printWaitingWPandNP(i);
        }

        cout.rdbuf(coutBuffer);

        cout << "Simulation ends. Output file created: output.txt" << endl;
    }

void displayStationStatus(int stationNumber) {
    int currentHour = company.getCurrentHour();
    int currentMinute = company.getCurrentMinute();

    cout << "Current Time (Hour:Min) ==> " << currentHour << ":" << currentMinute << endl;
    cout << "============== STATION #" << stationNumber << " =================" << endl;

    s.printWaitingSP(stationNumber);
    s.printWaitingWPandNP(stationNumber);

    s.printBusesAtStation(stationNumber);

    if (interactiveMode) {
        cout << "Press Enter to display the next station..." << endl;
        cin.ignore();
    }

    system("cls");
}
};
