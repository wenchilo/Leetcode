#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int nums2_start = 0, rlt_index = 0;
	int *rlt = (int *)malloc(sizeof(int) * nums1Size);
	*returnSize = 0;
	for(int i = 0; i < nums1Size; i++){
		for(int j = nums2_start; j < nums2Size; j++){
			if(nums1[i] == nums2[j]){
				rlt[rlt_index] = nums1[i];
				rlt_index++;
				(*returnSize)++;
				swap(&nums2[nums2_start], &nums2[j]);
				nums2_start++;
				break;
			}
		}
	}
	return rlt;
}

int main(){
	int nums1[4] = {1,2,2,1};
	int nums2[2] = {2,2};
	int* rlt;
	int* returnSize;
	rlt = intersect(nums1, 4, nums2, 2, returnSize);
	for(int i = 0; i < 2; i++){
		printf("%d\n", rlt[i]);
	}
	return 0;
}

