#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> group(int n, vector<int> force);

int main(){
	int arrNum;
	vector<int> numArr;
	vector<vector<int>> forceArr;

	cin >> arrNum;
	for(int i = 0; i< arrNum ; i++){
		int n,tmp;
		vector<int> force;
		cin >> n;
		numArr.push_back(n);
		for(int j = 0; j< n ; j++){
			cin >> tmp;
			force.push_back(tmp);
		}
		forceArr.push_back(force);
	}

	for(int i = 0; i < (int)forceArr.size(); i++){
		vector<int> result = group(numArr[i],forceArr[i]);
		cout << result[0] << " " << result[1] << endl;
	}
	return 0;
}

vector<int> group(int n, vector<int> force){
	//排序，然后把前后两个放进一组，直到数量达到一半
	int front,rear,count=0;
	front = 0;
	rear = n-1;

	sort(force.begin(),force.end());
	// force.sort();
	vector<int> result;
	result[0] = 0;
	result[1] = 0;

	while(front < rear){
		if(count < n/2){
			result[0] += force[front++]+force[rear--];
			count += 2;
		}
		else{
			result[1] += force[front++]+force[rear--];
		}
	}

	if(n%2 == 1){//奇数，则中间剩下一个
		if(result[0]>result[1]) result[0]+=force[n/2];
		else result[1]+=force[n/2];

	}
	return result;
}