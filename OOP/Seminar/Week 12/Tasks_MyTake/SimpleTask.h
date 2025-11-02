#pragma once
#include <iostream>
#include <string>

class SimpleTask{
public:
    SimpleTask(){
        name = "default";
        time = 0;
    }
    explicit SimpleTask(std::string name){
        this->time = 0;
        this->name = name;
    }
    explicit SimpleTask(unsigned time, std::string name){
        this->time = time;
        this->name = name;
    }
    virtual ~SimpleTask() = default;
    virtual void Print() const{
        std::cout << name << ' ' << time << '\n';
    }
    virtual unsigned GetTime() const{
        return time;
    }
    virtual SimpleTask* Clone() const{
        SimpleTask* task = new SimpleTask(*this);
        return task;
    }

protected:
    unsigned time;
    std::string name;
};