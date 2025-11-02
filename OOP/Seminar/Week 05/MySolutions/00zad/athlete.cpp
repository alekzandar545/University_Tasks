#include "athlete.h"


Athlete::Athlete(){
    name = nullptr;
    team = nullptr;
    stamina = 1;
    speed = 1;
    strength = 1;
    sport = Athlete::Sport::BASKETBALL;
    trauma = false;
}
Athlete::Athlete(char* const name, char* const team, bool trauma, unsigned char const stamina, unsigned char const speed, unsigned char const strength, Sport const sport){
    this->name = name;
    this->team = t;
    this->stamina = 1;
    this->speed = 1;
    this->strength = 1;
    this->sport = Athlete::Sport::BASKETBALL;
    this->trauma = false; 
}
Athlete::~Athlete(){
    delete[] name;
    delete[] team;
}