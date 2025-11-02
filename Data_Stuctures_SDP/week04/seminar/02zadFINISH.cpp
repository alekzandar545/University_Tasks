#include <iostream>
#include <stack>

void sort(std::stack<int>& s){
    std::stack<int> temp;
    int val, count;
    while(!s.empty()){
        val = s.top();
        s.pop();
        if(temp.empty() || temp.top() > val)
            temp.push(val);
        else{
            count = 0;
            while(!temp.empty() && temp.top() < val){
                s.push(temp.top());
                temp.pop();
                count++;
            }
            temp.push(val);
        }
    }
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
    return;
}

int main(){

}