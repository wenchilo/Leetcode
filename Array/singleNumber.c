#include<stdio.h>
#include<stdio.h>

int singleNumber(int* nums, int numsSize){
	bool flag = true;
	int single;
	for(int i = 0; i < numsSize; i++){
		for(int j = 0; j < numsSize; j++){
			if(nums[i] == nums[j] && j != i){
				flag = false;
			}
			if(j == numsSize - 1 && flag == true){
				return nums[i];
			}
		}
		flag = true;
	}
	return nums[numsSize - 1];
}

int main(){
	int nums[5] = {4,1,2,1,2};
	int single = singleNumber(nums, 5);
	printf("%d", single);
	return 0;
}
