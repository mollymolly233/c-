#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums);
};


int main(){
    Solution solution;
    vector<int> nums = {3,-2,-1,0,2,3,4};
    threeSum(nums);
    return 0;
}

//问题描述：给定一个数组，找到和为0的三个数的组合
vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    //整体思路：先排序，再遍历，这样就可以保证三数和是增长的，可以利用有序的这个性质，做一些情况的筛选，使整个寻找的过程变得有方向
    //外层循环遍历作为中间的值，
    //另外用两个指针，分别从两端逼近，寻找这个中间值情况下应该搭配的左右两个值是多少。
    //大了就把右边的指针左移，否则右移左指针
        vector<vector<int>> result;
        set<vector<int>>s;
        sort(nums.begin(),nums.end());

        for(int k = 0; k < (int)nums.size(); k++){
            if(nums[k]>0 || (k>0 && nums[k]==nums[k-1])) continue;//k正,则和一定为正，没有必要再遍历了。另外跳过所有相同的k

            int i = k+1;
            int j = nums.size()-1;
            
            //求和>0则把j往前移动，<0则把i往后移动
            while(i<j){
                if(nums[k]+nums[i]+nums[j]>0) --j;//nums[j] == nums[j-1] || 
                else if(nums[k]+nums[i]+nums[j]<0) ++i;//nums[i]==nums[i+1] || 
                else{//找到了，把组合放入符合条件的组合中
                    vector<int> tmp = {nums[k],nums[i],nums[j]};
                    s.insert(tmp);
                    ++i;
                    --j;
                }
            }
        }
        
        // set<vector<int>>s(result.begin(), result.end());
        result.assign(s.begin(), s.end());
        return result;
    }