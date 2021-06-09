#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void q_sort(int *nums, int left, int right){
	if(left >= right)
		return;
	else{
		int i = left, j = right;
		int pivot = nums[right];
		while(1){
			if(i >= j)
				break;
			while(nums[i] < pivot){
				if(i > j){
					break;
				}
				i++;
			}
			while(nums[j] >= pivot){
				if(i >= j)
					break;
				j--;
			}
			if(i < j)
				swap(&nums[i], &nums[j]);
		}
		swap(&nums[j], &nums[right]);
		/*for(int k = left; k <= right; k++){
			printf("%d,", nums[k]);
		}*/
		q_sort(nums, left, j - 1);
		q_sort(nums, j + 1, right);
	}
}
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColSize){
	q_sort(nums, 0, numsSize - 1);
	int **result = NULL;
	int l_index, r_index, sum, size = 0;
	for(int i = 0; i < numsSize - 2; i++){
		printf("i = %d\n", i);
		l_index = i + 1;
		r_index = numsSize - 1;
		while(l_index < r_index){
			//printf("while");
			sum = nums[i] + nums[l_index] + nums[r_index];
			if(sum < 0)
				l_index++;
			else if(sum > 0)
				r_index--;
			else{
				size++;
				result = (int **)realloc(result, size * sizeof(int*));
				result[size - 1] = (int *)malloc(3 * sizeof(int));
				result[size - 1][0] = nums[i];
				result[size - 1][1] = nums[l_index];
				result[size - 1][2] = nums[r_index];
				printf("%d,%d,%d\n", nums[i], nums[l_index], nums[r_index]);
                while(l_index + 1 < numsSize && nums[l_index] == nums[l_index + 1])
                    l_index++;
                while(r_index - 1 >= 0 && nums[r_index] == nums[r_index - 1])
                    r_index--;
				l_index++;
				r_index--;
			}
			//printf("%d,%d,%d\n", i, l_index, r_index);
		}
		printf("%d,%d,%d4444445\n", i, l_index, r_index);
		printf("numsize = %d", numsSize);
		if(i == 3)
			break;
	}
	printf("out");
    int col = 3;
    int *Col = &col;
    returnColSize = &Col;
	*returnSize = size;
	//**returnColSize = 3;
	return result;
}

int main(){
	int num[6] = {-1,0,1,2,-1,-4};
	//printf("main");
	//qsort(num, 0, 5);
	/*for(int i = 0; i < 6; i++){
		printf("%d,", num[i]);
	}*/
	int *size, **col;
	int **p = threeSum(num, 6, size, col);
	return 0;
}
