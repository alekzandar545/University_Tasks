#include <iostream>

void printStars(int iteration){
    for (int i = 1; i <= iteration*2 - 1; i++)
        std::cout << "*";
}
void printVoid(int iteration, int n){
    for (int i = n - iteration; i > 0; i--)
        std::cout << ' ';
}
void printRhombus(int n){
//top half
    for (int i = 1; i <= n; i++)
    {   
        printVoid(i, n);
        printStars(i);
        std::cout << std::endl;
    }
    
    //bottom half
    for (int i = n - 1; i >= 1; i--){
        printVoid(i, n);
        printStars(i);
        std::cout<<std::endl;
    }

}
int main(){
    //Задача 2: Да се направи функция, на която се подава цяло положително число n и отпечатва ромб, който да е с големина 2n - 1.

    int n;
    std::cout << "enter a value for n: ";
    std::cin >> n;
    if(n < 1){
        std::cout << "invalid input";
        return 0;
    }
    printRhombus(n);
    
    
}