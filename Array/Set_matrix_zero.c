#include<stdio.h>
#include<stdlib.h>

void setZeroes(int **matrix, int matrixSize, int *matrixColSize){
	printf("%d\n", *matrixColSize);
	int *row = (int *)malloc(*matrixColSize * sizeof(int));
	int *col = (int *)malloc(matrixSize * sizeof(int));
	for(int i = 0; i < matrixSize; i++){
		for(int j = 0; j < *matrixColSize; j++){
			if(matrix[i][j] == 0){
				row[j] = 1;
				col[i] = 1;
			}
		}
	}
	//printf("%d\n", row[1]);
	printf("%d\n", *matrixColSize);
	for(int i = 0; i < *matrixColSize; i++){
		if(row[i] == 1){
			for(int j = 0; j < matrixSize; j++){
				matrix[j][i] = 0;
			}
		}
	}
	printf("%d\n", *matrixColSize);
	for(int i = 0; i < matrixSize; i++){
		if(col[i] == 1){
			printf("%d", i);
			for(int j = 0; j < *matrixColSize; j++){
				matrix[i][j] = 0;
			}
		}
	}
	printf("%d\n", matrixSize);
	for(int i = 0; i < matrixSize; i++){
		for(int j = 0; j < *matrixColSize; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int matrix[3][4] = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
	int *p[3] = {matrix[0], matrix[1], matrix[2]};
	int *colSize;
	int col = 4;
	colSize = &col;
	setZeros(p, 3, colSize);
	return 0;
}
