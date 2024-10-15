#include "MatrixSolverTests.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include "MatrixSolver.h" // Include header file

// Function to compare floating point numbers with a tolerance
bool AlmostEqual(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}

// Test functions
void RunTests() {
    std::cout << "\nRunning tests...\n" << std::string(20, '-') << std::endl;
    TestReturnTuple();
    TestReturnColumn();
    TestMatrixCanMultiplication();
    TestMatrixMultiplication();
    TestSolveWithoutPivot();
    TestSolveWithPartialPivot();
    std::cout << "\n" << std::string(20, '-') << std::endl;
    std::cout << "\nAll tests passed!\n" << std::endl;
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
    std::cout << "\nTestReturnTuple passed.\n" << std::endl;

    // Print the result
    std::cout << "\nReturned tuple: \n";
    MatrixSolver<int>::PrintMatrix({ result }); // Wrap the result in a 2D vector for printing
    std::cout << std::string(20, '-') << std::endl; // Separator
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
    std::cout << "\nTestReturnColumn passed.\n" << std::endl;

    // Print the result
    std::cout << "\nReturned column: \n";
    MatrixSolver<int>::PrintMatrix({ result }); // Wrap the result in a 2D vector for printing
    std::cout << std::string(20, '-') << std::endl; // Separator
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
    std::cout << "\nTestMatrixCanMultiplication passed.\n" << std::endl;

    // Print the matrices
    std::cout << "\nMatrix A: \n";
    MatrixSolver<int>::PrintMatrix(matrixA);
    std::cout << "\nMatrix B: \n";
    MatrixSolver<int>::PrintMatrix(matrixB);
    std::cout << std::string(20, '-') << std::endl; // Separator
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
        {250, 260, 270, 280},
        {618, 644, 670, 696},
        {986, 1028, 1070, 1112},
        {1354, 1412, 1470, 1528}
    };

    // Call static method without instantiation
    std::vector<std::vector<int>> resultA = MatrixSolver<int>::MultiplyMatrix(matrixA, matrixB);
    std::vector<std::vector<int>> resultB = MatrixSolver<int>::MultiplyMatrixStepByStep(matrixA, matrixB);
    assert(resultA == expected);
    assert(resultB == expected);
    std::cout << "\nTestMatrixMultiplication passed.\n" << std::endl;

    // Print the results
    std::cout << "\nResult of matrix multiplication (Method A): \n";
    MatrixSolver<int>::PrintMatrix(resultA);
    std::cout << "\nResult of matrix multiplication (Method B): \n";
    MatrixSolver<int>::PrintMatrix(resultB);
    std::cout << std::string(20, '-') << std::endl; // Separator
}

void TestSolveWithoutPivot() {
    std::vector<std::vector<double>> augmentedMatrix = {
        {2, -1, 1, 8},
        {-3, 3, 9, 0},
        {-2, 1, 4, 1}
    };
    std::vector<double> expectedSolution{ 4.0 / 5.0, -23.0 / 5.0, 9.0 / 5.0 };

    std::vector<double> result = MatrixSolver<double>::SolveGaussianEliminationWithoutPivot(augmentedMatrix);

    for (size_t i = 0; i < expectedSolution.size(); ++i) {
        assert(AlmostEqual(expectedSolution[i], result[i]));
    }
    std::cout << "\nTestSolveWithoutPivot passed.\n" << std::endl;

    // Print the results
    std::cout << "Expected Solution: \n";
    MatrixSolver<double>::PrintMatrix({ expectedSolution }); // Wrap in a 2D vector for printing
    std::cout << "Calculated Solution: \n";
    MatrixSolver<double>::PrintMatrix({ result }); // Wrap in a 2D vector for printing
    std::cout << std::string(20, '-') << std::endl; // Separator
}

void TestSolveWithPartialPivot() {
    std::vector<std::vector<double>> augmentedMatrix = {
        {2, -1, 1, 8},
        {-3, 3, 9, 0},
        {-2, 1, 4, 1}
    };
    std::vector<double> expectedSolution{ 4.0 / 5.0, -23.0 / 5.0, 9.0 / 5.0 };

    std::vector<double> result = MatrixSolver<double>::SolveGaussianEliminationWithPartialPivot(augmentedMatrix);

    for (size_t i = 0; i < expectedSolution.size(); ++i) {
        assert(AlmostEqual(expectedSolution[i], result[i]));
    }
    std::cout << "\nTestSolveWithPartialPivot passed.\n" << std::endl;

    // Print the results
    std::cout << "\nExpected Solution: \n";
    MatrixSolver<double>::PrintMatrix({ expectedSolution }); // Wrap in a 2D vector for printing
    std::cout << "\nCalculated Solution: \n";
    MatrixSolver<double>::PrintMatrix({ result }); // Wrap in a 2D vector for printing
    std::cout << std::string(20, '-') << std::endl; // Separator
}


