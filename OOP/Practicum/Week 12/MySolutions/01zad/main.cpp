#include <iostream>
#include "file.h"
#include "directory.h"
int main(){
    Directory dir1("dir1");
    Directory* dir2 = new Directory("dir2");
    File* f1 = new File("f1", "PetarCHo");
    File* f2 = new File("f2", "Gosho");
    dir1.addEntity(f1);
    dir1.addEntity(f2);
    dir2->addEntity(f2);
    dir2->addEntity(f1);
    dir1.addEntity(dir2);
    //std::cout << f1->getSize();
    std::cout << dir1.getSize() << '\n' << dir1.getFilesCount() << '\n' << dir1.find("f1")<< '\n' << dir1.find("f2") << '\n';
    dir1.display(0);
}