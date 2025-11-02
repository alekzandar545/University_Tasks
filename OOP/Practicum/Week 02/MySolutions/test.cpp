#include <iostream>
#include <fstream>

int main(){
    std::fstream file("test.txt");
    if(!file.is_open()){
        std::cout << "Error!";
        return -1;
    }
    char curr;
    file.seekg(0);
    while(file.get(curr)){
        int pos = file.tellp();
        file.seekp(1, std::ios::cur);
        file.seekp(-1, std::ios::cur);
        std::cout << pos << ' ';
    }

    file.close();
    return 0;
}