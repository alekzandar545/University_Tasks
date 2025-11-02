#include <iostream>

using namespace std;

bool isSuffix(int a, int b){
    while(a > 0 && b > 0){
        if (a%10 != b%10) 
            return false;
        a /= 10;
        b /= 10;
    }
    return !(b > 0);
}

int Reverse(int a){
    int reverse = 0;
    while (a != 0){
        reverse = reverse*10 + a%10;
        a /= 10;
    }
    return reverse;
}

bool isPrefix(int a, int b){
    a = Reverse(a);
    b = Reverse(b);
    return isSuffix(a, b);
}

bool isInfix(int a, int b){
    while (a != 0){
        a /= 10;
        if(isSuffix(a, b) && a != b)
            return true;
    }
    return false;
}

int main(){
    int a = 1234;
    cout << boolalpha << isInfix(1234, 23);
}