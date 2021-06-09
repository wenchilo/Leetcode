#include<stdio.h>
#include<stdlib.h>

bool containsDuplicate(int* nums, int numsSize){
	for(int i = 0; i < numsSize; i++){
		for(int j = i + 1; j < numsSize; j++){
			if(nums[i] == nums[j]){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int nums[5] = {1,2,3,4,5};
	bool flag = containsDuplicate(nums, 4);
	printf("%d", flag);
	return 0;
}
