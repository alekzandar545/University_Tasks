#include <iostream>
#include <fstream>

bool IsLetter(char c){
    return (c >= 'a' && c <='z') || (c >= 'A' && c <='Z') || (c >= 0 && c <=9);
}

int main(){
     std::ifstream file("01zad.txt", std::ios::in);
     if(!file.is_open()){
        std::cout << "Error!";
        return -1;
     }
    int counter = 0;
    char check = file.get();
    if(IsLetter(check))
        counter++;
    while(!file.eof()){
        std::cout << file.tellg() << ' ';
        check = file.get();
        //std::cout << check;
        if((check == ' ' || check == '\n') && IsLetter(file.peek()))
            counter++;
    }
    std::cout << counter;
    file.close();

    return 0;
}