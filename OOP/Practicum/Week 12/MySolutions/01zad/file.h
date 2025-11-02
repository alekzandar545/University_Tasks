#pragma once
#include "entity.h"
#include <string>

class File: public Entity{
private:
    std::string content;
public:
    File(std::string name, std::string content);
    std::string getName() const override;
    unsigned getSize() const override; //number of symbols in file
    unsigned getFilesCount() const override;
    void display(int indent) const override;
};