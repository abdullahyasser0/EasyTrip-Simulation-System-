
#pragma once
#include <iostream>
#include <fstream>
//#include "Company.h"
#include"stations.h"

class UIcla {
private:
    bool interactiveMode;
    int stationNumber;
public:
    
    UIcla() :interactiveMode(1), stationNumber(0){} 
      
    void runInteractiveMode(Stations<Nodestation*> s, int size, int h, int m,LinkedListp<Bus> CheckupBusses,int choice) {
        static bool hasExecuted = false;
        if(choice==1){
        int stationNumber = 1;
        while (stationNumber <= size) {
            cout << "Current Time (Hour:Min) ==> " << h << ":" << m << endl;
            cout << "============== STATION #" << stationNumber << " =================" << endl;
            s.printWaitingSP(stationNumber);
            s.printWaitingWPandNP(stationNumber);
            s.printBusesAtStation(stationNumber);
            CheckupBusses.printCheckupBusses();
            s.printFinishedPassengers(stationNumber);
            cout<<endl;
            char userInput;
            cout << "Press Any key to display the next station "<<endl;
            userInput = cin.get();
            stationNumber++; 
        }
    }
    else if(!hasExecuted){
        cout<<"Silent Mode\nSimulation starts...\nSimulation ends, Outputt file created\n";
        hasExecuted = true;
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
