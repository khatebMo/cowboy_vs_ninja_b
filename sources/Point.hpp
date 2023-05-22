#pragma once
#include <string>

namespace ariel
{
}
using namespace std;
class Point
{
private:
    double x;
    double y;

public:
    // const
    Point(double x, double y);
    //~Point();
    double gitX();
    double gitY();

    // help functions
    string toString();
    double distance(const Point &other) const;
    void print();
    static Point moveTowards(Point source, Point destination, double dist);
};