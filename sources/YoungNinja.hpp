#pragma once
#include"Ninja.hpp"
#include"Character.hpp"
namespace ariel{}
class YoungNinja:public Ninja{
    public:
    YoungNinja(string name,const Point &lacation);
    YoungNinja(string name, const Point &location,int speed,int hp):Ninja(name,location,14,100){}
};