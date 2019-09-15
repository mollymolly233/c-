#include<iostream>
#include<vector>

using namespace std;

void showVector(vector<int> arr);

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // showVector(digits);
        //从最低位加起，如果最低位<9则可以直接返回了，如果==9则继续
        int plus_flag = 0;
        for(int i=digits.size()-1; i>=0; --i){
            if((int)digits[i] <9){// && plus_flag == 0
                digits[i] = digits[i]+1;
                plus_flag = 1;
                break;
            }
            else{
            	digits[i] = 0;
            }
        }

        //一直进位，进到最高位，后还需加一位，此时向前插入一个1
        if(plus_flag == 0){
        	digits.insert(digits.begin(),1);
        }
        return digits;
    }
};

int main(){
	Solution solution;
	// vector<int> arr = {2,3,5,1,-1,-3,-4,-5};
	// vector<int> arr = {-2,0,0,2,2};
	vector<int> arr = {4,6,9};
	showVector(arr);

	vector<int> arr2 = solution.plusOne(arr);
	showVector(arr2);
	return 0;
}
void showVector(vector<int> arr){
	cout << endl << "vector: " ;
	for(int i = 0; i<(int)arr.size(); i++){
		cout << arr[i] << ", ";
	}
	cout << endl;
}