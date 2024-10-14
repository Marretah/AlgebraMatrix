#include "MatrixSolver.h"
#include <vector>
#include <iostream>
#include <string>
//#include "TestMatrixSolver.h"
#include "MatrixSolverTests.h"

template <typename T>
std::vector<std::vector<T>> MatrixA;

template <typename T>
std::vector<std::vector<T>> MatrixB;

template <typename T>
static int PrintMatrix(std::vector<std::vector<T>> Matrix)
{
    std::cout << "======================" << std::endl;
    for (int i = 0; i < Matrix.size(); i++) {
        std::cout << "\t";
        for (int j = 0; j < Matrix[i].size(); j++)
            std::cout << Matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "======================" << std::endl;
    return 1;
}

template <typename T>
static std::string ToStringVector(std::vector<T> vector)
{
    std::string s = "";
    for (int i = 0; i < vector.size(); i++)
    {
        s += std::to_string(vector[i]) + " ";
    }
    return s;
}

template <typename T>
static bool IsMatrixRectangle(std::vector<std::vector<T>> MatrixA)
{
    int size = MatrixA[0].size();
    for (int i = 1; i < MatrixA.size(); i++)
    {
        if (size != MatrixA[i].size()) return false;
    }
    return true;
}

// Can only multiply if the number of columns of A is the same as the number of rows of B
template <typename T>
static bool CanMultiplyMatrix(std::vector<std::vector<T>> MatrixA, std::vector<std::vector<T>> MatrixB)
{
    return (MatrixA[0].size() == MatrixB.size());
}

template <typename T>
static std::vector<std::vector<T>> MultiplyMatrix(std::vector<std::vector<T>> MatrixA, std::vector<std::vector<T>> MatrixB)
{
    std::vector<std::vector<T>> MatrixResult;
    if (!CanMultiplyMatrix(MatrixA, MatrixB)) return MatrixResult;

    // Implement the actual matrix multiplication logic here

    return MatrixResult;
}

template <typename T>
static std::vector<T> ReturnTuple(std::vector<std::vector<T>> Matrix, int index)
{
    return Matrix[index];
}

template <typename T>
static std::vector<T> ReturnColumn(std::vector<std::vector<T>> Matrix, int index)
{
    std::vector<T> SubMatrixB;
    for (int i = 0; i < Matrix.size(); i++)
    {
        SubMatrixB.push_back(Matrix[i][index]);
    }
    return SubMatrixB;
}



int main()
{
    RunTests();
    return 0;
}
