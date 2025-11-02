#include <iostream>

void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    //Напишете функция swap чрез подаване на аргументите по указател.
    int a, b;
    std::cin >> a >> b;
    Swap(&a,&b);
    std::cout << a << ' ' << b << std::endl;
}

