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
    char current = str[0];
    int count = 1;
    size_t totalCount = 1;
    size_t index = 0;
    while(str[index + 1] != '\0'){
        if(current == str[index + 1]){
            count++;
        }
        else if(count > 3){
            totalCount+=4;
            current = str[index+1];
            count = 1;
            index++;
            continue;
        }
        else{
            totalCount++;
            current = str[index+1];
            count = 1;
        }
        index++;
    }
    if(count > 3){
            totalCount += 4;
    }
    char* output = new(std::nothrow) char[totalCount];
    if(!output){
        std::cout << "Memory error!";
        return 0;
    }
    //after we found the size we insert the char values
    size_t outputIndex = 0;
    current = str[0];
    count = 1;
    index = 0;
    while(str[index + 1] != '\0'){
        if(current == str[index + 1]){
            count++;
        }
        else if(count > 3){
            output[outputIndex] = '(';
            output[outputIndex + 1] = '0' + count;
            output[outputIndex + 2] = char(current);
            output[outputIndex + 3] = ')';
            outputIndex +=4;
            current = str[index+1];
            count = 1;
            index++;
            continue;
        }
        else{
            output[outputIndex] = (char)current;
            outputIndex++;
            current = str[index+1];
            count = 1;
        }
        index++;
    }
    if(count > 3){
            output[outputIndex] = '(';
            output[outputIndex + 1] = '0' + count;
            output[outputIndex + 2] = char(current);
            output[outputIndex + 3] = ')';
            outputIndex+=4;
    }
    output[outputIndex] = '\0';
    std::cout << output;
    delete[] output;
}