#include<stdio.h>
#include<stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
	digits[digitsSize - 1] += 1;
	if(digitsSize == 1 && digits[0] == 10){
		digits[0] = 0;
	}
	for(int i = digitsSize - 1; i >= 0; i--){
		if(digits[i] == 10){
			digits[i] = 0;
			if(i > 0)
				digits[i - 1] += 1;	
		}
	}
	if(digits[0] == 0){
		int *rlt = (int*)malloc((digitsSize + 1) * sizeof(int));
		rlt[0] = 1;
		for(int i = 1; i < digitsSize + 1; i++){
			rlt[i] = digits[0];
		}
		//*returnSize = digitsSize + 1;
		return rlt;
	}
	else{
		//*returnSize = digitsSize;
		return digits;
	}
}

int main(){
	int digits[2] = {9,9};
	int *returnSize;
	int *rlt = plusOne(digits, 2, returnSize);
	for(int i = 0; i < 3; i++){
		printf("%d,", rlt[i]);
	}
	return 0;
}
