#include <iostream>
#include <fstream>


int main(){
    std::ifstream f("functions1.cpp");
    if(!f.is_open()){
        std::cout << "file didnt open!" << std::endl;
    }
    int counter = 0;
    char ch;
    while(f.good()){
        f.get(ch);
        if(ch == '\n')
            counter++;
    }
    std::cout << counter;


    f.close();
    return 0;
}