#include <iostream>
#include <stack>
#include <vector>
/*Описание:
Даден е масив от височини на стълбове, където всеки стълб представлява
височината на дадена точка. След дъжд между стълбовете може да се задържи вода.
Трябва да намерите колко вода може да бъде уловена между стълбовете.

Пример:

Вход: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Изход: 6 */

int FindCapacity(const std::vector<int>& arr){
    std::stack<int> s;
    int totalWater = 0;

    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << totalWater << ' ';
        while(!s.empty() && arr[i] > arr[s.top()]){
            int top = s.top();
            s.pop();

            if(s.empty())
                break;
            
            int distance = i - s.top() - 1;
            int boundedHeighht = std::min(arr[i], arr[s.top()]) - arr[top];
            totalWater += distance * boundedHeighht;
        }

        s.push(i);
    }  

    return totalWater;
}

int main(){
    std::vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << FindCapacity(arr);
}