#include<iostream>
#include<vector>
using namespace std;

int maxPerfectSeqLen(vector<int> seq);
int main(){
	int T;
	vector<vector<int>> allSeq;
	cin >> T;

	for(int i = 0; i< T; i++){
		int n ;
		vector<int> seq;
		cin >> n;
		for(int j = 0; j< n; j++){
			int tmp;
			cin >> tmp;
			seq.push_back(tmp);
		}
		allSeq.push_back(seq);
	}
	for(int i = 0; i< (int)allSeq.size(); i++){
		cout << maxPerfectSeqLen(allSeq[i]) << endl;
	}

	return 0;
}

int maxPerfectSeqLen(vector<int> seq){
	int len = 1,maxlen = 1;//,start = 1;
	vector<int> diff(seq.size());
	diff[0] = 0;
	for(int i = 1; i< (int)seq.size(); i++){
		diff[i] = seq[i] - seq[i-1];
		cout << diff[i] << " ";
	}
	cout << endl;

	for(int i = 1; i< (int)seq.size(); i++){
		cout << diff[i] <<", " << len << ", " << maxlen << endl;

		if(diff[i] >= 0){
			len++;
		}
		else{
			maxlen = maxlen > len ? maxlen : len;
			len = 1;
		}
	}
	maxlen = maxlen > len ? maxlen : len;
	maxlen = maxlen==1?0:maxlen;
	return maxlen;
}