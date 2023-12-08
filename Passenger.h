#include<iostream>
using namespace std;
class Passenger
{
private:
	int ID;
	int Hours, Minutes;
	int startStation, endStation;
	int OnOffTime;
	string priority;
public:
	Passenger(int id, int hours, int mins, int startStation, int endStation, int OnoffTime, string& priority)
		: ID(id), Hours(hours),Minutes(mins), startStation(startStation), endStation(endStation), OnOffTime(OnoffTime), priority(priority)
	{
	}
};