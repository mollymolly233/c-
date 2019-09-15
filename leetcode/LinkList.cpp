// struct ListNode{
// 	int val;
// 	ListNode *next;
// 	ListNode(int x): val(x),next(NULL){}
// };
#include "LinkList.h"

void showList(ListNode *head){
	cout << endl << "List: ";
	while(head){
		cout << head->val << ", ";
		head = head->next;
	}
	cout << endl;
}

ListNode *initLinkList(std::vector<int> vec){
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
void insertLinkListHead(int val,ListNode *&head){
	ListNode *node = new ListNode(val);
	// node->val = val;
	node->next = head;
	head = node;
}

//尾插
void insertLinkListTail(int val,ListNode *&head){
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

void destroyLinkList(ListNode *&head){
	if(!head) return;
	ListNode *p = NULL;
	while(head){
		p = head->next;
		delete head;
		head = p;
	}
}