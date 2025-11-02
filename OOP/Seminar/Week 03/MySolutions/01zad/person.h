#pragma once

namespace Person
{
    struct Person
    {
        enum class Gender{
            Male, Female, Unknown
        };
        unsigned age;
        Gender gender;
        char* name;
        //init
        void InitPerson(char* name, unsigned age, Person::Gender gender);
        //delete
        void DeletePerson();
        //speakr
        void Speak(char* quote);
        void PrintInfo();
        //setters
        void SetName(const char* name);
    };
    //init
    Person InitPerson(char* name, unsigned age, Person::Gender gender);
    //delete
    void DeletePerson(Person person);
    //speakr
    void Speak(char* quote);
    void PrintInfo(Person person);
    //setters
    void SetName(Person person, const char* name);
}


