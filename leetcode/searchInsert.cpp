#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	int low = 0;
    	int high = nums.size()-1;
    	if(target<nums[0]) return 0;
    	if(target>nums[nums.size()-1]) return nums.size();
        while(low<high){
        	int mid = (low+high)/2;
        	cout << "low = " << low << ", high = " << high << ", mid = " << mid << endl;
        	if(nums[mid]==target)
        		return mid;
        	if(low==high-1) break;
        	if(nums[mid]<target){
        		low = mid;
        	}
        	else{
        		high = mid;
        	}
        }
        return high;
    }
};

int main(){
	cout << "test" << endl;
	int arr[5] = {1,3,5,6,8};
	vector<int> nums(arr,arr+5);
	int target = 0;

	Solution solution;
	int pos = solution.searchInsert(nums,target);
	cout << "pos = " << pos << endl;
	return 0;
}
