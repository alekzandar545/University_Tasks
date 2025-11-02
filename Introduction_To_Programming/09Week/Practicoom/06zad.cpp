#include <iostream>

void SortFirstHalf(int* arr, int size){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            if(*(arr + i) > *(arr + j)){
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
        
    }
    
}
void SortSecondHalf(int* arr, int size){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            if(*(arr + i) < *(arr + j)){
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
        
    }
}

int main(){
    /*Да се състави програма, която прочита n естествени числа от клавиатурата, заделяйки
    динамична памет за тях, сортира първата половина в нарастващ ред, a втората половина
    в намаляващ ред и ги отпечатва. Всяко от действията да бъде отделна функция, като съответно
    подадете половината масив на едната сортираща функция и другата половина от масива на другата.
    Използвайте указателна аритметика.*/
    int size;
    std::cin >> size;
    int* arr = new(std::nothrow) int[size];
    if(!arr){
        std::cout << "Memory error!";
        return -1;
    }    
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> *(arr + i);
    }
    
    SortFirstHalf(arr, size / 2);
    SortSecondHalf(arr + size / 2, size / 2);

    for (size_t i = 0; i < size; i++)
    {
        std::cout << *(arr + i);
    }
    

    delete[] arr;
}