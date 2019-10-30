#include<iostream>
#include<vector>
using namespace std;

bool ifChangable(vector<int> hi,int m);
int main(){
	int T;
	cin >> T;

	vector<vector<int>> his;
	vector<int> ms;

	for (int i = 0; i < T; ++i)
	{
		int n,m;
		vector<int> hi;
		cin >> n >> m;
		for (int j = 0; j < n; ++j)
		{
			int tmp;
			cin >> tmp;
			hi.push_back(tmp);
		}
		ms.push_back(m);
		his.push_back(hi);

		if(ifChangable(hi,m))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	// for (int i = 0; i < T; ++i)
	// {
	// 	if(ifChangable(his[i],ms[i]))
	// 		cout << "YES" << endl;
	// 	else
	// 		cout << "NO" << endl;
	// }




	return 0;
}


bool ifChangable(vector<int> hi,int m){
	int sum = 0;
	for (int i = 0; i < (int)hi.size(); ++i){
		sum += hi[i];
	}
	// cout << "sum = " << sum << endl;
	sum += m;//一共有sum块积木，可以分布给hi.size()个堆
	// cout << "sum + m = " << sum << endl;

	//所以至少要有0+
	1+2+...hi.size()-1个积木才可以。不然就不行

	int minSize = (int)(hi.size()-1)*(int)hi.size()/2;
	// cout << "hi.size() = " << hi.size() << endl;
	// cout << "min size = " << minSize << endl;
	return sum >= minSize;

	// return false;
}