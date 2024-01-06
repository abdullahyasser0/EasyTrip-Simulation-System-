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
		int currentStation;
		int direction; //0>>forward  ,, 1>>backword 
		int movingMins;// bus progress 
		int STSmins; //station to station mints 
		PriorityQueue<Passenger> moving_passenger;

public:
		
        Bus(){
			BusType = "NULL";
			maxcapacity = 20;
			maintenance = 0;
			nextStation = 1;
			direction=0;
			movingMins=0;
			STSmins=0;
			currentStation=0;
        }

		Bus (string type, int cap , int maint, int STS){
			BusType = type;
			maxcapacity = cap;
			maintenance = maint;
			nextStation = 1;
			direction=0;
			movingMins=0;
			STSmins=STS;
			currentStation=0;
		}
		int getCurrentStation(){
			return currentStation;
		}
		void setCurrentStation(int x){
			currentStation=x;
		}

		PriorityQueue<Passenger> getInBusPass(){
			return moving_passenger;
		}
		int getNextStation(){
			return nextStation;
		}
		int getMovingmins(){
			return movingMins;
		}
		void setNextStation(int x){
			nextStation=x;
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
		int getDirection(){
			return direction;
		}
     	void print_bus_info() {
    		cout << "Bus type : " << BusType << endl;
    		cout << "Bus capacity : " << maxcapacity << endl;
    		cout << "Bus maintenance : " << maintenance << endl;
			cout << "Bus current station : " << currentStation << endl;
			cout << "Bus next Station  : " << nextStation << endl;
			cout << "Bus direction  : " << direction << endl;
			cout<<"imprinting what inside mee "<<endl;
			moving_passenger.printQueue();
			}
		

		template<typename T>
		void getPassOn(T* p){
			moving_passenger.enqueueInsideBus(p);
			maxcapacity--;
		}

		
		void setDirection(int x){
			direction=x;
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
				currentStation++;
				nextStation--;
				return;
			}
			else if(nextStation==1){
				direction=0;
				currentStation--;
				nextStation++;
				return;
			}

			if(direction==0){nextStation ++; currentStation++;}
			else {nextStation--;currentStation--;}
    	}
		
		
};


