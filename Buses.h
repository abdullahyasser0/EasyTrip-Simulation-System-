#pragma once
#include<iostream>
using namespace std;
class Buses
{
private:
		string busType;
		int busCapacity;
		int maintenanceTime;
	public:
		Buses(string& type, int capacity, int maintenance)
			: busType(type), busCapacity(capacity), maintenanceTime(maintenance)
		{
		}
		string getBusType() {
			return busType;
		}
		int getBusCapacity() {
			return busCapacity;
		}
	int getMaintenanceTime()
	{
		return maintenanceTime;
	}
};