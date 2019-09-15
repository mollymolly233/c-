#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxScore(int n, vector<int> arr);

int main(){
	int n;//,k;
	cin >> n;
	vector<int> arr;
	for(int i = 0; i<n; i++){
		int tmp;
		cin >> tmp ;
		arr.push_back(tmp);
	}

	// showVector(arr);
	int num = maxScore(n, arr);
	cout << num << endl;

	return 0;
}

int maxScore(int n, vector<int> arr){
	//首尾两个指针，分别向中间取，每次取大的。算奇数次取出来的和
	int i = 0;
	int j = arr.size()-1;
	int sum = 0;
	int count = 0;
	while(i<=j){
		++count;
		int max = arr[i]>arr[j]?arr[i++]:arr[j--];
		if(count%2 == 1){
			sum += max;
		}
	}
	return sum;
}