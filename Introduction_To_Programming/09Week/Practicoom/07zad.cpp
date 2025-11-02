#include <iostream>

int** AllocateMatrix(const size_t rows, const size_t cols){
    int** matrix = new(std::nothrow) int*[rows];
    if(!matrix){
        std::cout << "Memory error!";
        return nullptr;
    }
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new(std::nothrow) int[cols];
        if(!matrix[i]){
            std::cout << "Memory error!";
            for (size_t j = 0; j < i; j++)
            {
                delete[] matrix[j];
            }
            delete[] matrix;
            return nullptr;
        }
    }
}
void Deallocate(int **matrix, const size_t rows){
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix [i];
    }
    delete[] matrix;
}

int main(){
    /*Създайте 2 функции първата да бъде int** AllocateMatrix(const size_t rows, const size_t cols),
    която да заделя памет за една матрица, а втората да бъде void Deallocate(int **matrix, const size_t rows),
    която да освобождава заделената памет за матрицата.

    Забележка, ако при заделянето се появи грешка, първата функция да връща nullptr
    и да се погрижи да няма изтекла памет.*/
}