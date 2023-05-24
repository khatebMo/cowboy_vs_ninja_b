#pragma once
#include <string>

namespace ariel
{
}
using namespace std;
class Point
{
private:
    double Pointx;
    double Pointy;

public:
    // const
    Point();
    Point(double pointx, double pointy);
    //~Point();
    double gitX();
    double gitY();
    void setX(double pointx){this->Pointx=pointx;}
    void setY(double pointy){this->Pointy=pointy;}

    // help functions
    string toString();
    double distance(const Point &other) const;
    void print();
    static Point moveTowards(Point source, Point destination, double dist);
};