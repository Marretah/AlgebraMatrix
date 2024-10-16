﻿#ifndef MATRIXSOLVER_H
#define MATRIXSOLVER_H

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

template <typename T>
class MatrixSolver {
public:

	// Static function to print a matrix
	static void PrintMatrix(const std::vector<std::vector<T>>& matrix) {
		for (const auto& row : matrix) {
			for (const auto& value : row) {
				std::cout << std::setw(10) << std::setprecision(4) << value << " ";
			}
			std::cout << std::endl;
		}
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
	// Helper function to detect zero pivots
	static bool HasZeroPivot(const std::vector<std::vector<T>>& matrix) {
		int n = matrix.size(); // Number of rows
		for (int i = 0; i < n; i++) {
			if (matrix[i][i] == 0) {
				return true; // Found a zero pivot
			}
		}
		return false; // No zero pivots found
	}

	// Solve Gaussian elimination without pivoting (with zero-pivot check)
	static std::vector<T> SolveGaussianEliminationWithoutPivot(const std::vector<std::vector<T>>& augmentedMatrix) {
		std::vector<std::vector<T>> matrix = augmentedMatrix; // Make a copy of the matrix
		int n = matrix.size(); // Number of rows

		// Check if there are any zero pivots before proceeding
		if (HasZeroPivot(matrix)) {
			std::cerr << "Error: Matrix contains a zero pivot. Cannot solve without pivoting." << std::endl;
			return {}; // Return empty solution
		}

		// Forward elimination (without pivoting)
		for (int i = 0; i < n; i++) {
			// Eliminate all rows below row i
			for (int j = i + 1; j < n; j++) {
				T ratio = matrix[j][i] / matrix[i][i];
				for (int k = i; k < matrix[0].size(); k++) {
					matrix[j][k] -= ratio * matrix[i][k];
				}
			}
		}

		// Back substitution
		std::vector<T> solution(n);
		for (int i = n - 1; i >= 0; i--) {
			solution[i] = matrix[i].back(); // The last column of the row is the constant term
			for (int j = i + 1; j < n; j++) {
				solution[i] -= matrix[i][j] * solution[j];
			}
			solution[i] /= matrix[i][i]; // Divide by the diagonal element
		}

		return solution;
	}



	// Function to perform Gaussian elimination with partial pivoting
	static std::vector<T> SolveGaussianEliminationWithPartialPivot(const std::vector<std::vector<T>>& augmentedMatrix) {
		std::vector<std::vector<T>> matrix = augmentedMatrix; // Make a copy of the matrix
		int n = matrix.size(); // Number of rows

		// Forward elimination with partial pivoting
		for (int i = 0; i < n; i++)
		{
			// Find the maximum element in the current column
			int maxRow = i;
			for (int k = i + 1; k < n; k++) {
				if (std::abs(matrix[k][i]) > std::abs(matrix[maxRow][i]))
				{
					maxRow = k;
				}
			}

			// Swap the maximum row with the current row
			if (maxRow != i) {
				std::swap(matrix[i], matrix[maxRow]);
			}

			// Check for zero pivot element
			if (matrix[i][i] == 0) {
				std::cerr << "Error: Zero pivot element at row " << i << ". The system may not have a unique solution." << std::endl;
				return {};
			}

			// Eliminate entries below the pivot
			for (int j = i + 1; j < n; j++)
			{
				T ratio = matrix[j][i] / matrix[i][i];
				for (int k = i; k < matrix[0].size(); k++)
				{
					matrix[j][k] -= ratio * matrix[i][k];
				}
			}
		}

		// Back substitution
		std::vector<T> solution(n);
		for (int i = n - 1; i >= 0; i--)
		{
			solution[i] = matrix[i].back(); // The last column of the row is the constant term
			for (int j = i + 1; j < n; j++) {
				solution[i] -= matrix[i][j] * solution[j];
			}
			solution[i] /= matrix[i][i];
		}

		return solution;
	}

	static T ReturnMatrixDeterminant(const std::vector<std::vector<T>>& MatrixA)
	{
		switch (MatrixA.size())
		{
		case 0:
			return 0; // Determinant of an empty matrix
		case 1:
			return MatrixA[0][0]; // Determinant of 1x1 matrix
		case 2:
			// Determinant of 2x2 matrix
			return (MatrixA[0][0] * MatrixA[1][1]) - (MatrixA[0][1] * MatrixA[1][0]);
		default:
			// If you plan to handle larger matrices, you can add recursive determinant calculation here
			return CalculateDeterminant(MatrixA); // Or any default value to indicate an unsupported matrix size
		}
	}

	static T CalculateDeterminant(const std::vector<std::vector<T>>& matrix)
	{
		int n = matrix.size();
		T determinant = 0;

		// Cofactor expansion along the first row
		for (int col = 0; col < n; ++col) {
			std::vector<std::vector<T>> minorMatrix = GetMinor(matrix, 0, col);
			T cofactor = ((col % 2 == 0) ? 1 : -1) * matrix[0][col]; // Alternating signs
			determinant += cofactor * CalculateDeterminant(minorMatrix); // Recursive call
		}

		return determinant;
	}

	// Helper function to get the minor matrix by removing the specified row and column
	static std::vector<std::vector<T>> GetMinor(const std::vector<std::vector<T>>& matrix, int row, int col)
	{
		std::vector<std::vector<T>> minorMatrix;

		for (int i = 0; i < matrix.size(); ++i) {
			if (i == row) continue; // Skip the specified row

			std::vector<T> minorRow;
			for (int j = 0; j < matrix[i].size(); ++j) {
				if (j == col) continue; // Skip the specified column
				minorRow.push_back(matrix[i][j]);
			}
			minorMatrix.push_back(minorRow);
		}

		return minorMatrix;
	}


};

#endif
