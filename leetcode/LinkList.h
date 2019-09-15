#include<vector>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};
ListNode *initLinkList(vector<int> vec);
void insertLinkListHead(int val,ListNode *&head);
void insertLinkListTail(int val,ListNode *&head);
void destroyLinkList(ListNode *&head);
void showList(ListNode *head);