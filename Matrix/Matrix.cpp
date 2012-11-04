// Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<vector>
#include "PrintMatrix.h"

using std::vector;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int> >  matrix;
	
	int row_1[] = {1, 2, 3, 4};
	vector<int> row1;
	row1.assign(row_1, row_1 + 4);
	
	int row_2[] = {10, 11, 12, 5};
	vector<int> row2;
	row2.assign(row_2, row_2 + 4);

	int row_3[] = {9, 8, 7, 6};
	vector<int> row3;
	row3.assign(row_3, row_3 + 4);
	
	matrix.push_back(row1);
	matrix.push_back(row2);
	matrix.push_back(row3);

	PrintMatrix::PrintCircular(matrix, 0, matrix[0].size() - 1, 0, matrix.size() - 1);

	std::cout << std::endl;
	PrintMatrix::circularOneLoop(matrix);

	return 0;
}

