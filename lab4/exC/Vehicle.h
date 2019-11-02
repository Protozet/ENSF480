#include <string>
#include "Moveable.h"

class Vehicle : public Resizable, public Moveable{
    protected:
        std::string name;
    public:
        Vehicle(std::string name);
        void move();
};