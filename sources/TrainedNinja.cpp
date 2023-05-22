#include"TrainedNinja.hpp"
#include"Character.hpp"
namespace ariel{}
TrainedNinja::TrainedNinja(string name,const Point &location):Ninja(name,location){
    this->setHp(120);
    this->setSpeed(12);
}

