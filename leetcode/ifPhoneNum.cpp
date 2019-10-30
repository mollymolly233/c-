#include<iostream>
#include<vector>

using namespace std;
bool ifPhoneNum(int strlen, string str);

int main(){
	int arrNum,strlen;
	string str;
	vector<int> strlenArr;
	vector<string> strArr;

	cin >> arrNum;
	for(int i = 0; i< arrNum ; i++){
		cin >> strlen;
		cin >> str;
		strlenArr.push_back(strlen);
		strArr.push_back(str);
	}

	for(int i = 0; i < (int)strArr.size(); i++){
		if(ifPhoneNum(strlenArr[i],strArr[i]))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

bool ifPhoneNum(int strlen, string str){
	if(strlen<11) return false;
	//经过n次任意删除一个字符能否变为一个11位8开头的号码
	//strlen-n+1开头的串里，至少要有一个8，则可以通过删除前面的字符来得到一个8开头的，再删除后面的任意字符达到11位即可
	//若str-n开头里没有8，则说明把前面删完了，位数已经少于11了都不能构成8开头的
	string head = str.substr(0,strlen-11+1);
	for(int i = 0; i < (int)head.size(); i++){
		if(head[i] == '8') return true;
	}
	return false;
	// bool result = false;
	// return result;
}