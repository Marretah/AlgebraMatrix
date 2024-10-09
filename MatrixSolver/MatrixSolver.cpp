// MatrixSolver.cpp : Defines the entry point for the application.
//

#include "MatrixSolver.h"
#include <vector>


std::vector<std::vector<float>> MatrixA,MatrixB;

static int PrintMatrix(std::vector<std::vector<float>> Matrix)
{
	if (&Matrix == NULL) return -1;
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

static bool IsMatrixRectangle(std::vector<std::vector<float>> MatrixA)
{
	int size = MatrixA[0].size();
	for (int i = 1; i < MatrixA.size(); i++)
	{
		if (size != MatrixA[i].size()) return false;
	}
	return true;
}

//Can only multiply if the number of Columns of A is the same as the number of lines of B
static bool CanMultiplyMatrix(std::vector<std::vector<float>> MatrixA, std::vector<std::vector<float>> MatrixB)
{
	return (MatrixA[0].size() == MatrixB.size());
}

static std::vector<std::vector<float>> MultiplyMatrix(std::vector<std::vector<float>> MatrixA, std::vector<std::vector<float>> MatrixB)
{
	std::vector<std::vector<float>> MatrixResult;
	if (!CanMultiplyMatrix(MatrixA, MatrixB)) return MatrixResult;

	return MatrixResult;
}


int main()
{
	MatrixA = 
	{ 
		{0,1,1},
		{2,3,4},
		{1,2,1}
	};
	PrintMatrix(MatrixA);

	std::cout << MatrixA.size() << std::endl;
	return 1;
}
