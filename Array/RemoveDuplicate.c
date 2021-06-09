#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numSize){
	if(numSize == 0)
		return 0;
	int index = 1;
	int *tmp; 
	tmp = (int *)malloc(sizeof(int) * numSize);
	tmp[0] = nums[0];
	for(int i = 0; i < numSize; i++){
		if(nums[i] != tmp[index - 1]){
			tmp[index] = nums[i];
			index++;
		}
	}
	for(int i = 0; i < index; i++){
		//printf("%d\n", tmp[i]);
		nums[i] = tmp[i];
		printf("%d\n", nums[i]);
	}
	return index;
}

int main(){
	int nums[3] = {1,1,2}; 
	int len = removeDuplicates(nums, 3);
	printf("%d", len);
	return 0;
}

