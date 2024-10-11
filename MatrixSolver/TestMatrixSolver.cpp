#include "TestMatrixSolver.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <string>

// Forward declarations for the matrix solver functions
template <typename T>
std::vector<T> ReturnColumn(std::vector<std::vector<T>> Matrix, int index);

template <typename T>
std::vector<T> ReturnTuple(std::vector<std::vector<T>> Matrix, int index);

template <typename T>
std::string ToStringVector(std::vector<T> vector);

template <typename T>
bool CanMultiplyMatrix(std::vector<std::vector<T>> MatrixA, std::vector<std::vector<T>> MatrixB);

// TestMatrixSolver class definition
class TestMatrixSolver
{
public:
    void RunTests()
    {
        TestReturnTuple();
        TestReturnColumn();
        TestMatrixMultiplication();
        std::cout << "All tests passed!" << std::endl;
    }

private:
    void TestReturnTuple()
    {
        std::vector<std::vector<int>> matrix = {
            {0, 1, 1},
            {2, 3, 4},
            {1, 2, 1}
        };
        std::vector<int> expected = { 2, 3, 4 };
        std::vector<int> result = ReturnTuple(matrix, 1);

        assert(result == expected);  // Assert to check equality
        std::cout << "TestReturnTuple passed." << std::endl;
    }

    void TestReturnColumn()
    {
        std::vector<std::vector<int>> matrix = {
            {0, 1, 1},
            {2, 3, 4},
            {1, 2, 1}
        };
        std::vector<int> expected = { 1, 3, 2 };
        std::vector<int> result = ReturnColumn(matrix, 1);

        assert(result == expected);  // Assert to check equality
        std::cout << "TestReturnColumn passed." << std::endl;
    }

    void TestMatrixMultiplication()
    {
        std::vector<std::vector<int>> matrixA = {
            {1, 2, 3},
            {4, 5, 6}
        };
        std::vector<std::vector<int>> matrixB = {
            {7, 8},
            {9, 10},
            {11, 12}
        };
        bool canMultiply = CanMultiplyMatrix(matrixA, matrixB);

        assert(canMultiply == true);  // Check if multiplication is possible
        std::cout << "TestMatrixMultiplication passed." << std::endl;
    }
};

// Define the functions used
