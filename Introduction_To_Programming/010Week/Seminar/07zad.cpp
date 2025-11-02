#include <iostream>
#include <cstring>

void SetNewWord(int length, char* currStr, char* outputStr){
    for (size_t i = 0; i < length; i++)
    {
        outputStr[i] = currStr[i];
    }
    outputStr[length] = '\0';    
}

int main(){
    //Задача 7 Да се напише програма, която приема низ и намира най-късата и най-дългата дума в него.    
    char str[255];
    std::cin.getline(str, 254);
    int longestLen = 0;
    int shortestLen = INT32_MAX;
    char longestWord[255];
    char shortestWord[255];
    while(strchr(str, ' ')){
        int substringLen = strlen(strchr(str, ' '));
        int wordLength = strlen(str) - substringLen;
        if(wordLength > longestLen){
            longestLen = wordLength;
            SetNewWord(longestLen, str, longestWord);
        }
        if(wordLength < shortestLen){
            shortestLen = wordLength;            
            SetNewWord(shortestLen, str, shortestWord);            
        }
        strcpy(str,strchr(str, ' ') + 1);
    }
    //gotta check the last word
    if(strlen(str) > longestLen){
        longestLen = strlen(str);
        SetNewWord(longestLen, str, longestWord);       
    }

    if(strlen(str) < shortestLen){
        shortestLen = strlen(str);  
        SetNewWord(shortestLen, str, shortestWord);   
    }
   
    //std::cout << shortestLen << '\n' << longestLen << '\n';
    std::cout << shortestWord << '\n' << longestWord;
}