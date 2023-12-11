#pragma once
#include<iostream>
#include "LinKedListp.h"
#include "Passenger.h"
#include "stations.h"
using namespace std;


template<typename T>
class Bus {
    public:
		string BusType;
        int capacity;
        int maintenance;
        int currentStation;
		LinkedListp<Passenger> insideBus;


        Bus(){
			BusType = "NULL";
			capacity = 0;
			maintenance = 0;
			currentStation = 0;
        }

		Bus (string type, int cap , int maint){
			BusType = type;
			capacity = cap;
			maintenance = maint;
			currentStation = 0;
		}

     	void print_bus_info() {
    		cout << "Bus type : " << BusType << endl;
    		cout << "Bus capacity : " << capacity << endl;
    		cout << "Bus maintenance : " << maintenance << endl;
			cout << "Bus current Station : " << currentStation << endl;
			}
		
		Bus creatNBus(int capacity){
			Bus bus("Normal",capacity, 0);
			return bus;
		}

        Bus creatWBus(int capacity){
			Bus bus("Wheel",capacity, 0);
			return bus;
		}

	

		
		// void loopStation(){
		// 	int direction=0;

		// 	while(/*the program is working*/){
		// 		Nodestation<T>* station = ReturnStationPointer(currentStation);
		// 		if(station->next==nullptr){
		// 			if(direction==0){direction=1;}
		// 			else if (direction==1){direction==0;}
		// 		}
		// 		while(direction==0 && station->next!=nullptr){
		// 			currentStation++;
		// 		}
		// 		while(direction==1 && station->next!=nullptr){
		// 			currentStation--;
		// 		}
				
				
		// 	}

		// }

};


