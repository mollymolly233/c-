#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int leastDelay(int n,multimap<int,int> deadlineCost);
void showMap(multimap<int,int> m);

int main(){
	int n;
	multimap<int,int> deadlineCost;

	int tmp1,tmp2;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> tmp1 >> tmp2;
		deadlineCost.insert(make_pair(tmp1,tmp2));
	}
	showMap(deadlineCost);

	int days = leastDelay(n,deadlineCost);
	showMap(deadlineCost);
	cout << days << endl;

	return 0;
}

int leastDelay(int n,multimap<int,int> deadlineCost){
	int leastDelay = 0;
	//按照截至天数来完成
	int current = 0;
	multimap<int,int>::iterator iter = deadlineCost.begin();
	while(iter != deadlineCost.end()){
		int delay = current+iter->second - iter->first;
		current += iter->second;
		if(delay>0) leastDelay+=delay;
		iter++;
	}
	return leastDelay;
}

void showMap(multimap<int,int> m){
	multimap<int,int>::iterator iter = m.begin();
	cout << endl << "map:" << endl;
	while(iter != m.end()){
		cout << iter->first << "," << iter->second << endl;
		iter++;
	}
	cout << endl;
}