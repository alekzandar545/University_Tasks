#include <iostream>
#include <iomanip>

bool ValidMove(bool** matrix, int ex, int ey, size_t size) {
    return ex >= 0 && ey >= 0 && ex < size && ey < size && !matrix[ex][ey];
}

bool ValidPath(bool** matrix, int sx, int sy, size_t size, int** outputMatrix, int counter) {
    if (!ValidMove(matrix, sx, sy, size))
        return false;

    matrix[sx][sy] = 1;
    outputMatrix[sx][sy] = counter;

    if (counter == size * size - 1) {
        return true;
    }

     int movesX[] = {2, 1, -1, -2, -2, -1, 1, 2};
     int movesY[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; ++i) {
        int nextX = sx + movesX[i];
        int nextY = sy + movesY[i];

        if (ValidPath(matrix, nextX, nextY, size, outputMatrix, counter + 1)) {
            return true;
        }
    }

    matrix[sx][sy] = 0; // Reset matrix for backtracking
    return false;
}

int main() {
    size_t n;
    std::cin >> n;

    bool** matrix = new(std::nothrow) bool*[n];
    int** outputMatrix = new(std::nothrow) int*[n];
    if(!matrix || !outputMatrix){
        std::cout << "memory error!";
        return 0;
    }
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = new(std::nothrow) bool[n];
        outputMatrix[i] = new(std::nothrow) int[n];
        if(!matrix[i] || !outputMatrix[i]){
            for (size_t j = 0; j <= i; j++)
            {
                delete[] matrix[j];
                delete[] outputMatrix[j];
            }
            delete[] matrix;
            delete[] outputMatrix;
        }
    }
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            matrix[i][j] = false;   

    if (ValidPath(matrix, 0, 0, n, outputMatrix, 0)) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                std::cout << std::setw(3) << outputMatrix[i][j] << ' ';
            }
            std::cout << '\n';
        }
    } else {
        std::cout << "No solution found.\n";
    }

    for (size_t i = 0; i < n; ++i) {
        delete[] matrix[i];
        delete[] outputMatrix[i];
    }

    delete[] matrix;
    delete[] outputMatrix;

    return 0;
}