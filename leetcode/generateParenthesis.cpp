#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
	//暴力破解
	vector<string> group;
    vector<string> generateParenthesis(int n);
    void generate(string origin,int len);
    bool validBrackets(string str);

	//回溯法
    vector<string> generateParenthesis2(int n);
    void backtrack(vector<string> &ans, string cur, int open, int close, int max);
};
void showStrVec(vector<string> arr);




int main(){
	Solution solution;
	int n = 3;

	vector<string> result = solution.generateParenthesis(n);
	showStrVec(result);
	cout << "=============================" <<endl;

	vector<string> result2 = solution.generateParenthesis2(n);
	showStrVec(result2);
	return 0;
}


//==================暴力破解======================
vector<string> Solution::generateParenthesis(int n) {
	generate("",n*2);
	return group;
    //方法一：暴力破解
    //总字符串的长度为2n，每一个位置都有两种选择，所有的情况有2^2n种
    //但是其中有一些是不符合要求的：左前方包括当前字符，左括号的数量小于右括号数量
    //把每一种方案都生成出来，再判断其是否为合法的括号串，生成括号的过程为递归的过程
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
	if(len == 0) { group.push_back("");return;}
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

//==================回溯法======================
vector<string> Solution::generateParenthesis2(int n) {
    vector<string> ans;//新建结果数组
    backtrack(ans, "", 0, 0, n);
    return ans;
}
void Solution::backtrack(vector<string> &ans, string cur, int open, int close, int max){
    if ((int)cur.length() == max * 2) {//递归出口，如果字符串长度==括号个数 = 括号对数*2
        ans.push_back(cur);//符合递归出口时，把字符串正确的括号序列的字符串 添加进数组
        return;
    }
    //回溯法，
    if (open < max)//当左括号个数<总数对数时，贴一个左括号
        backtrack(ans, cur+"(", open+1, close, max);
    if (close < open)//当右括号个数<左括号个数时，贴一个右括号
        backtrack(ans, cur+")", open, close+1, max);
}


//调试代码
void showStrVec(vector<string> arr){
	cout << "vector<string>:" << endl;
	for(int i = 0; i< (int)arr.size(); i++){
		cout << arr[i] << endl;
	}
	cout << endl;
}