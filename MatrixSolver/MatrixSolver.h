#ifndef MATRIXSOLVER_H
#define MATRIXSOLVER_H

#include <vector>
#include <iostream>
#include <string>

template <typename T>
class MatrixSolver {
public:

    // Static function to print a matrix
    static int PrintMatrix(const std::vector<std::vector<T>>& Matrix) {
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

    // Static function to convert a vector to a string
    static std::string ToStringVector(const std::vector<T>& vector) {
        std::string s = "";
        for (int i = 0; i < vector.size(); i++) {
            s += std::to_string(vector[i]) + " ";
        }
        return s;
    }

    // Static function to check if a matrix is rectangular
    static bool IsMatrixRectangle(const std::vector<std::vector<T>>& MatrixA) {
        int size = MatrixA[0].size();
        for (int i = 1; i < MatrixA.size(); i++) {
            if (size != MatrixA[i].size()) return false;
        }
        return true;
    }

    // Static function to check if two matrices can be multiplied
    static bool CanMultiplyMatrix(const std::vector<std::vector<T>>& MatrixA, const std::vector<std::vector<T>>& MatrixB) {
        return (MatrixA[0].size() == MatrixB.size());
    }

    // Static function to multiply two matrices
    static std::vector<std::vector<T>> MultiplyMatrix(const std::vector<std::vector<T>>& MatrixA, const std::vector<std::vector<T>>& MatrixB) {
        std::vector<std::vector<T>> MatrixResult(MatrixA.size(), std::vector<T>(MatrixB[0].size()));
        if (!CanMultiplyMatrix(MatrixA, MatrixB)) return MatrixResult;

        for (int i = 0; i < MatrixA.size(); i++) {
            for (int j = 0; j < MatrixB[0].size(); j++) {
                MatrixResult[i][j] = 0;
                for (int k = 0; k < MatrixA[0].size(); k++) {
                    MatrixResult[i][j] += MatrixA[i][k] * MatrixB[k][j];
                }
            }
        }
        return MatrixResult;
    }

    // Static function to multiply two matrices step by step
    static std::vector<std::vector<T>> MultiplyMatrixStepByStep(const std::vector<std::vector<T>>& MatrixA, const std::vector<std::vector<T>>& MatrixB) {
        std::vector<std::vector<T>> MatrixResult(MatrixA.size(), std::vector<T>(MatrixB[0].size()));

        // Check if multiplication is possible
        if (!CanMultiplyMatrix(MatrixA, MatrixB)) return MatrixResult;

        // Iterate through each row of MatrixA
        for (int i = 0; i < MatrixA.size(); i++) {
            // Get the current row from MatrixA
            std::vector<T> rowA = ReturnTuple(MatrixA, i);

            // Iterate through each column of MatrixB
            for (int j = 0; j < MatrixB[0].size(); j++) {
                // Get the current column from MatrixB
                std::vector<T> colB = ReturnColumn(MatrixB, j);

                // Initialize the result for the current cell
                T sum = 0;

                // Compute the dot product of rowA and colB
                for (int k = 0; k < rowA.size(); k++) {
                    sum += rowA[k] * colB[k];
                }

                // Assign the computed sum to the result matrix
                MatrixResult[i][j] = sum;
            }
        }

        return MatrixResult;
    }


    // Static function to return a tuple (row) from a matrix
    static std::vector<T> ReturnTuple(const std::vector<std::vector<T>>& Matrix, int index) {
        return Matrix[index];
    }

    // Static function to return a column from a matrix
    static std::vector<T> ReturnColumn(const std::vector<std::vector<T>>& Matrix, int index) {
        std::vector<T> SubMatrixB;
        for (int i = 0; i < Matrix.size(); i++) {
            SubMatrixB.push_back(Matrix[i][index]);
        }
        return SubMatrixB;
    }
};

#endif
