
#pragma once
#include <iostream>
#include <fstream>
//#include "Company.h"
#include"stations.h"

class UIcla {
private:
    //Company company;
    //Stations<Nodestation> s;
    //Nodestation n;
    bool interactiveMode;
    int stationNumber;
public:
    // Constructor to initialize interactiveMode
    //UIcla(bool isInteractiveMode) : interactiveMode(isInteractiveMode) {}
    UIcla() :interactiveMode(1), stationNumber(0){} 
    // void run() {
    //     char ask;
    //     cout << "Do you want to run interactive mode(Y/N) ? " << endl;
    //     cin >> ask;
    //     if (ask == 'Y' || ask == 'y') {
    //         runInteractiveMode();
    //     } else {
    //         runSilentMode();
    //     }
    // }
    // void runInteractiveMode(Stations<Nodestation*> s,int size,int h,int m) {
    //     // char userInput;
    //     // cout<<"Hour : "<<h<<" --> min : "<<m<<endl;
    //     // do {
    //     //     //s.printWaitingSP(stationNumber);
    //     //     cout<<"NOW @ STATION "<<stationNumber<<endl;
    //     //     //s.list[stationNumber].getNP()->printQueue();
    //     //     //s.printWaitingWPandNP(stationNumber);
    //     //     cout << "Press Enter to display the next station or 'q' to quit: ";
    //     //     userInput = cin.get();
    //     //     cin.ignore();
    //     //     stationNumber++; // Ignore the newline character
    //     // } 
    //     // while 
    //     // (userInput != 'q' && userInput != 'Q' && stationNumber<size-1);
    //         char userInput;
    //         cout<<"Hour : "<<h<<" --> min : "<<m<<endl;
    //     
    void runInteractiveMode(Stations<Nodestation*> s, int size, int h, int m) {
    int stationNumber = 1;
    while (stationNumber <= size) {
        cout << "Current Time (Hour:Min) ==> " << h << ":" << m << endl;
        cout << "============== STATION #" << stationNumber << " =================" << endl;
        s.printWaitingSP(stationNumber);
        s.printWaitingWPandNP(stationNumber);
        s.printBusesAtStation(stationNumber);
        cout<<endl;
        char userInput;
        cout << "Press Enter to display the next station or 'q' to quit: "<<endl;
        userInput = cin.get();
        cin.ignore();

        if (userInput == 'q' || userInput == 'Q') {
            
            break;
        }

        stationNumber++; 
    }

    // Additional actions after the loop (if needed)
}

    // void runSilentMode() {
    //     ofstream outputFile("output.txt");
    //     streambuf* coutBuffer = cout.rdbuf();
    //     cout.rdbuf(outputFile.rdbuf());

    //     for (int i = 0; i <= company.returnStation().getStationSize(); ++i) {
    //         company.returnStation().printWaitingSP(i);
    //         company.returnStation().printWaitingWPandNP(i);
    //     }

    //     cout.rdbuf(coutBuffer);

    //     cout << "Simulation ends. Output file created: output.txt" << endl;
    // }

    // void displayStationStatus(int stationNumber) {
    //     int currentHour = company.getCurrentHour();
    //     int currentMinute = company.getCurrentMinute();

    //     cout << "Current Time (Hour:Min) ==> " << currentHour << ":" << currentMinute << endl;
    //     cout << "============== STATION #" << stationNumber << " =================" << endl;

    //     //s.printWaitingSP(stationNumber);
    //     company.returnStation().printWaitingWPandNP(stationNumber);
    //     company.returnStation().printBusesAtStation(stationNumber);
    //     company.returnStation().printINCheckUpBuses();
    //     company.returnStation().printFinishedPassengers();

    //     if (interactiveMode) {
    //         cout << "Press Enter to display the next station..." << endl;
    //         cin.ignore();
    //     }

    //     system("cls");
    // }
};
