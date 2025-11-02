#include "athlete.h"
#include <iostream>
#include <cstring>

//constructors
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
    SetName(name);
    ChangeTeam(team);
    this->stamina = stamina;
    this->speed = speed;
    this->strength = strength;
    this->sport = sport;
    this->trauma = trauma; 
}
Athlete::~Athlete(){
    delete[] name;
    delete[] team;
}

//setters
void Athlete::SetName(char* const name){
    if(this->name)
        delete[] name;
    this->name = new(std::nothrow) char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Athlete::SetStamina(unsigned char const value){
    if(value < 1){
        std::cout << "Stamina too low!";
    }
    else if(value > 5){
        std::cout << "Cannot get more stamina!";
    }
    this->stamina = value;
}
void Athlete::SetSpeed(unsigned char const value){
    if(value < 1){
        std::cout << "Speed too low!";
    }
    else if(value > 5){
        std::cout << "Cannot get more speed!";
    }
    this->speed = value;
}
void Athlete::SetStrength(unsigned char const value){
    if(value < 1){
        std::cout << "Strength too low!";
    }
    else if(value > 5){
        std::cout << "Cannot get more strength!";
    }
    this->strength = value;
}
//getters
char* Athlete::GetName(){
    return this->name;
}
char* Athlete::GetTeam(){
    return this->team;
}
unsigned char Athlete::GetStamina(){
    return this->stamina;
}
unsigned char Athlete::GetSpeed(){
    return this->speed;
}
unsigned char Athlete::GetStrength(){
    return this->strength;
}
Athlete::Sport Athlete::GetSport(){
    return this->sport;
}
//functionality
void Athlete::ChangeTeam(char* const team){
    if(this->team)
        delete[] team;
    this->name = new(std::nothrow) char[strlen(team) + 1];
    strcpy(this->team, team);
}
void Athlete::Train(){
    if(!this->trauma){
        this->SetSpeed(this->speed + 1);
        this->SetStamina(this->stamina + 1);
        this->SetStrength(this->strength + 1);
    }
    else{
        std::cout << "Cannot train cus of injury!";
    }
}
void Athlete::Print(){
    std::cout << "Name: " << this->name << "\nTeam: " << this->team << "\nInjury: " << std::boolalpha << this->trauma <<
    "\n Stamina" << this-> stamina << "\nSpeed: " << this->speed <<"\nStrength" << this->strength << '\nSport: ';
    switch (this->sport)
    {
    case Sport::BASKETBALL:
        std::cout << "Basketball";
        break;
    case Sport::FOOTBALL:
        std::cout << "Football";
        break;
    case Sport::TENNIS:
        std::cout << "Tennis";
        break;
    case Sport::VOLEYBALL:
        std::cout << "Volleyball";
        break;    
    default:
        break;
    }
}