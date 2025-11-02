#include <iostream>
#include <fstream>

int lastIndex(std::fstream &file){
    int curr = file.tellg();
    file.seekg(0, std::ios::end);
    int output = file.tellg();
    file.seekg(curr);
    return output;
}

void MoveBack(std::fstream &file,const unsigned offset,const char ch,const int start){
    file.seekp(start - offset);
    //std::cout << ' ' << start << ' ';
    file << ch;
    file.seekp(start);
}

void DeleteAt(std::fstream &file, unsigned index){
    file.seekg(index);
    file << ' ';
}

int main(){
    /*Задача 2: Да се напише програма, която изтрива всички интервали от даден текстов файл. 
    За целта да не се използва помощен файл и да не се зарежда цялото съдържание на файла в паметта.*/
    std::fstream file("02zad.txt");
    if(!file.is_open()){
        std::cout << "Error";
        return -1;
    }
    unsigned offset = 0;        

    while(!file.eof()){

        //get current element
        int pos = file.tellp();
        char current;
        current = file.peek();
        file.seekg(pos);
        std::cout << current << pos << ' ';
        //MoveBack(file, offset, current, pos);
        file.seekp(pos - offset);
        //std::cout << ' ' << start << ' ';
        //file << current;
        file.seekp(pos);
        if(current == ' '){
            offset++;
        }
        //move
        file.get();
        file.peek();
    }
    //remove stuff at end
    /*for (size_t i = 0; i < offset; i++)
    {
        DeleteAt(file, last-=1);
    }*/
    
    file.close();
    return 0;
}