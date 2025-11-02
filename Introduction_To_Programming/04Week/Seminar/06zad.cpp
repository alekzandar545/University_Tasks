#include<iostream>

using namespace std;

int main(){
    /*
    Задача 6 Да се напише програма, която въвежда две цели положителни числа a и b. 
    Програмата да изпълнява следните операции за всяко число в затворения интервал [a, b]. Ограничение a<=b.

    За всяко число n в интервала:

    Ако 0 <= n <= 9, да се изпринтира стойността на n с думи.
    Ако n > 9 и n е четно, да се изпринтира "четно".
    Ако n > 9 и n е нечетно, да се изпринтира "нечетно".
    Вход: 8 11 Изход: eight nine even odd*/

    int a,b;
    cin >> a >> b;
    if(a > b){
        int temp = b;
        b = a;
        a = temp;
    }
    while (a <= b){
        switch (a)
        {
        case 0:
            cout << "zero ";
            break;
        case 1:
            cout << "one ";
            break;
        case 2:
            cout << "two ";
            break;
        case 3:
            cout << "three ";
            break;
        case 4:
            cout << "four ";
            break;
        case 5:
            cout << "five ";
            break;
        case 6:
            cout << "six ";
            break;
        case 7:
            cout << "seven ";
            break;
        case 8:
            cout << "eight ";
            break;
        case 9:
            cout << "nine ";
            break;                                                            
        default:
            if(a%2 == 0)
                cout << "even ";
            else
                cout << "odd ";
            break;
        }
        a++;
    }
    

    
}