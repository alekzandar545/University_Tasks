#pragma once
#include "entity.h"
#include <string>
#include <vector>
class Directory : public Entity{
private:
    std::vector<Entity*> files;
    class Iterator{
    private://fix
        friend class Directory;
        Entity** pointer;
        explicit Iterator(Entity** pointer): pointer(pointer){}
    public:
        
        Entity& operator*(){return **(this->pointer);}
        const Entity& operator*() const{return **(this->pointer);}
        Entity* operator->(){return *this->pointer;}
        const Entity* operator->() const{return *this->pointer;}
        Iterator& operator++(){ //returns after modification
            this->pointer++;
            return *this;
        }
        Iterator operator++(int){ //returs before altercation => no reference
            Iterator old = *this;
            this->pointer++;
            return old;
        }
        Iterator& operator--(){
            this->pointer--;
            return *this;
        }
        Iterator operator--(int){
            Iterator old = *this;
            this->pointer--;
            return old;
        }
        bool operator==(const Iterator& other) const{return this->pointer == other.pointer;}
        bool operator!=(const Iterator& other) const{return this->pointer != other.pointer;}
    };

public:
    Iterator Begin() const{
        return Iterator((Entity**)(files.data()));
    }
    Iterator End() const{
        return Iterator((Entity**)(files.data() + size()));
    }
    Directory(std::string name){this->name = name;}
    std::string getName() const override;
    unsigned getSize() const override;//size of data in all files in directory
    unsigned getFilesCount() const override; 
    void display(int indent) const override;
    void addEntity (Entity* entity);
    void copy (const Entity*);
    Entity* find(std::string name);
    unsigned size() const;

};