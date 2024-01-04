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
        int nextStation;
		int direction; //0>>forward  ,, 1>>backword 
		int movingMins;// bus progress 
		int STSmins; //station to station mints 
		PriorityQueue<Passenger> moving_passenger;

public:
		PriorityQueue<Passenger> getInBusPass(){
			return moving_passenger;
		}
		
        Bus(){
			BusType = "NULL";
			maxcapacity = 20;
			maintenance = 0;
			nextStation = 0;
			direction=0;
			movingMins=0;
			STSmins=0;
        }

		Bus (string type, int cap , int maint, int STS){
			BusType = type;
			maxcapacity = cap;
			maintenance = maint;
			nextStation = 0;
			direction=0;
			movingMins=0;
			STSmins=STS;

		}
		void plusMoviMins(){
			movingMins++;
		}
		bool arrived(){
			if(movingMins==STSmins){
				movingMins=0;
				return true;
			}
			return false;
		}
		void setType(string type){
			BusType=type;
		}

		string getType(){
			return BusType;
		}
		int getCapacity(){
			return maxcapacity;
		}
     	void print_bus_info() {
    		cout << "Bus type : " << BusType << endl;
    		cout << "Bus capacity : " << maxcapacity << endl;
    		cout << "Bus maintenance : " << maintenance << endl;
			cout << "Bus current station : " << nextStation-1 << endl;
			cout << "Bus next Station  : " << nextStation << endl;
			cout<<"imprinting what inside mee "<<endl;
			moving_passenger.printQueue();
			}
		

		template<typename T>
		void getPassOn(T* p){
			moving_passenger.enqueueInsideBus(p);
			maxcapacity--;
		}

	

		Passenger* getPassOff() {
			if(!moving_passenger.isEmpty()){
			Passenger *p = moving_passenger.dequeue();
			return p;
			}
			else{
				return nullptr;
			}
		}

		void gnextStation(int lastStation) {
			if(nextStation==lastStation){
				direction=1;
			}
			if(nextStation==1){
				direction=0;
			}
			if(direction==0)nextStation ++;
			else nextStation--;
    	}
		
		
};


