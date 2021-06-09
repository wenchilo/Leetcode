#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

class Solution{
	public:
		string longestCommonPrefix(vector<string>& strs){
			bool flag = 1;
			char ch;
			int index = 0, min_length;
			string longest;
			if(strs.size() == 0)
				return ""; 
			while(1){
				for(int i = 0; i < strs.size(); i++){
					ch = strs[0][index];
					if(strs[i][index] != ch){
						flag = 0;
						cout<<longest;
						return longest;
					}
					else
						flag = 1;
				}
				if(flag == 1){
					longest += ch;
					flag = 0;
				}
				index++;
				if(index > strs[0].length())
					break;
			}
		}
};

int main(){
	vector<string> vec;
	//vec.push_back("flower");
	//vec.push_back("flow");
	//vec.push_back("flight");
	Solution solution;
	solution.longestCommonPrefix(vec);
	return 0;
}
