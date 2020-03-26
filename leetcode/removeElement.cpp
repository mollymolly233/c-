#include<iostream>
#include<vector>

using namespace std;
void printVector(vector<int> nums);

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	//思路：遍历，第一次遇到后交换最后一个元素和当前元素，之后从当前这个元素开始继续遍历，同时统计数量
    	int count = 0;
    	int tail = nums.size()-1;
    	for(int i = 0; i<=tail;i++){
    		if(nums[i] == val){
    			++count;
    			if(i==tail) {
    				//cout << "count =" << count << ", tail=" << tail << ", size = " << nums.size() << ", return =" << nums.size()-count << endl;
    				return nums.size()-count;
    			}
    			//cout << endl << "nums["<<tail<<"]=" << nums[tail] << ", nums[" << i << "]=" << nums[i] << ", total=" << nums[tail]+nums[i] << ". ";
    			
    			nums[tail] = nums[tail]+nums[i];// cout << "total-nums["<<i<<"]=" <<nums[tail] - nums[i];
    			nums[i] = nums[tail] - nums[i];
    			nums[tail] = nums[tail] - nums[i];
    			//cout << "nums["<<tail<<"]=" << nums[tail] << ", nums[" << i << "]=" << nums[i] << ", total=" << nums[tail]+nums[i] << ". ";

    			--tail;
    			--i;
    			//cout << "nums["<<tail<<"]=" << nums[tail] << ", nums[" << i << "]=" << nums[i] << ", total=" << nums[tail]+nums[i] << ". ";

    		}
    		//printVector(nums);
    	}
    	//cout << "count =" << count << ", tail=" << tail << ", size = " << nums.size();
        return nums.size()-count;
    }
};


int main(){
	Solution solution;
	vector<int> nums;// = {2,3,3,4,2};

	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);

	int val = 2;
	printVector(nums);
	int newLen = solution.removeElement(nums,val);
	cout << "new count = " << newLen;
	printVector(nums);
	return 0;
}

void printVector(vector<int> nums){
	cout << endl << "vector: ";
	for(int i = 0; i<nums.size(); i++){
		cout << nums[i] << ", ";
	}
	cout << endl;
}
