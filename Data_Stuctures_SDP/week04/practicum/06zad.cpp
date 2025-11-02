#include <iostream>
#include <queue>
#include <stack>

/*Създайте опашка, която поддържа операция за намиране на максималния елемент в 
текущото състояние на опашката. Получаването на максимален елемент трябва да става за амортизирана константа.

Забележка: Стандартните операции на опашка трябва да се поддържат и тук и сложността им не трябва да се променя*/

class MinQueue{
    public:
    void enqueue(int val) {
        queue.push(val);
        if(minVals.empty())
            minVals.push_back(val);
            
        while(!minVals.empty() && val < minVals.back())
            minVals.pop_back();
        minVals.push_back(val);
    }

    int dequeue(){
        int val = queue.front();
        queue.pop();
        if(!minVals.empty() &&minVals.front() == val)
            minVals.pop_front();
        return val;
    }

    int getMin(){
        if(!minVals.empty())
            return minVals.front();
        return 0;
    }
    private:
    std::queue<int> queue;
    std::deque<int> minVals;
};

int main(){
    MinQueue mq;
    mq.enqueue(3);
    mq.enqueue(2);
    mq.enqueue(1);
    mq.enqueue(7);
    mq.enqueue(3);
    //int val = mq.dequeue();
    //std::cout << val;
    std::cout << mq.getMin() << '\n'; //returns 1
    std::cout << mq.dequeue() << '\n'; //remove 3
    std::cout << mq.dequeue() << '\n'; //remove 2
    std::cout << mq.getMin() << '\n'; //returns 1
    std::cout << mq.dequeue() << '\n'; //remove 1
    std::cout << mq.getMin() << '\n'; //returns 3
    std::cout << mq.dequeue() << '\n'; //remove 7
    std::cout << mq.getMin() << '\n'; //returns 3
}