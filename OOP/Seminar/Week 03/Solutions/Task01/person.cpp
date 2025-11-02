#include <iostream>
#include "person.h"
#include <cstring>

namespace Person{

    void Person::InitPerson(char* name, unsigned age, Person::Gender gender){
        SetName(name);
        this->age = age;
        this->gender = gender;
    }

    void Person::SetName(const char* name){
        if(this->name)
            Person::DeletePerson();
        this->name = new(std::nothrow) char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void Person::Speak(char* quote){
        std::cout << this->name << ':' << quote;
    }

    void Person::PrintInfo(){
        std::cout << "Hello i am: " << this->name << ". I am " << this -> age << " years of age. My gender is ";
        switch (this->gender)
        {
        case Gender::Male:
            std::cout << "Male.";
            break;
        case Gender::Female:
            std::cout << "Female.";
            break;
        case Gender::Unknown:
            std::cout << "Unknown";
            break;
        }
    }

    void Person::DeletePerson(){
        delete[] this->name;
        name = nullptr;
    }
    //Patoopa functionsssssssssssssssssssssssssssssssssssssssssssssssssssssss
    Person InitPerson(char* name, unsigned age, Person::Gender gender){
        Person person;
        SetName(person, name);
        person.age = age;
        person.gender = gender;
        return person;
    }

    void SetName(Person person, const char* name){
        if(person.name)
            DeletePerson(person);
        person.name = new(std::nothrow) char[strlen(name) + 1];
        strcpy(person.name, name);
    }

    void Speak(Person person, char* quote){
        std::cout << person.name << ':' << quote;
    }

    void PrintInfo(Person person){
        std::cout << "Hello i am: " << person.name << ". I am " << person.age << " years of age. My gender is";
        switch (person.gender)
        {
        case Person::Gender::Male:
            std::cout << "Male.";
            break;
        case Person::Gender::Female:
            std::cout << "Female.";
            break;
        case Person::Gender::Unknown:
            std::cout << "Unknown";
            break;
        }
    }

    void DeletePerson(Person person){
        delete[] person.name;
        person.name = nullptr;
    }
}
