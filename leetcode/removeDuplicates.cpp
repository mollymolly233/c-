#include<iostream>
#include<vector>

using namespace std;


//[0,0,1,1,1,2,2,3,3,4]=>[0,1,2,3,4]
//思路：两个指针，
//一个指针用于遍历，同时比较是否和前面的一样，找到不重复的值
//另一个指针从最初位开始不停地把不重复元素放进前面的位置

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size()<2) return nums.size();
    	int unique = 1;
    	
        for(int i = 1; i<nums.size(); i++){
        	if(nums[i] != nums[i-1]){//和前面的元素不同，说明是新的不重复元素，存进前面的位置中
        		nums[unique++] = nums[i];
        	}
        }
        return unique;
    }
};

int main(){
	Solution solution;
	//int a[10]= {0,0,1,1,1,2,2,3,3,4};
	//int a[10]= {0,1,2,3,4,5,6,7,8,9};
	//int a[0]= {0,1,2,3,4,5,6,7,8,9};
	vector<int> nums;//(a,a+10);
	//vector<int> nums = {0,0,1,1,1,2,2,3,3,4};//=>[0,1,2,3,4];

	//nums.push_back(2);
	
	int count = solution.removeDuplicates(nums);
	cout << "unique count = " << count << endl;
	return 0;
}