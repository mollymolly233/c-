#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;
void cutSeq(string str);

int main(){
	string str;
	cin >> str;
	cutSeq(str);


	return 0;
}

void cutSeq(string str){
	//输入一段字符串，切割成多个字符串，使得每个字母只在其中的一段里存在
	//输出每段的长度。
	//思路：一个hash，先把每个字母的最开始位置和最后位置记录下来，然后从第一个字母开始，探测开始结束下标区间内的字母的结束下标，然后扩展这段的结束下标
	map<char,int> endm;
	for(int i  = 0; i< (int)str.length(); i++){
		if(endm[str[i]] < i) endm[str[i]] = i;
	}

	int maxPos = endm[str[0]];
	int start = 0;
	for(int i  = 1; i< (int)str.length(); i++){
		if(i > maxPos){
			cout << maxPos-start+1 << " ";
			start = i;
			maxPos = endm[str[i]];
		}
		if(endm[str[i]] > maxPos){
			maxPos = endm[str[i]];
		}
	}
	cout << maxPos-start+1;
}