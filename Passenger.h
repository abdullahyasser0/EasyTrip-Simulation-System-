#include<iostream>
using namespace std;
class Passenger
{
private:
	int ID;
	string arrivalTime;
	int startStation, endStation;
	int getOn, getOff;
	string priority;
public:
	Passenger(int id, string& arrivalTime, int startStation, int endStation, int getOn, int getOff, string& priority)
		: ID(id), arrivalTime(arrivalTime), startStation(startStation), endStation(endStation), getOn(getOn), getOff(getOff), priority(priority)
	{
	}
};