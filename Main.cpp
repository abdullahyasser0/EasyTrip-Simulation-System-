#include "Company.h"
using namespace std;
#include "stations.h"

//last time working 

int main() {
Company BusProject;
BusProject.printEvent();

StationsDLL<int> S1;

S1.addStationsByNumber(5);

S1.display();

    return 0;
}