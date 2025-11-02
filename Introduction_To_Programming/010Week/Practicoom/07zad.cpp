#include <iostream>
#include <cstring>

char* deleteDuplicate(char* str){
    //first we find the size
    int length = strlen(str);
    int newLen = 0;
    int current = 0;
    char results[255];
    char resultIndex = 0;
    for (size_t i = 'a'; i <= 'z'; i++)
    {
        for (size_t j = 0; j < length; j++)
            if(str[j] == i)
                current++;
        if(current == 1){
           newLen++;
           results[resultIndex++] = i;
        }
        current = 0;   
    }
    //the we create the new string and add only unique letters
    char* outputStr = new(std::nothrow) char[newLen + 1];
    if(!outputStr){
        std::cout << "Memory error!";
        return nullptr;
    }
    int outputIndex = 0;
    for(size_t i = 0; i < length; i++)
        for (size_t j = 0; j < strlen(results); j++)
            if(str[i] == results[j])
                outputStr[outputIndex++] = results[j];
    outputStr[newLen] = '\0';
    return outputStr;
    
}
int main(){
    /*Да се напише функция, която получава низ, състоящ се само от малки латински букви, и 
    премахва всички дублиращи се символи. Резултатът от функцията да бъде нов масив, с размер точно 
    дължината на получения низ. Подредбата на символите в първоначалния низ да се запази.*/
    int size;
    std::cin >> size;
    std::cin.ignore();
    char* str = new(std::nothrow) char[size];
    if(!str){
        std::cout << "Memory error!";
        return -1;
    }
    std::cin.getline(str, size - 1);
    //std::cout << str;
    char* newStr = deleteDuplicate(str);
    std::cout << newStr;
    
    delete[] newStr;
    delete[] str;
}