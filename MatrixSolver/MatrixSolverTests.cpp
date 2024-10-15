#include "MatrixSolverTests.h"
#include <iostream>
#include <cassert>
#include <vector>
#include "MatrixSolver.h" // Include header file

// Test functions
void RunTests() {
    TestReturnTuple();
    TestReturnColumn();
    TestMatrixCanMultiplication();
    TestMatrixMultiplication();
    std::cout << "All tests passed!" << std::endl;
}

void TestReturnTuple() {
    std::vector<std::vector<int>> matrix = {
        {0, 1, 1},
        {2, 3, 4},
        {1, 2, 1}
    };
    std::vector<int> expected = { 2, 3, 4 };

    std::vector<int> result = MatrixSolver<int>::ReturnTuple(matrix, 1);

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

    std::vector<int> result = MatrixSolver<int>::ReturnColumn(matrix, 1);

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

    // Call static method without instantiation
    bool canMultiply = MatrixSolver<int>::CanMultiplyMatrix(matrixA, matrixB);

    assert(canMultiply == true);
    std::cout << "TestMatrixCanMultiplication passed." << std::endl;
}

void TestMatrixMultiplication() {
    std::vector<std::vector<int>> matrixA = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    std::vector<std::vector<int>> matrixB = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    };

    std::vector<std::vector<int>> expected = {
        {250,260,270,280},
        {618,644,670,696},
        {986,1028,1070,1112},
        {1354,1412,1470,1528}
    };

    // Call static method without instantiation
    std::vector<std::vector<int>> resultA = MatrixSolver<int>::MultiplyMatrix(matrixA, matrixB);
    std::vector<std::vector<int>> resultB = MatrixSolver<int>::MultiplyMatrixStepByStep(matrixA, matrixB);
    assert(resultA == expected);
    assert(resultB == expected);
    std::cout << "TestMatrixMultiplication passed." << std::endl;
}
