#include <iostream>
#include <functional>

/*Да се реализира функцията мap с аргументи масив и функцията, която да приложи върху елементите

Да се напише сортираща функция, която взима като аргумент 
предикатна функция и я използва като критерии за сортирането. 
Демонстрирайте работата на програмата с следните предикати:

1)Четен елемент е преди нечетен
2)Сравнение на остатъка при деленеие на 4*/

void map(int* arr, size_t size, std::function<int(int)> func){
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = func(arr[i]);
    }
}

void sort(int* arr, size_t size, std::function<bool(int,int)> cmp){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - i; j++)
        {
            if(cmp(arr[j+1], arr[j]))
                std::swap(arr[j], arr[j+1]);
        }
        
    }
    
}

int main(){
    int array[10]{1,2,3,4,5,6,7,8,9};
    int size = 8;
    std::function<int(int)> mult2 = [](int a){return 2*a;};
    //map(array, size, mult2);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
    std::function<bool(int a, int b)> cmp = [](int a, int b){
        if(a%2 == 0 && b%2 == 1) return true;
        if(a%2 == 1 && b%2 == 0) return false;
        if(a%2 == b%2) return a<b;
    };

    sort(array,size,cmp);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
    std::function<bool(int a, int b)> cmp2 = [](int a, int b){
        if(a%4 == b%4) return a < b;
        return a%4 < b%4;
    };
    sort(array, size, cmp2); 

    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
    
}