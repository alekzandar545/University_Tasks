#include <iostream>

using namespace std;

//01zad
int min(int num1, int num2){
    if(num1 < num2)
        return num1;
    else
        return num2;
}

int max(int num1, int num2){
    if(num1 > num2)
        return num1;
    else
        return num2;
}

int pow(int num1, int num2){
    int base = 1;
    for (int i = 0; i < num2; i++)
    {
        base *= num1;
    }
    return base;
    
}

void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void task1(){
    int num1, num2;
    cout << "enter two numbers: ";
    cin >> num1 >> num2;
    cout << "min: " << min(num1, num2) << endl;
    cout << "max: " << max(num1, num2) << endl;
    cout << num1 << "^" << num2 << ": " << pow(num1,num2) << endl;
    swap(num1, num2);
    cout << "swapped " << num1 << " " << num2 << endl;
}

//02zad

bool isPrime(int input){
    for (int i = 2; i < input; i++)
    {
        if(input % i == 0)
            return false;
    }
    return true;
}

void task2(){
    int n;
    cout << "Enter a number n: ";
    cin >> n;
    //
    cout << "Prime numbers: " ;
    int counter = 0;
    int number = 2;
    while(counter < n){
        if(isPrime(number)){
            cout<< number << ' ';
            number++;
            counter++;
        }
        else
            number++;
    }
    //
    cout << endl << n << " = ";
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0){
            cout << i << " * ";
            n /= i;
            i--;
            continue;
        }
    }
    cout << n << endl;
}

//03zad

bool Ascending(int input){
    int prev = 10;
    while (input > 1)
    {
        int n = input % 10;
        if (n > prev)
            return false;
        input /= 10;
        prev = n;
    }
    return true;
    
}

void task3(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Ascending: " << boolalpha << Ascending(n) << endl;
}

//04zad

int gcd(int num1, int num2){
    int maxNum = max(num1, num2);
    int minNum = min(num1, num2);
    if (num1 == num2)
        return num1;
    for (int i = maxNum - 1; i > 0; --i)
    {
        if(num1 % i == 0 && num2 % i == 0)
            return i;
    }
    return 1;
}

void task4(){
    int n, p;
    cout << "Enter two numbers: ";
    cin >> n >> p;
    cout << "Greatest common denominator = " << gcd(n, p) << endl;
}


//05zad
int lcm(int num1, int num2){
    int gcd1 = gcd(num1, num2);
    return gcd1 * ((num1 / gcd1) * (num2 / gcd1));
}

void task5(){
    int n, p;
    cout << "Enter two numbers: ";
    cin >> n >> p;
    cout << "Least common multiple = " << lcm(n, p) << endl;
}


//06zad
int append(int num1, int num2){
    int result;
    int powerTen = 1;
    while (num2 > 0){
        result += powerTen * (num2 % 10);
        num2 /= 10;
        powerTen *= 10;
    }
    while (num1 > 0){
        result += powerTen * (num1 % 10);
        num1 /= 10;
        powerTen *= 10;
    }
    return result;
}

void task6(){
    int n, p;
    cout << "Enter two numbers: ";
    cin >> n >> p;
    cout << append(n, p) << endl;   
}


//07zad
bool isLeapYear(int year){
    return (year % 4 == 0);
}
int getDaysInMonth(int month, int year){
    switch (month)
    {
    case 1:
        return 31;
        break;
    case 2:
        if(isLeapYear(year))
            return 29;
        else
            return 28;
        break;
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;
    default:
        return 0;
        break;
    }
}

bool validateYear(int year){
    return (year >= 0 && year <= 2500);
}

bool validateMonth(int month){
    return (month >= 0 && month <= 12);
}

bool validateDay(int day, int month, int year){
    return (day > 0 && day <= getDaysInMonth(month, year));
}

bool isDateValid(int day, int month, int year){
    return (validateDay(day, month, year) && validateMonth(month) && validateYear(year));
}

void printDaySuffix(int day){
    switch(day % 10)
    {
    case 1:
        cout << "st";
        break;
    case 2:
        cout << "nd";
        break;
    case 3:
        cout << "rd";
        break;
    default:
        cout << "th";
        break;
    }
}

void printMonth(int month){
    switch (month)
    {
    case 1:
        cout << "January";
        break;
    case 2:
        cout << "February";
        break;
    case 3:
        cout << "March";
        break;
    case 4:
        cout << "April";
        break;
    case 5:
        cout << "May";
        break;
    case 6:
        cout << "June";
        break;
    case 7:
        cout << "July";
        break;
    case 8:
        cout << "August";
        break;
    case 9:
        cout << "September";
        break;
    case 10:
        cout << "October";
        break;
    case 11:
        cout << "November";
        break;
    case 12:
        cout << "December";
        break;
    default:
        break;
    }
}

void task7(){
    int day, month, year;
    std::cout << "Enter a date in year month day format: ";
    std::cin >> year >> month >> day;
    if(isDateValid(day, month, year) == false){
        cout << "Invalid date!";
        return;
    }
    if(isLeapYear(year))
        cout << "Leap year ";
    if (day < 10)
        cout << "0" << day;
    else
        cout << day;
    printDaySuffix(day);
    cout << ' ';
    printMonth(month);
    cout << ' ' << year << endl;
}
//UI
void UI(){
    while (true)
    {
        char task;
        cout << "Task to execute: ";
        cin >> task;

        switch (task)
        {
        case 'e':
            return;
            break;
        case '1':
            task1();
            break;
        case '2':
            task2();
            break;
        case '3':
            task3();
            break;
        case '4':
            task4();
            break;
        case '5':
            task5();
            break;
        case '6':
            task6();
            break;
        case '7':
            task7();
            break;
        default:
            cout << "Invalid input!" << endl;
            break;
        }
    }
}

int main(){
    UI();
    /*
    Направете функция, представляваща UI (user interface), която да пита потребителя за въвеждане на число
    и да връща съответната задача. Например, ако потребителят въведе 1, да се изпълни задача 1, ако въведе 2,
    да се изпълни задача 2 и т.н. След изпълнение на съответната задача програмата да продължи своето изпълнение,
    докато не срещне команда за изход (например e). За целта да се използва switch конструкция.
    */
}