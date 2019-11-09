#include<iostream>
#include<vector>


using namespace std;



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums);
    void backtracking(vector<int> arr, int curr, int occupy);
private:
	vector<int> nums;
	int len;
	vector<vector<int>> result;
};
void showVec(vector<int> v);
void showTwoDimVec(vector<vector<int>> v);


int main(){
	Solution solution;
	vector<int> nums = {1,2,3};
	vector<vector<int>> result = solution.permute(nums);
	showTwoDimVec(result);
	return 0;
}


//目标 给定数组的全排列，例123 =>
/* [123] [132] [213] [231] [312] [321] */
vector<vector<int>> Solution::permute(vector<int>& nums) {
	this->nums = nums;
	this->len = (int)nums.size();
	vector<int> arr;
	backtracking(arr,0,0);
	return this->result;
}

void Solution::backtracking(vector<int> arr, int curr, int occupy){
	if(occupy == (1<<len)-1){//递归出口，长度达到了元素个数就压入结果数组
		result.push_back(arr);
		return;
	}

	//没达到长度，从occupy中找出还没有使用的元素，
	//遍历所有可能的元素，作为arr的下一个元素，进入不同的backtracking
	for(int i = 0; i< len; i++){
		if(1<<i&occupy) continue;//2的i次方即1000...0（i个0），说明这个元素已经在arr中了，跳过	
		arr.push_back(nums[i]);//把当前元素塞入arr
		backtracking(arr,i,occupy+(1<<i));//这个元素还不在arr中，这次把它塞入arr，标记为占用
		arr.pop_back();
	}
}

void showVec(vector<int> v){
	cout << "vec : ";
	for(int i = 0; i< (int)v.size(); i++){
		cout << v[i] << ",";
	}
	cout << endl;
}
void showTwoDimVec(vector<vector<int>> v){
	cout << "2 dim vec:" << endl;
	for(int i = 0; i< (int)v.size(); i++){
		showVec(v[i]);
	}
	cout << endl;
}