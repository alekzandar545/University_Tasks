#include <iostream>
#include <cstring>
const size_t maxLen = 255;

char* ReverseStr(char* str, int length){
    char* output = new(std::nothrow) char[length];
    if(!output){
        std::cout << "Memory error!";
        return nullptr;
    }

    for (size_t i = 0; i < length; i++)
    {
        output[i] = str[length - i - 1];
    }
    output[length] = '\0';
    return output;  
}

int main(){
    //Напишете функция ReverseStr, която приема стринг S и връща този стринг наобратно.
    char str[maxLen];
    std::cin.getline(str, 255);
    char* reversed = ReverseStr(str, strlen(str));
    std::cout << reversed;
    
    delete[] reversed;
}