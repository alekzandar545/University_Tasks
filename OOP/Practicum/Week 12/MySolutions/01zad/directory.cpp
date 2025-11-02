#include "directory.h"
#include <vector>
#include <string>
#include <cstring>

std::string Directory::getName() const{
    return this->name;
}
unsigned Directory::getSize() const{
    unsigned size = 0;
    for(auto it : this->files){
        size += (*it).getSize();
    }
    return size;
}

unsigned Directory::getFilesCount() const{
    int count = 0;
    for(Iterator it = this->Begin(); it!= this->End(); it++){
        count+= (*it).getFilesCount();
    }
    return count;
}
void Directory::display(int indent = 0) const{
    for (size_t i = 0; i < indent; i++)
    {
        std::cout << "  ";
    }
    
    std::cout << name << '\n';
    indent ++;
    for (Iterator it = this->Begin(); it != this->End(); it++)
    {
        it->display(indent);
    }
}
void Directory::addEntity(Entity* entity){
    this->files.push_back(entity);
}

void Directory::copy(const Entity* entity){

}
Entity* Directory::find(std::string name){
    Entity* output = nullptr;
    for (Iterator it = this->Begin(); it !=this->End(); it++)
    {
        if(it->getName()==name)
            output = *it.pointer;
    }
    return output;
}
unsigned Directory::size() const{
    return this->files.size();
}
