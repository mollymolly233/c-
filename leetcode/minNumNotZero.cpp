#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000000000

using namespace std;
void minNumNotZero(int n, int k, vector<int> arr);
 int main(){
 	int n,k;
 	vector<int> arr;
 	cin >> n >> k;
 	for(int i = 0; i<n ; i++){
 		int tmp;
 		cin >> tmp;
 		arr.push_back(tmp);
 	}
 	minNumNotZero(n,k,arr);
 	return 0;
 }

 void minNumNotZero(int n, int k, vector<int> arr){
 	sort(arr.begin(),arr.end());
 	// cout << arr[0] << endl;
 	int min = 0;
 	int count = 0;
 	// cout << arr.size() << endl;
 	for(int i = 0; i< (int)arr.size() && i< k; i++){
 		if(arr[i]-min != 0){
 			cout << arr[i]-min << endl;//arr[i] << "-" << min << "= " << 
 			min = arr[i];
 			count ++;
 		}
 	}
 	while(count++ < k){
 		cout << 0 << endl;
 	}

 	// for(int i = 0; i< k; i++){
 	// 	// sort(arr.begin(),arr.end());
 	// 	int min = MAX;
 	// 	for(int j = 0; j<n; j++){
 	// 		if(arr[j] != 0){
 	// 			min = min<arr[j]?min:arr[j];
 	// 		}
 	// 	}
 	// 	if(min == MAX){
 	// 		min = 0;
 	// 		cout << min << endl;
 	// 		continue;
 	// 	}
 	// 	else{
 	// 		cout << min << endl;
 	// 	}

 	// 	for(int j = 0; j<n; j++){
 	// 		if(arr[j] != 0){
 	// 			arr[j] -= min;
 	// 		}
 	// 	}
 	// }
 }