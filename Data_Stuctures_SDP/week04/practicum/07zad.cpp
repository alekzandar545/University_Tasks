#include <iostream>
#include <vector>
#include <stack>
//Даден е масив от цели числа. За всеки елемент намерете първия по-голям елемент вдясно 
//от него и запишете индекса му в резултатен масив. Ако няма такъв запишете -1.

std::vector<int> GenerateBigger(const std::vector<int>& arr){
   std::vector<int> result(arr.size(), -1);
   std::stack<int> s;
   if(arr.size() <= 1){ // nothing that can help
        return result;
   }
   for (int i = arr.size() - 1; i >= 0; i--)
   {
        while(!s.empty() && arr[i] >= arr[s.top()]){
            s.pop();
        }
        if(!s.empty() && arr[i] < arr[s.top()]){
            result[i] = s.top();
        }
        s.push(i);
   }
   return result;
}

int main(){
    std::vector<int> inputs = {5, 3, 4, 7, 8, 1};

    std::vector<int> result = GenerateBigger(inputs);

    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ' ';
    }

}