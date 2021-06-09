#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
	public:
	vector<vector<int>> threeSum(vector<int> &nums){
		//vector<int> row;
		//row.assign(3, 0);
		//vector< vector<int> > rlt;
		//rlt.assign(200, row);
		vector<vector<int>> rlt;
		int start, end, index = 0;
		//if(nums.size() < 3)
		sort(nums.begin(), nums.end());
		
		for(int now = 0; now < nums.size() - 2; now++){
			//start = now + 1;
			//end = nums.size() - 1;
			cout << "now=" << now << endl;
			if(now != 0 && nums[now - 1] == nums[now]){
				continue;
			}
			start = now + 1;
		       end = nums.size() -1;	
			while(end > start){
				if(nums[now] + nums[start] + nums[end] > 0){
					end--;
				}
				else if(nums[now] + nums[start] + nums[end] < 0){
					start++;
				}
				else{
					cout << nums[now] << "," << nums[start] << "," << nums[end] << endl; 
					/*rlt[index].push_back(nums[now]);
					rlt[index].push_back(nums[start]);
					rlt[index].push_back(nums[end]);
					index++;*/
					rlt.emplace_back(vector<int>{nums[now],nums[start], nums[end]});
					cout<<"2222222222";
					break;
				}
				cout << start << "," << end << endl;
			}
		}
		return rlt;
	}
};

int main(){
	int a[6] = {-1, 0, 1, 2, -1, -4};
	vector<int> vec(a, a + 6);
	Solution solution;
	solution.threeSum(vec);
	return 0;
}
