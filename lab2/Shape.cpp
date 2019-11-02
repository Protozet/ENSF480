//shape.cpp
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include "Shape.h"
#include "Point.h"
using namespace std;

Shape::~Shape(){
    delete shapeName;
}

void Shape::display()const{
    cout<<endl<<"Shape Name: "<<shapeName;
    this->origin.display();
}

double Shape::distance(const Shape& other)const{
    double ans = Point::distance(this->origin, other.origin);
    return ans;
}

int main(){
    Point p(2.0, 2.0);
    
    Shape s (p, "YUHH");
    s.display();
    return 0;
}

