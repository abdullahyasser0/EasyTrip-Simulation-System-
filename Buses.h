#pragma once
#include<iostream>
#include "dataStructures/LinKedListp.h"
#include "Passenger.h"
#include "dataStructures/PriorityQueue.h"
using namespace std;


class Bus {
    public:
		string BusType;
        int capacity;
        int maintenance;
        int currentStation;
		LinkedListp<Passenger> insideBus;
		PriorityQueue<Passenger> moving_passenger;


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

		void setType(string type){
			BusType=type;
		}

		string getType(){
			return BusType;
		}

     	void print_bus_info() {
    		cout << "Bus type : " << BusType << endl;
    		cout << "Bus capacity : " << capacity << endl;
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
			moving_passenger.enqueue(p);
		}

		Passenger* getPassOff() {
			Passenger *p = moving_passenger.dequeue();
			return p;
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


