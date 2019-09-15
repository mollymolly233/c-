#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void showVector(vector<int> arr);
int threeSum(int n, vector<int> arr, int k);

int main(){
	int n,k;
	cin >> n;
	vector<int> arr;
	for(int i = 0; i<n; i++){
		int tmp;
		cin >> tmp ;
		arr.push_back(tmp);
	}

	showVector(arr);
	int num = maxScore(n, arr);
	cout << num << endl;



	return 0;
}

int maxScore(int n, vector<int> arr){
	//首尾两个指针，分别向中间取，每次取大的。算奇数次取出来的和
		
}
/*
n批文件
加入队列t秒
文件个数c个

一秒传输一个

*/