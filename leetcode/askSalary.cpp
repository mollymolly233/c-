#include<iostream>
#include<vector>
#include<map>
using namespace std;


void askSalary(vector<int> salary,vector<int> ks);
int main(){
	int n,m;
	vector<int> salary;
	vector<int> ks;
	cin >> n >> m;
	for(int i = 0; i< n; i++){
		int xi;
		cin >> xi;
		salary.push_back(xi);
	}
	for(int i = 0; i< m ;i++){
		int k;
		cin >> k;
		ks.push_back(k);
	}
	askSalary(salary,ks);

	return 0;
}

void askSalary(vector<int> salary,vector<int> ks){
	map<int,int> m;
	for(int i = 0; i< (int)salary.size(); i++){
		// if(m[salary[i]]){
			m[salary[i]]++;
		// }
		// else{
		// 	m[salary[i]] = 1;
		// }
	}
	for(int i = 0; i< (int)ks.size(); i++){
		if(m[ks[i]]){
			cout << m[ks[i]] << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
}