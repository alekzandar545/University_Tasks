#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c;
    cout << "enter 3 numbers: " << endl;
    cin >> a >> b >> c;
    cout << boolalpha << ((b > min(a, c)) && (b < max(a, c))) << endl; 
    //this works, when b != a; b!= c
    cout << boolalpha << (max(a,b) == min(b,c));
}