#include "MatrixSolverTests.h"
#include <iostream>
#include <cassert>
#include <vector>

// Implementation of matrix-related functions
template <typename T>
std::vector<T> ReturnTuple(const std::vector<std::vector<T>>& matrix, int index) {
    return matrix[index];
}

template <typename T>
std::vector<T> ReturnColumn(const std::vector<std::vector<T>>& matrix, int index) {
    std::vector<T> column;
    for (int i = 0; i < matrix.size(); i++) {
        column.push_back(matrix[i][index]);
    }
    return column;
}

template <typename T>
bool CanMultiplyMatrix(const std::vector<std::vector<T>>& MatrixA, const std::vector<std::vector<T>>& MatrixB) {
    return MatrixA[0].size() == MatrixB.size();
}

// Test functions
void RunTests() {
    TestReturnTuple();
    TestReturnColumn();
    TestMatrixCanMultiplication();
    std::cout << "All tests passed!" << std::endl;
}

void TestReturnTuple() {
    std::vector<std::vector<int>> matrix = {
        {0, 1, 1},
        {2, 3, 4},
        {1, 2, 1}
    };
    std::vector<int> expected = { 2, 3, 4 };
    std::vector<int> result = ReturnTuple(matrix, 1);

    assert(result == expected);
    std::cout << "TestReturnTuple passed." << std::endl;
}

void TestReturnColumn() {
    std::vector<std::vector<int>> matrix = {
        {0, 1, 1},
        {2, 3, 4},
        {1, 2, 1}
    };
    std::vector<int> expected = { 1, 3, 2 };
    std::vector<int> result = ReturnColumn(matrix, 1);

    assert(result == expected);
    std::cout << "TestReturnColumn passed." << std::endl;
}

void TestMatrixCanMultiplication() {
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
    assert(canMultiply == true);
    std::cout << "TestMatrixMultiplication passed." << std::endl;
}

void TestMatrixMultiplication()
{
    //https://matrix.reshish.com/multCalculation.php
    std::vector<std::vector<int>> matrixA = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> matrixB = {
        {7, 8},
        {9, 10},
        {11, 12}
    };


}
