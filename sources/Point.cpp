#include "Point.hpp"
#include <cmath>
#include <iostream>

namespace ariel
{
}
    Point::Point()
    {
        Pointx=0;
        Pointy=0;
    }

Point::Point(double x, double y) : Pointx(x), Pointy(y)
{
}
double Point::distance(const Point &other) const
{
    double dist;
    double deltaX = this->Pointx - other.Pointx;
    double deltaY = this->Pointy - other.Pointy;
    dist = std::sqrt(deltaX * deltaX + deltaY * deltaY);
    return dist;
}
void Point::print()
{
    std::cout << "(" << Pointx << ", " << Pointy << ")" << std::endl;
}
Point Point::moveTowards(Point source, Point destination, double dist)
{
    if(dist<0){
        throw invalid_argument("the distance can't be nigative");
    }
    double deltaX = destination.Pointx - source.Pointx;
    double deltaY = destination.Pointy - source.Pointy;
    double currentDistance = source.distance(destination);

    if (currentDistance <= dist)
    {
        return destination;
    }

    double ratio = dist / currentDistance;
    double newX = source.Pointx + deltaX * ratio;
    double newY = source.Pointy + deltaY * ratio;
    Point temp(newX, newY);
    return temp;
}

double Point::gitX()
{
    return this->Pointx;
}
double Point::gitY()
{
    return this->Pointy;
}
string Point::toString()
{
    string temp="(" + to_string(Pointx) + ", " + to_string(Pointy) + ")" ;
    return temp;
}