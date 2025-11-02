#include <iostream>
#include <cstring>

int main(){
    /*Напишете функция LargestPrefix, която приема 3 стринга с дължини - n1, n2, n3 и връща най-големия 
    префикс между думите. Префикс наричаме част от низа, която стои в началото му.*/
    char str1[255], str2[255], str3[255];
    std::cin.getline(str1, 254);
    std::cin.getline(str2, 254);
    std::cin.getline(str3, 254);

    char prefix[255];
    for (size_t i = 0; i < strlen(str1); i++)
    {
        if(str1[i] != str2[i] || str2[i] != str3[i] || str1[i] != str3[i]){
            prefix[i] = '\0';
            break;
        }
 
        prefix[i] = str1[i];
    }
    std::cout << prefix;
     
}