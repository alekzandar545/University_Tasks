#include <iostream>
#include <fstream>

int main(){
    std::fstream file("text.txt", std::ios::binary | std::ios::in | std::ios::out);
    if(!file.is_open()){
        std::cout << "Error";
        return -1;
    }
    char current;
    size_t putPointer = 0, getPointer = 0;
    while(file.read((char*)&current, sizeof(char))){
        file.seekg(putPointer);
        file.write((char*)&current, sizeof(char));

        if(current !=' ')
            putPointer++;
        getPointer++;
        file.seekg(getPointer);
        std::cout << getPointer << ' ' << putPointer << '\n';
    }
    //clear excess
    file.clear();
    file.seekg(putPointer);
    char fill = ' ';
    while(putPointer!=getPointer){
        file.write((char*)&fill, sizeof(char));
        putPointer++;
    }
    file.close();
}