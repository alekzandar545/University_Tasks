#include <iostream>
#include <fstream>

struct line{
    unsigned count = 0;
    unsigned num = 1;
};

int main(){
    //Задача 3: Да се напише програма, която намира поредния номер на най-късия и най-дългия ред в даден текстов файл.
    std::ifstream file("03zad.txt");
    if(!file.is_open()){
        std::cout << "Big error!";
        return -1;
    }
    line maxLine;
    maxLine.count = 0;
    line minLine;
    minLine.count = UINT32_MAX;
    line currentLine;
    while(!file.eof()){
        char current;
        current = file.get();
        if(current == '\n'){

            if(currentLine.count > maxLine.count){
                maxLine = currentLine;
            }
            if(currentLine.count < minLine.count){
                minLine = currentLine;
            }
            currentLine.count = 0;
            currentLine.num++;
            continue;
        }
        currentLine.count++;
    }
    std::cout << maxLine.num << ' ' << maxLine.count << '\n';
    std::cout << minLine.num << ' ' << minLine.count << '\n';
    
    file.close();
    return 0;
}