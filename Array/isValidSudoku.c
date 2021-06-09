#include<stdio.h>
#include<stdlib.h>

bool checkRow(char** board){
	int tmp;
	bool flag[10] = {0};
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			tmp = board[i][j] - '0';
			if(flag[tmp]){
				return false;
			}
			else{
				flag[tmp] = 1;
			}
		}
	}
	return true;
}

bool checkCol(char** board){
	int tmp;
	bool flag[10] = {0};
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			tmp = board[j][i] - '0';
			if(flag[tmp]){
				return false;
			}
			else{
				flag[tmp] = 1;
			}
		}
	}
	return true;
}

bool checkSquare(char** board){
	int tmp;
	bool flag[10] = {0};
	for(int k = 0; k < 9; k++){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				tmp = board[(k / 3) * 3 + i][(k % 3) * 3 + j];
				if(flag[tmp]){
					return false;
				}
				else{
					flag[tmp] = 1;
				}
			}
		}
	}
	return true;
}

bool isValidSudoku(char[][9] board, int boardSize, int* boardColSize){
	bool flag = checkRow(board);
	if(!flag)
			return false;
	flag = checkCol(board);
	if(!flag)
			return false;
	flag = checkSquare(board);
	if(!flag)
			return false;
	return true;

}

int main(){
	char* board[] = {'5','3','.','.','7','.','.','.','.',
				 	   '6','.','.','1','9','5','.','.','.',
				 	   '.','9','8','.','.','.','.','6','.',
				 	   '8','.','.','.','6','.','.','.','3',
				 	   '4','.','.','8','.','3','.','.','1',
				 	   '7','.','.','.','2','.','.','.','6',
				 	   '.','6','.','.','.','.','2','8','.',
				 	   '.','.','.','4','1','9','.','.','5',
				 	   '.','.','.','.','8','.','.','7','9'};
	char**pboard = board;
	int boardSize = 9;
	int* boardColSize;
	boardColSize = &boardSize;
	bool flag = isValidSudoku(pboard, 9, boardColSize);
	printf('%d', bool);
	return 0;
}
