#pragma once
#include<iostream>
using namespace std;
#include "stations.h"



class Bus {
    public:
		string BusType;
        int capacity;
        int maintenance;
        int currentStation;

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
		
		Bus creatNBus(){
			Bus bus("Normal",13, 0);
			return bus;
		}

        Bus creatWBus(){
			Bus bus("Wheel",13, 0);
			return bus;
		}


        void create_bus();
   
    private:


};


