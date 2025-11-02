#pragma once
#include <cstring>
#include <stdexcept>

const unsigned MAX_NAME_LEN = 50;

struct Coord
{
    int x,y;
};

class Player{
private:
    char* name; //max50
    int points;
    Coord coord;

    void copy(const Player& other){
        points = other.points;
        coord = other.coord;
        this->name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    void free(){
        delete[] name;
    }
public:
    //big4
    Player(){
        name = new char[MAX_NAME_LEN];
        points = 0;
        coord = {0,0};
    }
    ~Player(){
        free();
    }
    Player(const Player& player){
        copy(player);
    }
    Player& operator=(const Player& player){
        if(this!=&player){
            free();
            copy(player);
        }
        return*this;
    }
    //setters
    void SetName(const char* name) 
    {
        const unsigned short nameLen = strlen(name);

        if(!name || nameLen >= MAX_NAME_LEN)
        {
            throw std::invalid_argument("Invalid name!");
        }

        delete[] this->name;
        this->name = new char[nameLen + 1];
        strcpy(this->name, name);
    }
    //getters
    //print
};