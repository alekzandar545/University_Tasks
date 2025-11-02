#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main(){
    //Да се прочете цяло число от конзолата и да се провери дали то е палиндром.
    int input;
    cin >> input;

    int straight = input;
    int reverse;
    while (input != 0){
        reverse = reverse*10 + input%10;
        input /= 10;
    }
    cout << boolalpha << (straight == reverse);
}