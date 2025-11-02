#include <iostream>
#include <fstream>
#include <cstring>

bool ContaintsWord(std::ifstream &file, int index, char word[]){
    for (size_t i = 0; i < strlen(word); i++)
    {   
        file.peek();
        if(file.eof()){
            file.seekg(index);
            return false;
        }

        if(file.get() != word[i]){
            file.seekg(index);
            return false;
        }
    }
    //file.seekg(index);
    return true;
}

int main(){
    //Задача 4: Да се напише програма, която търси определена дума в текстов файл и извежда на
    //екрана броя срещания и съответните редове, на които се среща.
    std::ifstream file("04zad.txt");
    if(!file.is_open()){
        std::cout << "Error";
        return -1;
    }
    char word[] = {"sosko"};
    unsigned occurances = 0;
    unsigned currentLine;

    while(!file.eof()){
        
        if(ContaintsWord(file, file.tellg(), word))
            occurances++;
        char current;
        current = file.get();   
        std::cout << current;
        if(current == '\n'){
            currentLine++;
            continue;
        }
    }
    std::cout << '\n' << occurances;
    file.close();
    return 0;
}