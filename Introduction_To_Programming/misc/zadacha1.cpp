#include <iostream>

int main(){
    int m;
    int n;
    std::cout << "Enter m rows and n cols: ";
    std::cin >> m >> n;

    //Матрица със стойности (създаваме Pointer към всеки ред)
    double **matrix = new(std::nothrow) double*[m];
    //Проверка дали големината е валидна
    if(!matrix){
        std::cout << "Memory error! ";
        return -1;
    }

    for (size_t i = 0; i < m; i++)
    {
        //Всеки ред е pointer към колона стойности
        matrix[i] = new(std::nothrow) double[n];
        //Проверка дали е заделено валидно количество памет. Ако не, трием всичко
        if(!matrix[i]){
            std::cout << "Memory error!";
            for (size_t j = 0; j <= i; j++)
            {
                delete[] matrix[j];
            }
            delete[] matrix;
            return -1;
        }
        //Въвеждаме стойност за всяка клетка в двумерния масив
        std::cout << "Enter the value of the elements from row " << i << ": ";
        for (size_t j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }  
    }

    //създаваме масив който е голям колкото е броят на редовете в двумерния масив
    double *avgArray = new(std::nothrow) double[m];
    //проверка дали не заема твърде много памет
    if(!avgArray){
        std::cout << "Memory Error";
        return -1;
    }
    //смятаме средна стойност на всеки ред
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            avgArray[i] += matrix[i][j] / n;
        }
    }
    //извеждаме всеки ред от матрицата и съответната му ср. стойност
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << "--> " << avgArray[i] << '\n';
    }
    
    //трием всичко накрая
    for (size_t i = 0; i < m; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] avgArray;
}