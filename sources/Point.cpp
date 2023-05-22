#include "Point.hpp"
#include <cmath>
#include <iostream>

namespace ariel
{
}
Point::Point(double x, double y) : x(x), y(y)
{
}
double Point::distance(const Point &other) const
{
    double dist;
    double deltaX = this->x - other.x;
    double deltaY = this->y - other.y;
    dist = std::sqrt(deltaX * deltaX + deltaY * deltaY);
    return dist;
}
void Point::print()
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
Point Point::moveTowards(Point source, Point destination, double dist)
{
    if(dist<0){
        throw invalid_argument("the distance can't be nigative");
    }
    double deltaX = destination.x - source.x;
    double deltaY = destination.y - source.y;
    double currentDistance = source.distance(destination);

    if (currentDistance <= dist)
    {
        return destination;
    }

    double ratio = dist / currentDistance;
    double newX = source.x + deltaX * ratio;
    double newY = source.y + deltaY * ratio;
    Point temp(newX, newY);
    return temp;
}

double Point::gitX()
{
    return this->x;
}
double Point::gitY()
{
    return this->y;
}
string Point::toString()
{
    string temp="(" + to_string(x) + ", " + to_string(y) + ")" ;
    return temp;
}