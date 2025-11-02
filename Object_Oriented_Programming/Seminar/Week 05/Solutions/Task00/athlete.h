#pragma once

class Athlete{
public:
    enum class Sport{
        FOOTBALL,
        BASKETBALL,
        VOLEYBALL,
        TENNIS
    };
    //constructors
    Athlete();
    Athlete(char* const name, char* const team, bool const trauma, unsigned char const stamina, unsigned char const speed, unsigned char const strength, Sport const sport);
    ~Athlete();
    //setters
    void SetName(char* const name);
    void SetStamina(unsigned char const value);
    void SetSpeed(unsigned char const value);
    void SetStrength(unsigned char const value);
    //getters
    char* GetName();
    char* GetTeam();
    unsigned char GetStamina();
    unsigned char GetSpeed();
    unsigned char GetStrength();
    Sport GetSport();
    //functionality
    void ChangeTeam(char* const team);
    void Train();
    void Print();

private:
    char* name;
    char* team;
    bool trauma;
    unsigned char stamina, speed, strength;
    Sport sport;
};


