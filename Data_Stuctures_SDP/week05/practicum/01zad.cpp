#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
//Дадено ви е число num, представляващ неотрицателно цяло число, и число k. 
//Върнете най-малкото възможно число, което може да се получи след премахване на k цифри от num.

//gotta fix when leftover k :(

int calculate(std::stack<unsigned>& res){
    int result = 0;
    int exp = 0;
    while (!res.empty()){
        result += pow(10,exp)*res.top();
        res.pop();
        exp++;
    }

    return result;
}

int main(){
    unsigned num, k;
    std::cin >> num >> k;
    std::stack<unsigned> res;
    std::stack<unsigned> rev;
    while(num > 0){
        rev.push(num % 10);
        num /= 10;
    }
    while(!rev.empty()){
        //std::cout << rev.top() << " ";
        unsigned old = rev.top();
        if(!res.empty())
            old = res.top();
        unsigned curr = rev.top();
        if ((curr < old) && k){
            res.pop();
            k--;
        }
        res.push(curr);
        rev.pop();
    }
    if(!k){
        while (!k){
            res.pop();
            k--;
        }
        while (!res.empty()){
            rev.push(res.top());
            res.pop();
        }
        std::cout << calculate(rev);
    }
    else
        std::cout << calculate(res);

}