#include<stack>
#include <utility>
#include "LinkList.h"
#include<map>
using namespace std;

void showVecArr(std::vector<int> v);
class Solution{
public:
	ListNode* removeZeroSumSublists(ListNode* head);
};

int main(){
	vector<int> vec = {2,1,5};
	Solution solution;
	ListNode *head = initLinkList(vec);
	showList(head);

	insertLinkListTail(4,head);
	showList(head);

	ListNode* result = solution.removeZeroSumSublists(head);
	showList(result);

	destroyLinkList(head);
	showList(head);
	return 0;
}

ListNode* Solution::removeZeroSumSublists(ListNode* head){
	vector<int> list,stack,tmp,preSum = 0;
	multimap<int,ListNode*> m;//sum,node
	ListNode *p = head;
	int sum = 0,loc = 0;
	//建立反向查找的hash表，以及前缀和数组
	while(p){
		list.push_back(p->val);
		sum += p->val;
		preSum.push_back(sum);
		m.insert(make_pair(sum,p));
		p = p->next;
	}

	//遍历链表，查找相同的元素的位置，把中间的元素都删掉。
	p = head;
	int i = 0;
	while(p){
		int curr = list[i];
		multimap<int,int>::iterator iter = m.find(preSum[i]);
		if(iter != m.end()){
			p->next = q->next;
			ListNode *q = iter->second;
		}
		p = p->next;
		i++;
	}
	return head;
}

void showVecArr(vector<int> v){
	cout << endl << "vector arr : ";
	for(int i = 0; i < (int)v.size(); i++){
		cout << v[i] << ", ";
	}
	cout << endl;
}
