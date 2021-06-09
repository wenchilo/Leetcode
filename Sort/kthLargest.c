#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}
int quickselect(int *nums, int left, int right, int k){
    int pivot = right;
    int index_l = left, index_r = right - 1;
    /*if(left >= right){
        return nums[right];
    }*/
    while(1){
        while(index_l < right){
            if(nums[index_l] > nums[pivot])
                break;
            index_l++;
        }
        while(index_r >= left){
            if(nums[index_r] < nums[pivot])
                break;
            index_r--;
        }
        if(index_l > index_r)
            break;
        swap(&nums[index_l], &nums[index_r]);
    }
    //printf("r = %d\n", index_r);
    swap(&nums[pivot], &nums[++index_r]);
    for(int i = 0; i < 9; i++){
        printf("%d", nums[i]);
    }
    printf("\n");
    if(index_r == right - 1 && right == k)
        return nums[right];
    if(index_r < k)
        return quickselect(nums, index_r + 1, right, k);
    else if(index_r > k)
        return quickselect(nums, left, index_r - 1, k);
    else
        return nums[index_r];
}

int findKthLargest(int* nums, int numsSize, int k){
    if(numsSize ==0)
        return 0;
    k = numsSize - k;
    return quickselect(nums, 0, numsSize - 1, k);
}

int main(){
    int nums[9] = {3,2,3,1,2,4,5,5,6};
    printf("**%d", findKthLargest(nums, 9, 5));
    return 0;
}
