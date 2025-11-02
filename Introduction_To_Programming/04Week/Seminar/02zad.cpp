#include <iostream>

using namespace std;

int main(){
    //Задача 2 Да се напише програма, която въвежда поток от числа и ги събира, докато не срещне 0. Да се отпечата резултата.
    int input;
    int sum;
    do{
        cin >> input;
        sum += input;
    }
    while(input != 0);

    cout << "Total: " << sum;
        

}