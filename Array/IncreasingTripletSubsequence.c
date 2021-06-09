#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

bool increasingTriplet(int* nums, int numsSize){
    int min1 = INT_MAX, min2 = INT_MAX;
    for(int i = 0; i < numsSize; i++){
        //printf("%d, ",nums[i]);
        if(nums[i] < min1)
            min1 = nums[i];
        else if(nums[i] > min1 && nums[i] < min2)
            min2 = nums[i];
        else if(nums[i] > min2){
            printf("%d, %d, %d\n", min1, min2, i);
            return true;
        }
    }
    printf("%d, %d", min1, min2);
    return false;
}

int main(){
    int nums[5] = {20,40,30,10,15};
    printf("%d", increasingTriplet(nums, 5));
    return 0;
}
