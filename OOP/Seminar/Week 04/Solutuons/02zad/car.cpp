#include "car.h"
#include <iostream>

//getters
unsigned car::getPower() const{
    return this->power;
}
unsigned car::getGas() const{
    return this->gas;
}
unsigned car::getDistance() const{
    return this->distance;
}
//setters
void car::setPower(unsigned value){
    if(value < 0){
        std::cout << "rip accumulator";
        return;
    }
    else if(value > 150){
        std::cout << "Engine too powerful!";
        return;
    }
    this->power = value;
}
void car::setGas(unsigned value){
    if(value > 100){
        std::cout << "Full tank!";
        return;
    }
    else if(value < 0){
        std::cout << "Not enough fuel!";
        return;
    }
    this->gas = value;
}
void car::setDistance(unsigned value){
    //distance can be negative in the sence that the car may be going backwards
    this->distance = value;
}
//methods
void car::fill(){
    this->setGas(100);
}
void car::drive(unsigned distance){
    unsigned oldGas = this->gas;
    this->setGas(this->gas - distance*(this->power/15)/100*this->gas);
    //travel distance only if there is enough fuel
    if(this->gas != oldGas)
        this->setDistance(this->distance + distance);
}
void car::upgrade(){
    this->setPower(this->power + 15);
}
