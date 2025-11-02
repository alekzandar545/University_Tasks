#pragma once
#include <iostream>
#include <string>

class Entity{
    protected:
        std::string name;
    public:
        virtual std::string getName() const = 0;
        virtual unsigned getSize() const = 0;
        virtual unsigned getFilesCount() const = 0;
        virtual ~Entity() = default;
        virtual void display(int indent) const = 0;
};