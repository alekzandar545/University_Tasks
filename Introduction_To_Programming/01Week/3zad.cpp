#include <iostream>
#include <stdbool.h>

using namespace std;

int main(){
    int input;
    cin >> input;
    bool unevenDigits = false;

    //check if all digits are uneven
    unevenDigits = (input % 2 != 0) &&
     ((input/10) % 2 != 0) &&
      ((input/100) % 2 != 0);
    cout << boolalpha << unevenDigits;
    
    return 0;
}