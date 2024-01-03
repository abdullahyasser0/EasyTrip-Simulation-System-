#pragma once
#include<iostream>
#include "dataStructures/LinKedListp.h"
#include "Passenger.h"
#include "dataStructures/PriorityQueue.h"
using namespace std;


class Bus {
    private:
		string BusType;
        int maxcapacity;
        int maintenance;
        int currentStation;
		LinkedListp<Passenger> insideBus;
		PriorityQueue<Passenger> moving_passenger;

public:
        Bus(){
			BusType = "NULL";
			maxcapacity = 20;
			maintenance = 0;
			currentStation = 0;
        }

		Bus (string type, int cap , int maint){
			BusType = type;
			maxcapacity = cap;
			maintenance = maint;
			currentStation = 0;
		}

		void setType(string type){
			BusType=type;
		}

		string getType(){
			return BusType;
		}

     	void print_bus_info() {
    		cout << "Bus type : " << BusType << endl;
    		cout << "Bus capacity : " << maxcapacity << endl;
    		cout << "Bus maintenance : " << maintenance << endl;
			cout << "Bus current Station : " << currentStation << endl;
			}
		
		Bus* createNBus(int capacity){
			Bus* bus = new Bus("Normal",capacity, 0);
			return bus;
		}

        Bus* createWBus(int capacity){
			Bus* bus= new Bus("Wheel",capacity, 0);
			return bus;
		}

		void getPassOn(Passenger* p){
			moving_passenger.enqueueInsideBus(p);
		}

		// void getPassOn(Passenger* p) {
        // if (moving_passenger.size() < maxcapacity && /*time*/ <= 24.00) {
        //     moving_passenger.enqueueInsideBus(p);
        // 	}
    	// }

		Passenger* getPassOff() {
			Passenger *p = moving_passenger.dequeue();
			return p;
		}

		void nextStation() {
        currentStation += 1;
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

	// bool isFull(){
	// }
};


