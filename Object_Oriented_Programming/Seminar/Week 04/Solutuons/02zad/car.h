#pragma once

class car
{
private:
    unsigned power = 90,
             gas = 0;
    int distance = 0;
public:
    //getters
    unsigned getPower() const;
    unsigned getGas() const;
    unsigned getDistance() const;
    //setters
    void setPower(unsigned value);
    void setGas(unsigned value);
    void setDistance(unsigned value);
    //methods
    void fill();
    void drive(unsigned distance);
    void upgrade();
};