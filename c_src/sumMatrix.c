#include<stdio.h>

int sumMatrix(const int (*m)[4], int row, int col)
{
	int result = 0;
	for (int i = 0; i< row; ++i)
		for (int j = 0; j < col; ++j)
			result += m[i][j];
			
	return result;
}

int main (void)
{
	int matrix[][4] ={
		1,2,3,4,5,6,7,8,9,10,11,12
		};
	
	int result = sumMatrix(matrix, 3, 4);
	printf("result %d\n", result);

	return 0;
}
