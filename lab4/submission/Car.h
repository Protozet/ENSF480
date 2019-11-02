#include "Vehicle.h"

class Car: public Vehicle{
    private:
        int seats;
    public:
        Car(int seats);
        void turn();
}