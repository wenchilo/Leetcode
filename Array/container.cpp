#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
	    int max_size = 0, n = height.size();
	    for(int i = 0; i < n; i++){
		    for(int j = i + 1; j < n; j++){
			max_size = max(max_size, (j - i) * min(height[i], height[j]));
		    }
	    }
	    cout<<max_size;
	    return max_size;
    }
};

int main(){
	vector <int> height{4,3,2,1,4};
	Solution solution;
	solution.maxArea(height);
	return 0;
}
