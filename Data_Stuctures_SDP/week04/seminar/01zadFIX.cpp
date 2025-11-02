#include <stack>
#include <iostream>

class StackMin{
    private:
    std::stack<int> nums;
    std::stack<int> min;

    public:
    void push(int num){
        if(num <= min.top() || min.empty())
            min.push(num);
        nums.push(num);
    }
    int pop(){
        if(nums.top() == min.top())
            min.pop();
        int val = nums.top();
        nums.pop();
        return val;
    }
    int getMin(){
        return min.top();
    }
    int top(){return nums.top();}
    bool empty(){return nums.empty();}
};


int main(){
    StackMin s;
    s.push(5);
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(1);
    s.push(4);
    s.push(6);
    s.push(7);
    s.push(0);
    
    while(!s.empty()){
        std::cout << s.getMin() << ' ' << s.top() << '\n';
        s.pop();
    }

}