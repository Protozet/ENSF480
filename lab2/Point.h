// class Point
// Shamin Rahman

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <iomanip>
using namespace std;

class Point{
    private:
        int id;
        double x;
        double y;

    public:
        Point(double xCoord, double yCoord): x(xCoord), y(yCoord){}
        
        void display()const{
            cout<<fixed;
            cout<<setprecision(2);
            cout<<endl<<"X-coordinate: "<<x<<endl;
            cout<<"Y-coordinate: "<<y<<endl;
        }
        Point& operator =(const Point& rhs);
        double distance(const Point& other)const;
        static double distance(const Point& first, const Point& second);
        double getX()const{return x;}
        double getY()const{return y;}
        void setY(double yCoord){y = yCoord;}
        void setX(double xCoord){x = xCoord;}
};

#endif