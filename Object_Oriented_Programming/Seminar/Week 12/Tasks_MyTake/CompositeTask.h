#include<iostream>
#include<string>
#include "SimpleTask.h"

class CompositeTask : public SimpleTask{
private:
    SimpleTask** tasks;
    unsigned size;
    unsigned capacity;

    void copy(const CompositeTask& other){
        this->name = other.name;
        this->time = other.time;
        this->size = other.size;
        this->capacity = other.capacity;
        tasks = new SimpleTask*[capacity];
        for (size_t i = 0; i < size; i++)
            tasks[i] = other.tasks[i]->Clone();       
    }

    void move(CompositeTask&& other){
        this->name = other.name;
        this->time = other.time;
        this->capacity = other.capacity;
        this->size = other.size;
        this->tasks = other.tasks;

        other.name = ' ';
        other.time = 0;
        other.size = 0;
        other.capacity = 0;
        other.tasks = nullptr;
    }
    void free(){
        for (size_t i = 0; i < size; i++)
        {
            delete tasks[i];
        }
        delete[] tasks;
    }
    void resize(){
        SimpleTask** temp = new SimpleTask*[capacity*2];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = tasks[i];
        }
        delete[] tasks;
        tasks = temp;
    }
    class Iterator{
    private:
        SimpleTask** ptr;
        friend class CompositeTask;
    public:
        explicit Iterator(SimpleTask** ptr){
            this->ptr = ptr;
        }
        SimpleTask* operator*(){return *ptr;}
        const SimpleTask* operator*() const{return *ptr;}
        SimpleTask** operator->(){return ptr;}
        Iterator& operator++(){ptr++; return *this;}
        Iterator operator++(int){
            Iterator* old = new Iterator(this->ptr);
            ptr++; 
            return *old;
        }
        Iterator& operator--(){ptr--; return *this;}
        Iterator operator--(int){
            Iterator* old = new Iterator(this->ptr);
            ptr--; 
            return *old;
        }
        bool operator==(Iterator other){return ptr == other.ptr;}
        bool operator!=(Iterator other){return ptr!= other.ptr;}
    };
    Iterator begin() const{
        return Iterator(tasks);
    }
    Iterator end() const{
        return Iterator(tasks + size);
    }
public:
    CompositeTask() : SimpleTask(){
        size = 0;
        capacity = 10;
        tasks = new SimpleTask*[capacity];
    }
    CompositeTask(std::string name) : SimpleTask(name){
        size = 0;
        capacity = 10;
        tasks = new SimpleTask*[capacity];
    }
    CompositeTask(const CompositeTask& other){
        copy(other);
    }
    CompositeTask(CompositeTask&& other){
        move(std::move(other));
    }
    ~CompositeTask(){
        free();
    }
    CompositeTask& operator=(const CompositeTask& other){
        if(this != &other){
            free();
            copy(other);
        }
        return *this;
    }
    CompositeTask& operator=(CompositeTask&& other){
        if(this != &other){
            free();
            move(std::move(other));
        }
        return *this;
    }

    void AddTask(SimpleTask* task){
        if(size+1 >= capacity)
            resize();
        tasks[size++] = task;
    }

    void Print() const override{
        //std::cout << name << '\n';
        for (SimpleTask* task : *this)
        {
            task->Print();
        }
    }
    unsigned GetTime() const override{
        unsigned time = 0;
        for (SimpleTask* task : *this)
        {
            time += task->GetTime();
        }
        return time;
    }
    SimpleTask* Clone() const override{
        CompositeTask* task = new CompositeTask(*this);
        return (SimpleTask*)task;
    }
};