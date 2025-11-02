#include <iostream>

using namespace std;

int main(){
    //Задача 4 Да се напише програма, която въвежда цяло число n и го обръща на обратно.
    int input;
    cin >> input;
    while(input != 0){
        cout << input % 10;
        input /= 10;
    }
}