#include "file.h"
#include <string>

File::File(std::string name, std::string content) : content(content){this->name = name;}

std::string File::getName() const{
    return this->name;
}

unsigned File::getSize() const{
    return this->content.length();
}

unsigned File::getFilesCount() const{
    return 1;
}

void File::display(int indent = 0) const{
    for (size_t i = 0; i < indent; i++)
    {
        std::cout << "  ";
    }
    std::cout << name << '\n';
}
