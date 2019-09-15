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
		cin >> tmp;
		arr.push_back(tmp);
	}
	cin >> k;

	showVector(arr);
	int num = threeSum(n, arr, k);
	cout << endl << num << endl;



	return 0;
}

int threeSum1(int n, vector<int> arr, int k){
	// map<int,vector<int>> m;
	int count;
	//排序，为了不重复
	sort(arr.begin(),arr.end());
	//一个数从头遍历起，其它两个数用两个指针分别指向后面所有数的首尾
	for (int l = 0; l < (int)arr.size(); ++l){
		int i = l+1;
		int j = (int)arr.size()-1;
		while(i<j){
			cout << "arr[" << i << "] + arr[" << j << "] + arr[" << l << "] = " ;
			cout << arr[i] << "+" << arr[j] << "+" << arr[l] << " = " << arr[i]+arr[j]+arr[l];
			if(arr[i]+arr[j]+arr[l] >= k) {j--;cout << " >=";}
			else{//小于了，找到一个，则移动i，此时和又变大，再去移动j找
				cout << "<" ;
				count+=j-i;
				++i;
			}
			cout  << k << endl;
		}
	}
	return count;
}


int threeSum(int n, vector<int> arr, int k){
	// map<int,vector<int>> m;
	int count;
	sort(arr.begin(),arr.end());

	for (int l = 0; l < (int)arr.size()-2; ++l){
		for (int i = l+1; i < (int)arr.size()-1; ++i){
			for (int j = i+1; j < (int)arr.size(); ++j){
				if(arr[i]+arr[j]+arr[l] < k){
					count ++;
				}
				else{
					break;
				}
			}
		}
	}
	return count;
}


void showVector(vector<int> arr){
	cout << endl << "vector: " ;
	for(int i = 0; i<(int)arr.size(); i++){
		cout << arr[i] << ", ";
	}
	cout << endl;
}
