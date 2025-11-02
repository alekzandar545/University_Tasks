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
int main(){

}