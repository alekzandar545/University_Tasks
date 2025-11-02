#include <iostream>
#include <stdbool.h>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    cout << boolalpha << (a % 3 == 0) << endl;
    cout << boolalpha << (b >= 9 && b <=13) << endl;
    cout << boolalpha << !(c >=0 && c <=8) << endl;
    cout << boolalpha << (a < 0 || b < 0 || c < 0) << endl;
    cout << boolalpha << (a == b && b == c) << endl;
}