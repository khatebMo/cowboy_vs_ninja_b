#include"OldNinja.hpp"
#include"Character.hpp"
namespace ariel{}
OldNinja::OldNinja(string name,const Point &location):Ninja(name,location){
    this->setHp(150);
    this->setSpeed(8);
}
