#include <iostream>
#include <stack>
#include <vector>

/*Описание:
Даден е масив от стойности на акции за последователни дни. 
Трябва да намерите броя на дните преди текущия ден, през 
които стойността на акциите е била по-ниска или равна на 
стойността на текущия ден.*/
//Вход: [100, 80, 60, 70, 60, 75, 85]
//Изход: [1, 1, 1, 2, 1, 4, 6]
//O(n)

std::vector<int> FindDays(const std::vector<int>& arr){
    std::stack<int> s; //here we keep the indexes of the max values, going from left to right
    std::vector<int> result(arr.size(), 0);

    for (size_t i = 0; i < arr.size(); i++){
        // Calculate span for the current day
        while (!s.empty() && arr[i] >= arr[s.top()]) {
            s.pop(); // Pop elements from the stack
        }

        if (s.empty()) {
            result[i] = i + 1; // All elements before are smaller
        } else {
            result[i] = i - s.top(); // Difference between current and top index
        }

        s.push(i); // Push current index onto the stack
    }
    
    return result;
}

int main(){
    std::vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    std::vector<int> result = FindDays(arr);

    for (int days : result) {
        std::cout << days << " ";
    }
}