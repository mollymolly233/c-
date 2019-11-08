#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	vector<int> origin;//原始数组
	vector<vector<int>> group;//结果二维数组
	int max;//原始数组的长度
    vector<vector<int>> subsets(vector<int>& nums);
    void backtraking(vector<int> arr,int curr);

    vector<vector<int>> subsets2(vector<int>& nums);
};

void showArrVec(vector<vector<int>> arr);

int main(){
	vector<int> arr = {1,2,3};
	Solution solution;
	vector<vector<int>> result = solution.subsets2(arr);
	showArrVec(result);
	return 0;
}

//目标，给定一个数组，输出数组内所有元素的可能组合，每个组合不要求用到所有元素，但不能用到重复元素，即求数组的子集
vector<vector<int>> Solution::subsets(vector<int>& nums) {
//思路一：用递归的方式，把数组里一部分放入数组，当数组元素个数没达到上限时，持续调用递归函数
	max = (int)nums.size();
	origin = nums;
	vector<int> arr;
	backtraking(arr,0);
	return group;
}

void Solution::backtraking(vector<int> arr,int curr){
	if(curr == max){//递归出口
		group.push_back(arr);
		return;
	}
	backtraking(arr,curr+1);
	arr.push_back(origin[curr]);
	backtraking(arr,curr+1);
}

/*
作者：da-li-wang
链接：https://leetcode-cn.com/problems/subsets/solution/c-wei-yun-suan-by-da-li-wang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
//用位向量的思路，用每一个二进制位，表示数组中的一个元素，存在在子集中则为1，不存在则为0
vector<vector<int>> Solution::subsets2(vector<int>& nums) {
    int S = nums.size();//数组大小，按照S位的二进制来组合，每一位表示数组nums中的一个元素是否存在于新数组中，一共应该有2^S次方个组合结果
    int N = 1 << S;//1左移S位，即2的S次方
    vector<vector<int> > res;//结果数组
    for (int i = 0; i < N; ++i) {//遍历所有的可能结果，从1到N的二进制表示，即每一种可能的结果
        vector<int> v;
        for (int j = 0; j < S; ++j)//遍历每一个元素，看当前这个排列，对于每一个元素是否应该存在
            if (i & (1 << j))//1左移j位，即元素j如果存在，那用二进制表示它对应的数，i则是当前组合，与运算后能判断当前这一位在i的二进制中为1
                v.push_back(nums[j]);
        res.push_back(v);
    }
    return res;
}

//调试代码
void showArrVec(vector<vector<int>> arr){
	cout << "vector<vector<int>>:" << endl;
	for(int i = 0; i< (int)arr.size(); i++){
		cout << "[" << i << "]";
		for(int j = 0; j< (int)arr[i].size(); j++){
			cout << arr[i][j] << ",";
		}
		cout << endl;
	}
	cout << endl;
}