#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
	vector<string> group;
    vector<string> generateParenthesis(int n);
    void generate(string origin,int len);
    bool validBrackets(string str);
};
void showStrVec(vector<string> arr);

int main(){
	Solution solution;
	int n = 3;
	// solution.generate("",n*2);
	// showStrVec(solution.group);
	solution.generateParenthesis(n);
	return 0;
}

vector<string> Solution::generateParenthesis(int n) {
	generate("",n*2);

	for(int i = 0; i< (int)group.size(); i++){
		cout << endl << group[i];
		// if(validBrackets(group[i])){
		// 	//保留
		// 	cout << " stay";
		// }
		// else{
		// 	cout << " remove";
		// 	//删掉
		// }

	}
	return group;
    //方法一：暴力破解
    //总字符串的长度为2n，每一个位置都有两种选择，所有的情况有2^2n种
    //但是其中有一些是不符合要求的：左前方包括当前字符，左括号的数量小于右括号数量
    //把每一种方案都生成出来，再判断其是否为合法的括号串，生成括号的过程为递归的过程
    // string parenthesis = "(";
    // int leftCount = 1;
    // for(int i = 1; i< 2*n; i++){
    //     for(int j = 1; j <= leftCount; j++){
            
    //     }
    // }
}
bool Solution::validBrackets(string str){
	if(str[0] != '(') return false;
	int leftCount = 0;
	for(int i = 0; i < (int)str.length(); i++){
		if(str[i] == '('){
			leftCount ++;
		}
		else{
			if(leftCount == 0) return false;
			leftCount --;
		}
	}
	if(leftCount == 0) return true;
	return false;
}

//递归生成括号：完整的括号串为，第一个元素+后面n-1个括号的串
void Solution::generate(string origin,int len){
	if(len == 0) return;
	if(len == 1) {
		if(validBrackets(origin+"("))
		group.push_back(origin+"(");

		if(validBrackets(origin+")"))
		group.push_back(origin+")");
		return;
	}
	generate(origin+"(",len-1);
	generate(origin+")",len-1);
}

void showStrVec(vector<string> arr){
	cout << "vector<string>:" << endl;
	for(int i = 0; i< (int)arr.size(); i++){
		cout << arr[i] << endl;
	}
	cout << endl;
}