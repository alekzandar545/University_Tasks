#include <iostream>
#include <stack>
#include <queue>
#include <stdexcept>
/*В една танцова академия идваше време за редовното уроци по танци, 
но тази седмица инструкторите решиха да добавят нов елемент – танцови 
двойки. За целта те помолиха всички курсисти да се съберат в залата. 
Всяка двойка щеше да се състои от един мъж и една жена.

Програмата очаква вход в текстов формат, където всяка линия съдържа 
информация за пол и име на участника. Полът се обозначава с "F" за жена 
и "M" за мъж, следвано от името на съответния участник.*/

struct dancer
{
    bool gender; //F is female T is male
    std::string name;
};


int main(){
    size_t n;
    std::queue<dancer> males;
    std::queue<dancer> females;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        char gender;
        std::cin >> gender;
        if(gender != 'M' && gender != 'F')
            throw -1;
        std::string name;
        std::cin >> name;
        dancer d;
        d.name = name;
        if(gender == 'M'){
            males.push(d);
            d.gender = true;
        }
        else{
            females.push(d);
            d.gender = false;
        }

    }
    while(!(males.empty()) && !(females.empty())){
        dancer f, m;
        f = females.front();
        m = males.front();
        std::cout << "Female dancer is: " << f.name << " and the male dancer is: " << m.name << '\n';
        females.pop();
        males.pop();
    }
    int fWait = 0;
    int mWait = 0;
    while(!males.empty()){
        mWait++; 
        males.pop();
    }

    while(!females.empty()){
        fWait++; 
        females.pop();
    }

    std::cout << "Females waiting to dance: " << fWait << '\n' << "Males waiting to dance: " << mWait;


}