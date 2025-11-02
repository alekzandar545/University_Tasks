#include <iostream>
#include <cstring>

int Find(const char* s, const char* s1){
    for (size_t i = 0; i < strlen(s); i++)
    {
        if(s[i] == s1[0]){
            bool isEqual = true;
            for (size_t j = i; j < i + strlen(s1); j++)
            {
                if(s[j] != s1[j - i])
                    isEqual = false;
            }
            if(isEqual)
                return i;
        }
    }
    return -1;
    
}

int main(){
    //Да се напише функция int Find(const char* s, const char* s1), която намира индекса на първото срещане на низа s1 в s. 
    //Ако s1 не се среща в s, функцията да връща -1.
    char str1[255];
    char str2[255];
    std::cin.getline(str1, 254);
    std::cin.getline(str2, 254);
    std::cout << Find(str1, str2);
}