#include <iostream>
const size_t SIZE = 3;

bool IsValidMove(bool pathMatrix[SIZE][SIZE], int const matrix[SIZE][SIZE], unsigned x, unsigned y){
    return x < SIZE && y < SIZE && !pathMatrix[x][y];
}

void FindChepaestPath(bool pathMatrix[SIZE][SIZE], int const matrix[SIZE][SIZE], unsigned x, unsigned y, unsigned sizex, unsigned sizey, unsigned ex, unsigned ey, int sum, int &minsum){
    if(!IsValidMove(pathMatrix, matrix, x, y))
        return;
    if(x == ex && y == ey){
        if(sum < minsum || minsum == 0)
            minsum = sum;
        std::cout << minsum << '\n';
        return;
    }
    pathMatrix[x][y] = 1;
    sum += matrix[x][y];
    FindChepaestPath(pathMatrix, matrix, x+1, y, SIZE, SIZE, ex, ey, sum, minsum);
    FindChepaestPath(pathMatrix,matrix, x, y + 1, SIZE, SIZE, ex, ey, sum, minsum);
    FindChepaestPath(pathMatrix,matrix, x-1, y, SIZE, SIZE, ex, ey, sum, minsum);
    FindChepaestPath(pathMatrix,matrix, x, y-1, SIZE, SIZE, ex, ey, sum, minsum);
    pathMatrix[x][y] = 0;
    return;
}

int main(){
    int matrix[SIZE][SIZE];
    bool pathMatrix[SIZE][SIZE] = {0};
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    int minsum = 0;
    FindChepaestPath(pathMatrix, matrix, 0, 0, SIZE, SIZE, SIZE-1, SIZE-1, 0, minsum);
    std::cout << minsum;
    
}