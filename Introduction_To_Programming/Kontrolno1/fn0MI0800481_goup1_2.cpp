#include <iostream>

const size_t SIZE = 1024;


//s dvoichno tursene stava po burzo
unsigned long countSums(long* arr1, long* arr2, long* arr3, int size){
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {   
        for (size_t j = 0; j < size; j++)
        {
            for (size_t p = 0; p < size; p++)
            {
                if(arr1[i] == arr2[j] + arr3[p])
                    count++;
                else if(arr2[j] == arr1[i] + arr3[p])
                    count++;
                else if(arr3[p] == arr1[i] + arr2[j])
                    count++;
            }
            
        }
    }
    return count;
    
}

void sortArray(long* arr, int size){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            if(arr[i] > arr[j]){
                long temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        
    }
    
}

int main(){
    /*[30т.] Да се дефинира функция unsigned long countSums(...) с подходящи по тип и брой параметри, която да приема 
    три масива с елементи от тип long с еднаква големина n. Елементите на масивите са подредени в нарастващ ред. 
    Функцията да намира броя на тройките от числа (a, b, c), всяко от които е елемент съответно на първия, втория 
    и третия масив (не непременно намиращи се на един и същи индекс в трите масива), такива че едното от тях е сума на другите две.

    Пример: за масивите {1,3,5}, {2,4,5}, {0,3,6} функцията връща 5 (това са тройките (1,2,3), (5,2,3), (1,5,6), (1,4,3), (5, 5, 0) ). 
    Ако има повторения на такива трийки, можете да ги броите или не, и двете решения се приемат.

    Напишете примерна програма, която демонстрира използването на функцията.*/
    int size;
    std::cin >> size;
    long arr1[SIZE], arr2[SIZE], arr3[SIZE];
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr1[i] >> arr2[i] >> arr3[i];
    }
    sortArray(arr1, size);
    sortArray(arr2, size);
    sortArray(arr3, size);
    std::cout << countSums(arr1, arr2, arr3, size);
    
}