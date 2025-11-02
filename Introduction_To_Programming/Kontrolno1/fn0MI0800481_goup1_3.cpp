#include <iostream>
#include <cstring>

void split(char* s, char* a, char* b){
    int wordStart;
    int wordEnd;
    int length = strlen(s);
    //find the start
    for (size_t i = 0; i < length; i++)
    {
        if(s[i] != ' '){
            wordStart = i;
            break;
        }

    }
    while(wordEnd != length - 1){
        bool foundEnd = true;
        for (size_t i = wordStart; i < length; i++)
        {
            if(s[i] == ' '){
                wordEnd = i;
                foundEnd = false;
                break;
            }
        }
        if(foundEnd == true)
            wordEnd = length - 1;
        //cread substring which is the word
        char substr[255];
        for (size_t i = wordStart; i < wordEnd; i++)
        {
            substr[i - wordStart] = s[i];
        }
        substr[wordEnd - wordStart] = '\0';
        if(wordEnd == length - 1){
            substr[wordEnd - wordStart] = s[wordEnd];
            substr[wordEnd - wordStart + 1] = '\0'; //
        }

        std::cout << substr << '\n';
        //check if the word is small letters only
        bool onlysmall = true;
        for (size_t i = 0; i < strlen(substr); i++)
        {
            if(!(substr[i] <= 'z' && substr[i] >= 'a')){
                onlysmall = false;
            }
        }
        if(onlysmall){
            strcat(a, substr);
            a[strlen(a)] = ' ';
        }
        else{
            strcat(b, substr);
            b[strlen(b)] = ' ';
        }
        wordStart = wordEnd + 1;
    }
    
}

int main(){
    /*[40т.] Да се дефинира функция void split(char *s, char *a, char* b), където s, a и b са символни низове. 
    Всяка последователност от символи в s, несъдържаща интервали и оградена от двете страни от интервали или 
    краищата на низа, наричаме “дума”. Функцията да записва в a последователно всички думи от s, които съдържат 
    само малки латински букви, като ги раздели с интервали помежду им. В b да се записват последователно останалите 
    думи, отново разделени с интервали. Приемете, че буферите, сочени от a и b, са достатъчно големи, за да поберат резултатите.

    Пример: Ако s = “Please give me 4 COLD beers NOW!”, то a=”give me beers”,  а b=”Please 4 COLD NOW!”.*/
    char s[255], a[255] = "\0", b[255] = "\0";
    std::cin.getline(s, 254);
    split(s, a, b);
    std::cout << a << '\n';
    std::cout << b;
}