#include <iostream>
#include <cstring>

bool containsLetter(char*substr, char ch){
    for (size_t i = 0; i < strlen(substr); i++)
    {
        if (substr[i] == ch)
            return true;
    }
    return false;
}

int LongestSubstr(char* str){
    char substr[100] = {'\0'};
    char maxsubstr[100] = {'\0'};
    int startIndex = 0;
    int endIndex = 0;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if(containsLetter(substr, str[i])){
            if(strlen(substr) > strlen(maxsubstr)){
                strcpy(maxsubstr, substr);
            }
            for (size_t j = 0; j < strlen(maxsubstr); j++)
            {
                substr[j] = '\0';
            }
            
            startIndex++;
            i =  startIndex;
        }
        //std::cout<<substr<<'\n';
        substr[i - startIndex] = str[i];
    }
    if(strlen(substr) > strlen(maxsubstr))
        strcpy(maxsubstr, substr);
    std::cout << maxsubstr;
    return strlen(maxsubstr);

}

int main(){
    char string[256];
    std::cin.getline(string, 255);
    std::cout << LongestSubstr(string);
}