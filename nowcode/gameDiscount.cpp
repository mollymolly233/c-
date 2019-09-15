#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gameDiscount(int n,int x,vector<vector<int,int,int>> arr);

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> arr;
	for(int i = 0; i<n; i++){
		int t1,t2,t3;
		cin >> t1 >> t2 >> t3;
		vector<int> row = {t1,t2,t3};
		arr.push_back(row);
	}

	// showVector(arr);
	int num = gameDiscount(n, x, arr);
	cout << num << endl;

	return 0;
}

int gameDiscount(int n,int x,vector<vector<int,int,int>> arr){
	//暴力破解，遍历当前的arr，先默认当前元素进入候选中，计算其金额和快乐
	//动态规划
}