#include <iostream>
#include <cstring>

const size_t MAXSIZE = 100;
const size_t MAXLENGTH = 11;

int main(){
    /*Да се напише програма, която сортира във възходящ ред редица от символни низове, състояща се от най-много 100 низа. 
    Всеки от низовете ще бъде с дължина най-много 10 символа. Сортирането да е спрямо дължината на елементите, като не е 
    важно в какъв ред ще са думите с еднаква дължина след сортирането. Редицата да се изведе с по 3 думи на ред.*/
    int size;
    std::cin >> size;
    std::cin.ignore();
    char strArr[MAXSIZE][MAXLENGTH];
    for (size_t i = 0; i < size; i++)
    {
        std::cin.getline(strArr[i], 10);
        //отново се чупи, ако въведа повече от 10 символа
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if(strlen(strArr[i]) < strlen(strArr[j])){
                char temp[MAXLENGTH];
                strcpy(temp, strArr[i]);
                strcpy(strArr[i], strArr[j]);
                strcpy(strArr[j], temp);
            }
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        std::cout << strArr[i] << ' ';
        if((i + 1) % 3 == 0)
            std::cout << '\n';
    }
    
    
    
}