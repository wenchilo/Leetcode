#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
	public:
		int threeSumClosest(vector<int> &nums, int target){
			sort(nums.begin(), nums.end());
			int i, j, k, closest, dist = INT8_MAX, length = nums.size();
			k = length - 1;
			for(i = 0; i < length; i++){
				j = i + 1;
				k = length - 1;
				while(k > j){
					if(nums[i] + nums[j] + nums[k] == target){
						cout << target;
						return target;
					}
					else if(nums[i] + nums[j] + nums[k] > target){
						if(abs(nums[i] + nums[j] + nums[k] - target) <= dist){
							closest = nums[i] + nums[j] + nums[k];
							dist = abs(nums[i] + nums[j] + nums[k] - target);
							//--k;
							cout<<"!!!!!!!"<<endl;
						}
						--k;
					}
					//if(nums[i] + nums[j] + nums[k] < target){
					else{
						if(abs(nums[i] + nums[j] + nums[k] - target) <= dist){
							closest = nums[i] + nums[j] + nums[k];
							dist = abs(nums[i] + nums[j] + nums[k] - target);
							//++j;
							cout<<"????????"<<endl;
						}
						++j;
					}
					
					//cout<<"%%%%%%%"<<endl;
					cout << i << "," << j << "," << k << endl;
					cout << closest <<endl;
				}
				cout << i << "," << j << "," << k << endl;
			}
				
			cout << i << "," << j << "," << k << endl;
			cout << closest;
			return closest; 			
		}
};

int main(){
	int arr[5] = {1, 1, 1, 0, 1};
	vector<int> nums(arr, arr + 5);
	Solution solution;
	solution.threeSumClosest(nums, -100);
	return 0;
}

