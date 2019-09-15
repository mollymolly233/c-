#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int uploadFile(int &time,int n,map<int,int> m);

int main(){
	int n;
	cin >> n;
	map<int,int> m;
	for(int i = 0; i < n; i++ ){
		int tmp1,tmp2;
		cin >> tmp1 >> tmp2;
		m.insert(make_pair(tmp1,tmp2));
	}
	int time = 1;
	int num = uploadFile(time, n, m);
	cout << time << " " << num << endl;
	return 0;
}

/*
n批文件
加入队列t秒
文件个数c个
一秒传输一个
*/
int uploadFile(int &currTime,int n,map<int,int> m){
	int maxFileNum = 0;
	int currentNum = 0;

	while(true){
		cout << "time = " << currTime << ", ";
		cout << "m[currTime]" << m[currTime] << ", ";
		cout << "maxFileNum = " << maxFileNum << endl;

		if(m[currTime]>0){
			currentNum += m[currTime];
			maxFileNum = maxFileNum>currentNum?maxFileNum:currentNum;
			m.erase(currTime);
		}
		currTime++;
		if(currentNum>0) --currentNum;
		if(m.empty()){
			break;
		}
	}
	currTime += currentNum;

	return maxFileNum;
}