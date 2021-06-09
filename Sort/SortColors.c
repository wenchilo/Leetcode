#include<stdlib.h>
#include<stdio.h>

void sort(int *nums, int mid, int left, int right){
    int index_i = 0, index_j = 0, index_nums = left;
    int *left_sub = (int *)malloc(sizeof(int) * (mid - left + 1));
    int *right_sub = (int * )malloc(sizeof(int) * (right - mid));
    //printf("%d,%d,%d\n", left, mid, right);
    for(int i = left; i <= mid; i++){
        left_sub[i - left] = nums[i];
    }
    for(int i = mid + 1; i <= right; i++){
        right_sub[i - mid - 1] = nums[i];
    }
    
    while(index_i <= (mid - left) && index_j <= (right - mid - 1)){
        if(left_sub[index_i] < right_sub[index_j] && index_i <= (mid - left)){
            nums[index_nums] = left_sub[index_i];
            index_i++;
        }
        else{
            nums[index_nums] = right_sub[index_j];
            index_j++;
        }
        index_nums++;
    }
    while(index_i <= (mid - left)){
        nums[index_nums] = left_sub[index_i];
        index_i++;
        index_nums++;
    }
    while(index_j <= (right - mid - 1)){
        nums[index_nums] = right_sub[index_j];
        index_j++;
        index_nums++;
    }
    /*for(int i = left; i <= right; i++){
        printf("%d \n", nums[i]);
    }*/
    free(left_sub);
    free(right_sub);
}

void mergeSort(int *nums, int left, int right){
    int mid = (left + right) / 2;
    //printf("%d,%d,%d\n", left, mid, right);
    if(left < right){
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        sort(nums, mid, left, right);
    }
    //else
        //return;
}

void sortColors(int* nums, int numsSize){
    if(numsSize == 0)
        return;
    mergeSort(nums, 0, numsSize - 1);
}

int main(){
    int nums[5] = {6, 5, 4, 3, 2};
    /*for(int i = 0; i < 5; i++){
        printf("%d ", nums[i]);
    }*/
    //mergeSort(nums, 0, 4);
    sortColors(nums, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}
