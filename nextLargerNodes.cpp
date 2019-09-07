#include<iostream>
#include<vector>
#include<stack>
#include <utility>

using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};
void showList(ListNode *head);
void showVecArr(vector<int> v);
class Solution{
public:
	vector<int> nextLargerNodes(ListNode* head);
	vector<int> nextLargerNodes2(ListNode* head);
	vector<int> nextLargerNodes3(ListNode* head);
	ListNode *initLinkList(vector<int> vec);
	void insertLinkListHead(int val,ListNode *&head);
	void insertLinkListTail(int val,ListNode *&head);
	void destroyLinkList(ListNode *&head);
};

int main(){
	vector<int> vec = {2,1,5};
	Solution solution;
	ListNode *head = solution.initLinkList(vec);
	showList(head);

	solution.insertLinkListTail(4,head);
	showList(head);

	vector<int> result = solution.nextLargerNodes3(head);
	showVecArr(result);

	solution.destroyLinkList(head);
	showList(head);
	return 0;
}

/**
给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。
每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。
返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。

注意：在下面的示例中，诸如 [2,1,5] 这样的输入（不是输出）是链表的序列化表示，其头节点的值为 2，第二个节点值为 1，第三个节点值为 5 。
示例 1：

	输入：[2,1,5]
	输出：[5,5,0]

示例 2：

	输入：[2,7,4,3,5]
	输出：[7,0,5,5,0]

示例 3：

	输入：[1,7,5,1,9,2,5,1]
	输出：[7,9,9,9,0,5,0,0]

提示：

    对于链表中的每个节点，1 <= node.val <= 10^9
    给定列表的长度在 [0, 10000] 范围内

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-node-in-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
vector<int> Solution::nextLargerNodes(ListNode* head){
//O(n^2)的算法：遍历链表，内层再遍历当前结点后面的结点。
	//挨个比较，找第一个比自己大的，塞入返回值数组中
	ListNode *p = head;
	ListNode *q = NULL;
	vector<int> arr;
	while(p){
		q = p->next;
		while(q){
			if(q->val > p->val){
				arr.push_back(q->val);
				break;
			}
			else{
				q = q->next;
			}
		}
		if(!q){
			arr.push_back(0);
		}
		p = p->next;
	}
	return arr;
}


vector<int> Solution::nextLargerNodes2(ListNode* head){
//3个结构：原链表，结果数组，中间存储的栈
	ListNode *p = head;
	vector<int> arr;
	stack<pair<int,int>> sta;//存储值和下标，用于反查
	int count = 0;

	while(p){
		arr.push_back(0);//
		while(!sta.empty() && sta.top().first < p->val){
			//栈顶>当前元素，出栈，栈顶找到了自己的第一个lager元素，把栈顶值对应位置的arr标为当前元素
			arr[sta.top().second] = p->val;
			sta.pop();
		}
		//栈顶<当前元素，栈顶的lager还需要等待，则把当前元素压入栈，或栈空时
		sta.push(make_pair(p->val,count++));
		p = p->next;
	}
	return arr;
}

vector<int> Solution::nextLargerNodes3(ListNode* head){
	vector<int> res,sta;
	//链表转成数组
	while(head){
		res.push_back(head->val);
		head = head->next;
	}

	//遍历每个元素，找当前元素的next_lager，从栈里找，栈顶到栈底，从小到大。
	//所以比当前小的全都出栈，因为以后的元素会先找与当前比，如果比当前大才会继续往后比
	//现在比当前小的这些比不过当前的，也不会比那个比当前还大的更大，没有必要再比较一次了。动态规划的思想：把之前做过的努力保留下来。
	for(int i = res.size()-1; i>=0; i--){
		int current = res[i];
		while(!sta.empty() && sta.back()<=current){
			sta.pop_back();
		}
		
		res[i] = sta.empty()?0:sta.back();
		sta.push_back(current);
	}
	return res;
}


void showList(ListNode *head){
	cout << endl << "List: ";
	while(head){
		cout << head->val << ", ";
		head = head->next;
	}
	cout << endl;
}

void showVecArr(vector<int> v){
	cout << endl << "vector arr : ";
	for(int i = 0; i < (int)v.size(); i++){
		cout << v[i] << ", ";
	}
	cout << endl;
}

ListNode *Solution::initLinkList(vector<int> vec){
	if(vec.size() == 0) return NULL;
	ListNode *head = new ListNode(vec[0]);
	ListNode *p = head;
	for(int i = 1;i<(int)vec.size();i++){
		cout << "vec[" << i << "] = " << vec[i] << endl;
		//因为函数外还要使用，所以不能简单的声明一个该类型的变量，而应该用堆里的内存，要么new 要么malloc
		ListNode* node = new ListNode(vec[i]);
		p->next = node;
		p = node;
	}
	return head;
}

//头插
void Solution::insertLinkListHead(int val,ListNode *&head){
	ListNode *node = new ListNode(val);
	// node->val = val;
	node->next = head;
	head = node;
}

//尾插
void Solution::insertLinkListTail(int val,ListNode *&head){
	ListNode *p = head;
	ListNode *pre = NULL;
	while(p){
		pre = p;
		p = p->next;
	}

	ListNode *node = new ListNode(val);
	pre->next = node;
	if(!head){
		head = node;
	}
}

void Solution::destroyLinkList(ListNode *&head){
	if(!head) return;
	ListNode *p = NULL;
	while(head){
		p = head->next;
		delete head;
		head = p;
	}
}