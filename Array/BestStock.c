#include<stdio.h>
#include<stdlib.h>

int maxProfit(int* price, int priceSize){
	if(priceSize == 0)
		return 0;
	int profit = 0;
	for(int i = 1; i < priceSize; i++){
		if(price[i - 1] < price[i]){
			profit += (price[i] - price[i - 1]);
		}
	}
	return profit;
}

int main(){
	int arr[6] = {7,1,5,3,6,4};
	int prof = maxProfit(arr, 6);
	printf("%d", prof);
	return 0;
}
