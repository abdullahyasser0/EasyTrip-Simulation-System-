#include"stations.h"



template<typename T>
Stations<T>::Stations() {
    size = 0;
    list = nullptr;
}

template<typename T>
Stations<T>::Stations(int size){
    list = new Nodestation<T>[size+1];
}
template<typename T>
void Stations<T>::addStationsByNumber(int numberOfStations)
{
    Nodestation<T>* newArray=new Nodestation<T>[numberOfStations+1]{};
    delete[] list;
    list=newArray;
    size=numberOfStations+1;
    for (int i =0;i<=numberOfStations;i++){
        list[i].setSnumber(i);
    }
}

template<typename T>
void Stations<T>::display(int size){
    for(int i=0;i<size;i++){
        list[i].Snumber=i;
        cout<<list[i].Snumber<<endl;
    }
}
template<typename T>
void Stations<T>::PrintAllStations(int size) 
{
    for (int i=0;i<size;i++)
    {
        list[i].PrintStationInfo();
    }
}
template<typename T>
void Stations<T>::addPassenger(Passenger* passenger){
    int startStation = passenger->getStartStation();
    string passengerType = passenger->getType();
    int passDrection = passDirection(passenger);
    
    if (passengerType == "NP") {
        if(passDrection==0) list[startStation].getNP()->Insert(passenger);
        else list[startStation].getBNP()->Insert(passenger);
    } else if (passengerType == "WP") {
        if(passDrection==0) list[startStation].getWP()->enqueue(passenger);
        else list[startStation].getBWP()->enqueue(passenger);
    }else if (passengerType == "SP") {
        if(passDrection==0) list[startStation].getSP()->enqueue(passenger);
        else list[startStation].getBSP()->enqueue(passenger);        
        }

}
template<typename T>

void Stations<T>::storeNBus(Bus* bus)
{
    list[0].getNgarage()->enqueue(bus);
}
template<typename T>
void Stations<T>::storeWBus(Bus* bus)
{
        list[0].getWgarage()->enqueue(bus);
}

template<typename T>
int Stations<T>::passDirection(Passenger* passenger){
    int start = passenger->getStartStation();
    int end = passenger->getEndStation();
    if ((end-start)>0) return 0;
    else return 1;
}
template<typename T>
void Stations<T>::RemovePassenger(Passenger* passenger, int stationNumber){ // This function is used for the leave evvent
    int passDrection = passDirection(passenger);
    //int startStation = passenger->getStartStation();
    if(passDrection==0) list[stationNumber].getNP()->RemovePassenger(passenger);
    else list[stationNumber].getBNP()->RemovePassenger(passenger);
}
template<typename T>
int Stations<T>::getStationSize(){
    return size;
}