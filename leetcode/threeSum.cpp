#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>

using namespace std;
class Solution{
public:
	vector<vector<int>> twoSum(vector<int> arr);
	vector<vector<int>> threeSum(vector<int> arr);
	vector<vector<int>> threeSum2(vector<int> arr);
};
void showVector(vector<int> arr);
void showTowDimVector(vector<vector<int>> arr);


int main(){
	Solution solution;
	// vector<int> arr = {2,3,5,1,-1,-3,-4,-5};
	// vector<int> arr = {-2,0,0,2,2};
	vector<int> arr = {-1, 0, 1, 2, -1, -4};


	showVector(arr);

	vector<vector<int>> result = solution.threeSum(arr);
	showTowDimVector(result);

	vector<vector<int>> result2 = solution.threeSum2(arr);
	showTowDimVector(result2);
	return 0;
}

//问题描述：
/* 给定一个vector，求其中三个数和为0的配对，返回一个二维数组 */
vector<vector<int>> Solution::threeSum(vector<int> arr){
	vector<int> twoSum;
	vector<vector<int>> result;
	for(int i = 0; i< (int)arr.size(); i++){//遍历计算每个值应该配对的另外两数的和
		twoSum.push_back(0-arr[i]);
	}
	for(int i = 0; i< (int)arr.size()-2; i++){//当前值
		for(int j = i+1; j< (int)arr.size()-1; j++){//第二个值
			for(int k=j+1; k<(int)twoSum.size();k++){//
				if(arr[i]+arr[j] == twoSum[k]){
					vector<int> tmp;
					tmp.push_back(arr[i]);
					tmp.push_back(arr[j]);
					tmp.push_back(arr[k]);
					result.push_back(tmp);
				}
			}
		}
	}
	return result;
}


vector<vector<int>> Solution::threeSum2(vector<int> nums){
	map<int,pair<int,int>> rest;
	vector<vector<int>> result;

	sort(nums.begin(),nums.end());
	showVector(nums);

	for(int k = 0; k < (int)nums.size(); k++){
		if(nums[k]>0 || (k>0 && nums[k]==nums[k-1])) continue;//k正,则和一定为正，没有必要再遍历了

		int i = k+1;
		int j = nums.size()-1;

		cout << "nums[" <<k<< "]="<<nums[k] << ", nums[" << i << "]=" << nums[i] << ", nums[" << j << "]=" << nums[j] << endl;

		//求和>0则把j往前移动，<0则把i往后移动
		while(i<j){
			/*
			if(j<nums.size()-1 && nums[j] == nums[j+1]) --j;
			else if(i>1 && nums[i]==nums[i-1]) ++i;
			else 
			*/
			if(nums[k]+nums[i]+nums[j]>0){// || nums[j] == nums[j-1]
				cout << "  nums[" <<k<< "]="<<nums[k] << ", nums[" << i << "]=" << nums[i] << ", nums[" << j << "]=" << nums[j] << ":j--" << endl;
				--j;
			}
			else if(nums[k]+nums[i]+nums[j]<0){// || nums[i]==nums[i+1]
				cout << "  nums[" <<k<< "]="<<nums[k] << ", nums[" << i << "]=" << nums[i] << ", nums[" << j << "]=" << nums[j] << ":i++" << endl;
				++i;
			}
			else{
				cout << "  nums[" <<k<< "]="<<nums[k] << ", nums[" << i << "]=" << nums[i] << ", nums[" << j << "]=" << nums[j] << ":ok" << endl;
				vector<int> tmp = {nums[k],nums[i],nums[j]};
				result.push_back(tmp);
				++i;
				--j;
			}
		}

		set<vector<int>>s(result.begin(), result.end());
    	result.assign(s.begin(), s.end());

		cout << "nums[" <<k<< "]="<<nums[k] << ", nums[" << i << "]=" << nums[i] << ", nums[" << j << "]=" << nums[j] << endl << endl;
		

		//如果移动结束时，和为0，则塞入结果数组中
		// if(nums[k]+nums[i]+nums[j] == 0){
		// }
	}
	return result;
}

/* 给定一个vector，求其中两两和为0的配对，返回一个二维数组 */
vector<vector<int>> Solution::twoSum(vector<int> arr){
	map<int,int> rest;//(arr.size())
	vector<vector<int>> result;
	for(int i = 0; i< (int)arr.size(); i++){
		//先用0-当前数，如果
		cout << arr[i] << " ";
		if( rest[arr[i]] != 0){//arr[i] < (int)rest.size() &&
			cout << "find in rest" << endl;
			vector<int> tmp;
			tmp.push_back(arr[i]);
			tmp.push_back(0-arr[i]);
			result.push_back(tmp);
		}
		else{
			cout << "not find in rest"<< endl;
			rest[0-arr[i]] = arr[i];
		}
	}
	return result;
}

void showVector(vector<int> arr){
	cout << endl << "vector: " ;
	for(int i = 0; i<(int)arr.size(); i++){
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void showTowDimVector(vector<vector<int>> arr){
	cout << endl << "two dim vector: " << endl;
	for(int i = 0; i < (int)arr.size(); i++){
		cout << i << ": ";
		for(int j = 0; j<(int)arr[0].size(); j++){
			cout << arr[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}