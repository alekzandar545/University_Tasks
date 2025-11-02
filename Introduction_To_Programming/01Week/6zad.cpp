#include <iostream>

using namespace std;

template <typename T> void calculate(T num1, T num2){
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl
        << num1 << " - " << num2 << " = " << num1 - num2 << endl
        << num1 << " * " << num2 << " = " << num1 * num2 << endl
        << num1 << " / " << num2 << " = " << num1 / num2 << endl; 
}
template <typename T, typename F> void calculate(T num1, F num2){
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl
        << num1 << " - " << num2 << " = " << num1 - num2 << endl
        << num1 << " * " << num2 << " = " << num1 * num2 << endl
        << num1 << " / " << num2 << " = " << num1 / num2 << endl; 
}

int main(){
    int int1, int2;
    float float1, float2;
    double double1, double2;
    cout << "enter 2 integers" << endl;
    cin >> int1 >> int2;
    cout << "enter 2 floats" << endl;
    cin >> float1 >> float2;
    cout << "enter 2 doubles" << endl;
    cin >> double1 >> double2;

    cout << "integers:" << endl;
    calculate<int>(int1, int2);
        /*
        << "a + b" << int1 + int2 << endl
        << "a - b" << int1 - int2 << endl
        << "a * b" << int1 * int2 << endl
        << "a / b" << int1 / int2 << endl;
        */
    
    cout << "floats:" << endl;
    calculate<float>(float1, float2);
        /*
        << "a + b" << float1 + float2 << endl
        << "a - b" << float1 - float2 << endl
        << "a * b" << float1 * float2 << endl
        << "a / b" << float1 / float2 << endl;
        */

    cout << "doubles:" << endl;
    calculate(double1, double2);
        /*
        << "a + b" << double1 + double2 << endl
        << "a - b" << double1 - double2 << endl
        << "a * b" << double1 * double2 << endl
        << "a / b" << double1 / double2 << endl;
        */

    cout << "float and double:" << endl;
    calculate(float1, double2);
        /*
        << "a + b" << float1 + double2 << endl
        << "a - b" << float1 - double2 << endl
        << "a * b" << float1 * double2 << endl
        << "a / b" << float1 / double2 << endl;
        */

    cout << "int and double:" << endl;
    calculate(int1, double2);

    cout << "float and int:" << endl;
    calculate(float1, int2); 

    return 0;
}


    
