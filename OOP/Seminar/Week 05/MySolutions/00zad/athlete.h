#pragma once

class Athlete{
public:
    enum class Sport{
        FOOTBALL,
        BASKETBALL,
        VOLEYBALL,
        TENNIS
    };
    Athlete();
    Athlete(char* const name, char* const team, bool trauma, unsigned char const stamina, unsigned char const speed, unsigned char const strength, Sport const sport);
    ~Athlete();

private:
    char* name;
    char* team;
    bool trauma;
    unsigned char stamina, speed, strength;
    Sport sport;
};


