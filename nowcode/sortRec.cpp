#include<iostream>
#include<map>
#include<vector>
using namespace std;

void showVector(vector<int> arr);
void sortRec(int N);

int main(){
	int N = 0;
	cin >> N;
	sortRec(N);
	return 0;
}

//先按面积排序
//面积相同则按宽高比，高的在前面 宽高比= min(W/H,H/W)
//宽高比相同的据行，按宽排序
void sortRec(int N){
	map<int,vector<int>> areaMap;
	for(int i = 0;i< N; i++){
		int W,H;
		cin << W << H;
		if(W <= 0 || H>100) return;
		int ratio = W/H>H/W?W/H:H/W;
		vector<int> curr{W*H, ratsio, W, H};
		showVector(curr);
	}
}


void showVector(vector<int> arr){
	cout << endl << "vector: " ;
	for(int i = 0; i<(int)arr.size(); i++){
		cout << arr[i] << ", ";
	}
	cout << endl;
}
