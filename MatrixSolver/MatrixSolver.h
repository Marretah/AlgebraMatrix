#ifndef MATRIXSOLVER_H
#define MATRIXSOLVER_H

#include <vector>
#include <string>

// Function to print a matrix
template <typename T>
int PrintMatrix(const std::vector<std::vector<T>>& Matrix);

// Function to convert a vector to a string
template <typename T>
std::string ToStringVector(const std::vector<T>& vector);

// Function to check if a matrix is rectangular
template <typename T>
bool IsMatrixRectangle(const std::vector<std::vector<T>>& MatrixA);

// Function to check if two matrices can be multiplied
template <typename T>
bool CanMultiplyMatrix(const std::vector<std::vector<T>>& MatrixA, const std::vector<std::vector<T>>& MatrixB);

// Function to multiply two matrices
template <typename T>
std::vector<std::vector<T>> MultiplyMatrix(const std::vector<std::vector<T>>& MatrixA, const std::vector<std::vector<T>>& MatrixB);

// Function to return a tuple (row) from a matrix
template <typename T>
std::vector<T> ReturnTuple(const std::vector<std::vector<T>>& Matrix, int index);

// Function to return a column from a matrix
template <typename T>
std::vector<T> ReturnColumn(const std::vector<std::vector<T>>& Matrix, int index);

#endif // MATRIXSOLVER_H
