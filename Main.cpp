#include "UI.h"
//#include "UI.h"


using namespace std;
int main() {
// //     // Company BusProject;
// //     //UI ui;

    Passenger p(string passengerType, int id, int hours, int mins, int startstation, int endStation, int OnoffTime, string priority);


    Passenger* p1 = new Passenger("NP", 1, 10, 30, 1, 5, 10, "AGED");
    p1->setPriority(0);
    Passenger* p2 = new Passenger("WP", 2, 10, 31, 2, 3, 10, "AGED");
    p2->setPriority(0);
    Passenger* p3 = new Passenger("SP", 3, 10, 32, 4, 6, 10, "AGED");
    p3->setPriority(0);
    Bus b("WBus", 20, 10);
    b.getPassOn(p1);
    b.getPassOn(p2);
    b.getPassOn(p3);
    b.moving_passenger.printQueue();
    cout << endl;
    b.getPassOff();
    // b.getPassOff();
    b.moving_passenger.printQueue();
return 0;

}