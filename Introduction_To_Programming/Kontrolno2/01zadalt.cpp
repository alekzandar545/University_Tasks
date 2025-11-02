#include <iostream>

int main(){
    /*Задача 1: 20т.
    Реализирайте функция, която компресира текст, съставен от малки латински букви, посредством RLE алгоритъм и връща получения 
    резултат в динамично заделен низ с точната големина. RLE е компресия, при която еднаквите символи се заменят с число и 
    съответния символ в скоби. За да има смисъл се заменят поне четири последователни еднакви символа. 
    Демонстрирайте използването на функцията в примерна програма.

    Вход:					Изход:
    аbcdddddaaaaaaabccadddd		abc(5d)(7a)bcca(4d)*/
    char str[1024];
    std::cin.getline(str, 1024);
    //we compress repeating symbols huh //only single symbols :)
    //std::cout << str;
    int current = str[0];
    int count = 1;
    int totalCount = 1;
    int index = 0;
    while(str[index + 1] != '\0'){
        if(current == str[index + 1]){
            count++;
        }
        else if(count > 3){
            std::cout << '(' << count << (char)current <<')';
            totalCount+=4;
            current = str[index+1];
            count = 1;
            index++;
            continue;
        }
        else{
            std::cout << (char)current;
            totalCount++;
            current = str[index+1];
            count = 1;
        }
        index++;
        //std::cout << totalCount << '\n';
    }
    //std::cout << count;
    if(count > 3){
            std::cout << '(' << count << (char)current <<')';
            totalCount += 4;
    }
    char* output = new(std::nothrow) char[totalCount];
    if(!output){
        std::cout << "Memory error!";
        return 0;
    }
    
    delete[] output;
}