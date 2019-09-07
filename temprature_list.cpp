#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<stack>

using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T);
    vector<int> dailyTemperatures2(vector<int>& T);
    string removeDuplicates(string S);
    string removeDuplicates2(string S);

};
void printVector(vector<int> v);

int main(){
	Solution solution;
	std::vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
	printVector(T);

	vector<int> newT = solution.dailyTemperatures2(T);
	printVector(newT);

	string str = "abaabacdsdc";
	string newStr = solution.removeDuplicates2(str);
	cout << "str = " << str << ", newStr = " << newStr << endl;
	

	return 0;
}
void printVector(vector<int> v){
	cout << "vecotor:" << endl;
	for(int i = 0; i<(int)v.size();i++){
		cout << v[i] << ", ";
	}
	cout << endl;
	return;
}
vector<int> Solution::dailyTemperatures(vector<int>& T) {
	int len = (int)T.size();
	if(len<1 || len>30000){
		vector<int> v;
		return v;
	}
	//输入一个列表，返回一个
	//遍历数组，每一个数取出来，往后找第一个比它大的，并计数
	for(int i = 0; i< len;i++){
		if(T[i]<30 || T[i]>100){
			vector<int> v;
			cout << "AssertionError: Each element in given input 'temperatures' must be an integer in the range [30, 100]";
			return v;
		}
		// int temprature = T[i];
		int j = 0;
		for(j = i+1; j< len;j++){
			if(T[j]>T[i]){
				T[i] = j-i;
				break;
			}
		}
		if(j == len){//没找到比当前元素大的，则置为0
			T[i] = 0;
		}
	}

	return T;
}



vector<int> Solution::dailyTemperatures2(vector<int>& T) {
	// cout << "int the dailyTemperatures2" << endl;
	int len = (int)T.size();
	if(len<1 || len>30000){
		vector<int> v;
		return v;
	}
	vector<int> diff(len);
	diff[len-1] = 0;
	//输入一个列表，返回一个
	//遍历数组，每一个数取出来，往后找第一个比它大的，并计数
	for(int i = len-2; i>=0; i--){
		// cout << "int the outer loop,i=" << i << endl;
		if(T[i]<30 || T[i]>100){
			vector<int> v;
			// cout << "AssertionError: Each element in given input 'temperatures' must be an integer in the range [30, 100]";
			return v;
		}
		// int temprature = T[i];
		int j = i+1;
		while(j< len){
			// cout << "in then loop" << endl;
			if(T[j]>T[i]){
				// cout << "T[j]>T[i]" << endl;
				diff[i] = j-i;
				break;
			}
			// cout << "T[j]<=T[i]" << endl;
			if(diff[j] == 0){
				// cout << "diff[j] = 0" << endl;
				diff[i] = 0;
				break;
			}
			j+=diff[j];
		} 
		if(j == len){//没找到比当前元素大的，则置为0
			// cout << "j == len" << endl;
			diff[i] = 0;
		}
	}
	return diff;
}

//删除字符串中连续重复的两个字母，删除后新的字符串再删重复的两个字母，直到不能再删为止
string Solution::removeDuplicates(string S) {
	cout << "S = " << S << endl;
    //思路：遍历这个字符串，每个字符与前一个相比，相同则都删除，不同则留下。
    stack<char> chStack;
    chStack.push(S[0]);
    int i = 1;
    while(i<(int)S.length() && !chStack.empty()){
    // for(int i = 1;i<(int)S.length() && !chStack.empty();i++){
    	cout << "S["<<i<<"] = " << S[i] << ", ";//newStr << endl;
    	cout << "chStacl.top = " << chStack.top() << endl;
    	//取栈顶，和当前元素比较
    	if(S[i++] == chStack.top()){
    		//same,pop
    		chStack.pop();
    	}
    	else{
    		chStack.push(S[i]);
    	}
    	if(chStack.empty() && i<(int)S.length()){
    		chStack.push(S[i++]);
    	}
    }
    string newStr = "";
    while(!chStack.empty()){
    	cout << "newStr = " << newStr << endl;
    	newStr += chStack.top();
    	chStack.pop();
    }
    return newStr;
}

string Solution::removeDuplicates2(string S) {
	cout << "S = " << S << endl;
    //思路：遍历这个字符串，每个字符与前一个相比，相同则都删除，不同则留下。
    stack<char> chStack;
    chStack.push(S[0]);
    int i = 1;
    while(i<(int)S.length() && !chStack.empty()){
    // for(int i = 1;i<(int)S.length() && !chStack.empty();i++){
    	cout << "S["<<i<<"] = " << S[i] << ", ";//newStr << endl;
    	cout << "chStacl.top = " << chStack.top() << endl;
    	//取栈顶，和当前元素比较
    	if(S[i++] == chStack.top()){
    		//same,pop
    		chStack.pop();
    	}
    	else{
    		chStack.push(S[i-1]);
    	}
    	if(chStack.empty() && i<(int)S.length()){
    		chStack.push(S[i++]);
    	}
    }

    stack<char> newStack;
    while(!chStack.empty()){
    	newStack.push(chStack.top());
    	chStack.pop();
    }

    string newStr = "";
    while(!newStack.empty()){
    	newStr += newStack.top();
    	newStack.pop();
    }
    return newStr;
}