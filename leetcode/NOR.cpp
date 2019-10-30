#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void showMatrix(int matrix[5][5],int n);
int allNor(vector<vector<int>> v);

int main(){
	int n;
	vector<vector<int>> arr;
	cin >> n;

	for(int i = 0; i<2; i++){
		vector<int> tmpArr;
		for(int j = 0; j< n ; j++){
			int tmp;
			cin >> tmp;
			tmpArr.push_back(tmp);
		}
		arr.push_back(tmpArr);
	}

	cout << allNor(arr);

	return 0;
}

// int allNor(vector<vector<int>> v){
// 	int result = 0;
// 	vector<vector<int>> matrix;
// 	for(int i = 0; i< (int)v[0].size();i++){
// 		vector<int> line(v.size());
// 		matrix.push_back(line);
// 		// for(int j = 0; j < (int)v[0].size(); j++){
// 		// 	matrix[i][j] = 0;
// 		// }
// 	}
// 	for(int i = 0; i< (int)v[0].size();i++){
// 		for(int j = 0; j < (int)v[0].size(); j++){
// 			if(i<=j){
// 				cout << matrix[i][j] << "," << matrix[j][i] << ", ";
// 				cout << v[0][i] << "+" << v[1][j] << " = " << v[0][i]+v[1][j] << ", ";
// 				matrix[i][j] = v[0][i]+v[1][j];
// 				matrix[j][i] = matrix[i][j];
// 				cout << matrix[i][j] << "," << matrix[j][i] << endl;

// 				showMatrix(matrix,(int)v.size());
// 			}
// 			result ^= matrix[i][j];
// 		}
// 	}

// 	showMatrix(matrix,(int)v.size());
	
// 	return result;
// }

// void showMatrix(vector<vector>int matrix[5][5],int n){
// 	cout << endl;
// 	for(int i = 0; i< n;i++){
// 		for(int j = 0; j < n; j++){
// 			cout << matrix[i][j]  << " ";
// 		}
// 		cout << endl;
// 	}
// }