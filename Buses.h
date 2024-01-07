#pragma once
#include<iostream>
#include "dataStructures/LinKedListp.h"
#include "Passenger.h"

#include "dataStructures/PriorityQueue.h"
using namespace std;


class Bus {
    private:
		int BusID;
		string BusType;
		int checkupduration;
		int checkupcounter=0;
        int maxcapacity;
		int currentcapacity;
        int CheckupTrips;
        int nextStation;
		int currentStation;
		int direction; //0>>forward  ,, 1>>backword 
		int movingMins;// bus progress 
		int STSmins; //station to station mints 
		PriorityQueue<Passenger> moving_passenger;
		int journies=0;

public:
		
        Bus(){
			BusType = "NULL";
			maxcapacity = 0;
			currentcapacity=0;
			CheckupTrips = 0;
			nextStation = 1;
			direction=0;
			movingMins=0;
			STSmins=0;
			currentStation=0;
        }

		Bus (int id,string type, int cap , int CheckupTrip, int STS){
			BusType = type;
			maxcapacity = cap;
			currentcapacity=cap;
			CheckupTrips = CheckupTrip;
			nextStation = 1;
			direction=0;
			movingMins=0;
			STSmins=STS;
			currentStation=0;
			BusID=id;
		}
		int getCurrentStation(){
			return currentStation;
		}
		void setCurrentStation(int x){
			currentStation=x;
		}

		int getBusID(){
			return BusID;
		}

		void setCheckuptripsAndDuration(int x,int y){
			CheckupTrips=x;
			checkupduration=y;	
		}

		bool finishCheckup(){
			if(checkupcounter!=checkupduration){
				checkupcounter++;
				return false;
			}
			else{
				checkupcounter=0;
				return true;
			}
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
			return currentcapacity;
		}

		bool isFull(){
			return currentcapacity==0;
		}

		bool Checkup(){
			return journies==CheckupTrips;
		} 

		int getDirection(){
			return direction;
		}
     	void print_bus_info() {
    		cout << "Bus type : " << BusType << endl;
    		cout << "Bus capacity : " << maxcapacity << endl;
    		cout << "Bus maintenance : " << CheckupTrips << endl;
			cout << "Bus current station : " << currentStation << endl;
			cout << "Bus next Station  : " << nextStation << endl;
			cout << "Bus direction  : " << direction << endl;
			cout<<"imprinting what inside mee "<<endl;
			moving_passenger.printQueue();
			}
		

		template<typename T>
		// void getPassOn(T* p){
		// 	moving_passenger.enqueueInsideBus(p);    //modified
		// 	maxcapacity--;
		// }


		void getPassOn(T* p){
			if (direction==0){
			moving_passenger.enqueueInsideBus(p);
			maxcapacity--;
			}
		}

		
		void setDirection(int x){
			direction=x;
		}
		Passenger* getPassOff() {
			if(!moving_passenger.isEmpty()){
			Passenger *p = moving_passenger.dequeue();
			currentcapacity++;
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
				journies++;
				return;
			}
			else if(nextStation==1){
				direction=0;
				currentStation--;
				nextStation++;
				journies++;
				return;
			}

			if(direction==0){nextStation ++; currentStation++;}
			else {nextStation--;currentStation--;}
    	}
		
		
};


