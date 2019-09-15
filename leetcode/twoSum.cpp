#include<iostream>
#include<vector>
#include<map>

using namespace std;
class Solution{
public:
	vector<vector<int>> twoSum(vector<int> arr);
};
void showVector(vector<int> arr);
void showTowDimVector(vector<vector<int>> arr);


int main(){
	Solution solution;
	vector<int> arr = {2,3,5,1,-1,-3,-4,-5,-1,1};
	showVector(arr);

	vector<vector<int>> result = solution.twoSum(arr);
	showTowDimVector(result);
	return 0;
}

//问题描述：
/*
给定一个vector，求其中两两和为0的配对，返回一个二维数组
*/

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
			rest[arr[i]] = 0;//保证每个元素配对只使用一次，还有问题，待处理
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