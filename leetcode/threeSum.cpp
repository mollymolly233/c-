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
	int threeSumClosest(vector<int>& nums, int target);
	vector<vector<int>> fourSum0(vector<int>& nums, int target);
	vector<vector<int>> fourSum(vector<int>& nums, int target);
};
void showVector(vector<int> arr);
void showTowDimVector(vector<vector<int>> arr);


int main(){
	Solution solution;
	// vector<int> arr = {2,3,5,1,-1,-3,-4,-5};
	// vector<int> arr = {-2,0,0,2,2};
	vector<int> arr = {1, 0, -1, 0, -2, 2};
	// vector<int> arr = {1,-2,-5,-4,-3,3,3,5};


	showVector(arr);

	//三数和
	// vector<vector<int>> result = solution.threeSum(arr);
	// showTowDimVector(result);

	// vector<vector<int>> result2 = solution.threeSum2(arr);
	// showTowDimVector(result2);

	//最接近的三数和
	int target = 0;
	cout << "input target value: ";
	cin >> target;
	// cout << "result: " << solution.threeSumClosest(arr, target) << endl; 

	//四数和
	vector<vector<int>> result4 = solution.fourSum(arr,target);
	showTowDimVector(result4);
	return 0;
}


//======================================================
//						四数和
//======================================================
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	sort(nums.begin(),nums.end());
	showVector(nums);

	//循环遍历每个元素
	for(int i = 0; i< (int)nums.size()-3; i++){
		if(i>0 && nums[i] == nums[i-1]) continue;//去除重复的

		//在该元素后面，再找
		for(int j = i+1; j < (int)nums.size()-2; j++){
			int sum0 = nums[i]+nums[j];
			if(j > i+1 && nums[j] == nums[j-1]) continue;//去除重复的

			//方法一：左右同时逼近，
			// int k = j+1;
			// int l = (int)nums.size()-1;
			// while(k<l){
			// 	// if(nums[k]+sum0 > target) break;
			// 	if(k>j+1 && nums[k] == nums[k-1]){
			// 		++k;
			// 		continue;
			// 	}
			// 	if(l < (int)nums.size()-1 && nums[l] == nums[l+1]){
			// 		--l;
			// 		continue;//去除重复的
			// 	}
			// 	int sum = sum0+nums[k]+nums[l];
			// 	if(sum == target){
			// 		vector<int> tmp = {nums[i], nums[j], nums[k], nums[l]};
			// 		result.push_back(tmp);
			// 		--l;++k;
			// 	}
			// 	else if(sum > target) --l;
			// 	else ++k;
			// }

			//方式二：用map去优化查询的部分，缺点没有去重，需要单独处理去重
			map<int,int> rest;
			for(int m = j+1; m<=(int)nums.size()-1; m++){
				if(rest.find(nums[m]) != rest.end()){//找到了
					vector<int> tmp = {nums[i], nums[j], rest[nums[m]], nums[m]};
					result.push_back(tmp);
				}
				else{//没找到，说明前面的没有差nums[m]的
					rest[target - sum0 - nums[m]] = nums[m];
				}
			}

		}
	}
	return result;
}


vector<vector<int>> Solution::fourSum0(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());

    //循环遍历每个元素
    for(int i = 0; i< (int)nums.size(); i++){
        if(i>0 && nums[i] == nums[i-1]) continue;//去除重复的
        //在该元素后面，再找
        
        for(int j = i+1; j < (int)nums.size(); j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;//去除重复的
            
            int k = j+1;
            int l = (int)nums.size()-1;
            
            while(k<l){
                if(k>j+1 && nums[k] == nums[k-1]){
                    ++k;
                    continue;
                }
                if(l < (int)nums.size()-1 && nums[l] == nums[l+1]){
                    --l;
                    continue;//去除重复的
                }
                int sum = nums[i]+nums[j]+nums[k]+nums[l];
                if(sum == target){
                    vector<int> tmp = {nums[i], nums[j], nums[k], nums[l]};
                    result.push_back(tmp);
                    --l;++k;
                }
                else if(sum > target) --l;
                else ++k;
            }
        }
    }
    return result;
}

//======================================================
//					最接近的三数和
//======================================================
int Solution::threeSumClosest(vector<int>& nums, int target) {
        //暴力破解：三层遍历，更新三数和 以及最接近的三数和集合
        //类似三数和，先排序外层一个遍历，内层三个指针
        //1.排序
        sort(nums.begin(),nums.end());
        int nearestSum = nums[0] + nums[1] + nums[2];//存储最近似的三数和
        int diff = INT_MAX;//存储最大差值
        
        //2.遍历找最接近的和
        for(int i = 0; i< (int)nums.size() && nearestSum-target != 0; i++){
            int j = i+1,k = (int)nums.size()-1;

            //左右没相遇前去逼近找
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                //和更接近了则更新
                if(abs(sum-target) < diff){
                    nearestSum = sum;
                    diff = abs(nearestSum-target);
                    // cout << nums[i] << " + " << nums[j] << " + " << nums[k] << " = " << sum << endl;
                }
                //根据当前和 与 target的大小关系，移动左右两个指针
                if(sum > target) --k;
                else ++j;
            }
        }
        return nearestSum;
    }


//======================================================
//						三数和
//======================================================

//问题描述：
/* 给定一个vector，求其中三个数和为0的配对，返回一个二维数组 */
//1.暴力破解，三层循环遍历所有的排列。问题是1.慢，2.不能去除重复的组合
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
					vector<int> tmp = {arr[i],arr[j],arr[k]};
					result.push_back(tmp);
				}
			}
		}
	}
	return result;
}

//2.先排序，然后一层循环遍历，三个指针来指向三个元素，根据大小调整左右指针，中间这个即为外层循环的当前元素
//算法分析，相当于两层循环，两层循环O(n^2),排序O(nlogn),所以总的时间复杂度还是O(n^2)
//同时可以去重，内层移动指针时，可以判断是否和上一个元素相同，相同则跳过
//时间是从 排序后有序，指针调整有方向可循。
//两数和也可以用类似的方法来，只不过不需要完成循环了。同理四数和也可以类比用两个外层循环
//甚至可以把两数和抽出来做一个函数，传入一个排好序的数组和一个目标值。输出二维数组：符合的组合的集合
//之后三数和 四数和 n数和都可以调用
vector<vector<int>> Solution::threeSum2(vector<int> nums){
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

//======================================================
//						两数和
//======================================================
/* 给定一个vector，求其中两两和为0的配对，返回一个二维数组 */
//思路1：暴力破解，两层循环，所有组合算一遍，符合的加入到结果数组中
//思路2：遍历一次，用一个map存储已经遍历过的数，key为0-当前数，value>0即可。
//遍历时先在map中查找key为0-当前数，是否有值，有则找到一对，即当前数和0-当前数，没有则把0-当前数当作key放进map中
//利用的是：map底层为红黑树，查找效率高于线性表 这一特点
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