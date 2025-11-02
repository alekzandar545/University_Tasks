#include <iostream>
using namespace std;

struct MatrixCell
{
    int val;
    MatrixCell* next, *down;  
};

MatrixCell* createMatrix(int arr[][3], size_t n, size_t m){
    MatrixCell** startPoints = new MatrixCell*[m];
    MatrixCell** currPoints = new MatrixCell*[m];
    for (size_t i = 0; i < m; i++)
        startPoints[i] = nullptr;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if(i==0){
                startPoints[j] = new MatrixCell{arr[i][j], nullptr, nullptr};
                currPoints[j] = startPoints[j];
            }
            else{
                currPoints[j]->down = new MatrixCell{arr[i][j], nullptr, nullptr};
                currPoints[j] = startPoints[j]->down;
            } 
            
        }
       
    }
    for (size_t i = 0; i < m; i++)
    {
        currPoints[i] = startPoints[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m-1; j++)
        {
            currPoints[j]->next = currPoints[j+1];
        }
        
        for (size_t j = 0; j < m; j++)
        {
            //currPoints[j]->next = currPoints[j+1];
            currPoints[j] = currPoints[j]->down;
        }
    }
    
    
    /*MatrixCell* curr = startPoints[1];
    for (size_t i = 0; i < n; i++)
    {
        std::cout << curr->val;
        curr = curr->down;
    }*/
    
    MatrixCell* temp = startPoints[0];
    delete[] startPoints;
    delete[] currPoints;
    return temp;
}

void print(MatrixCell* start){
    MatrixCell* lineStart, *curr = start;
    
    for (size_t i = 0;lineStart; i++)
    {
        for (size_t j = 0;curr; j++)
        {
            std::cout << curr->val << ' ';
            curr = curr->next;
        }
        std::cout << '\n';
        lineStart = lineStart->down;
    }
    
}

int main(){
    int arr[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10,11,12}
    };
    print(createMatrix(arr,4,3));

}