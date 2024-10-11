#ifndef MATRIXSOLVERTESTS_H
#define MATRIXSOLVERTESTS_H

class TestMatrixSolver
{
public:
    // Function to run all tests
    void RunTests();

private:
    // Test functions for specific matrix operations
    void TestReturnTuple();
    void TestReturnColumn();
    void TestMatrixMultiplication();
};

#endif // MATRIXSOLVERTESTS_H
