/*
求一个二叉树的最小深度
*/
#include<iostream>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>
#include<math.h>
#define MAX_INT 2147483647
// #define INT_MAX 2147483647
// #define INT_MIN -2147483648

using namespace std;

typedef struct TreeNode{
	int value;
	TreeNode *left,*right;
}TreeNode;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


void showTree(TreeNode* root);
void showList(ListNode* L);
void showArr(vector<int> arr);


class Solution {
public:
    int run(TreeNode *root) {
    	if(!root){
    		return 0;
    	}
    	//层次遍历，找最小深度
    	queue<TreeNode*> que;//队列，用于层次遍历
    	que.push(root);//根入队
    	TreeNode *last = root;//指向一层的最后一个结点，用于标识层数是不是应该增加了
    	int depth = 1;//层数初始为1，因为若根节点不空至少有一层
    	while(que.size()){//遍历队列，直到队空
    		TreeNode *top = que.front();//队首出队
    		que.pop();
    		if(top->left) que.push(top->left);//若队首左右孩子存在则进队
    		if(top->right) que.push(top->right);
    		if(!top->left && !top->right){//队首的左右孩子都空了，则说明队首是一个叶子结点，此时停止遍历
    			return depth;
    		}
    		//队首有孩子，继续遍历
    		if(last == top){//队首是当前层的最后一个结点，但此时队列还不空，则层数++，并且last指向当前的队尾，即下一层的最后一个结点。
    			depth++;
    			last = que.back();
    		}
    	}
    	return depth;
    }
    /*
	Evaluate the value of an arithmetic expression in Reverse Polish Notation.
	Valid operators are+,-,*,/. Each operand may be an integer or another expression.
	Some examples: 
    */
    int evalRPN(vector<string> &tokens) {
    	//逆波兰式，后缀表达式，计算。
    	stack<int> operand_stack;
    	//遍历vector
    	set<string> operator_set = {"+","-","*","/"};
    	for(vector<string>::iterator iter = tokens.begin();iter != tokens.end();iter++){
    		//if(find(operator_set.begin(),operator_set.end(),*iter)){
			if(operator_set.find(*iter)!= operator_set.end()){
    			//遇到操作符就取出栈顶两个元素，计算后压栈，直到字符串序列空
    			int operand1 = operand_stack.top();
    			operand_stack.pop();
    			int operand2 = operand_stack.top();
    			operand_stack.pop();
    			operand_stack.push(calculate(*iter,operand2,operand1));
    		}
    		else{//遇到数字则放入operand栈中
    			operand_stack.push(atoi((*iter).c_str()));
    		}
    	}
    	
        return operand_stack.top();
    }
    int calculate(string operator_str , int operand1 , int operand2){
    	if(operator_str == "+") return operand1+operand2;
    	if(operator_str == "-") return operand1-operand2;
    	if(operator_str == "*") return operand1*operand2;
    	if(operator_str == "/") return operand1/operand2;
    	return -1;
    }

	//两数之和，给定一个数组和一个int，求数组中两个值家和为给定int的两个下标
    vector<int> twoSum(vector<int>& nums, int target) {
        //思路：遍历数组，用target-当前值，然后在剩下的数里查找这个数，这样时间复杂度为n*n
        //思路2：先对数组排序，时间复杂度为nlogn，，然后遍历数组，用target-当前值，然后在剩下的数据里查找这个数,时间复杂度为logn
        // map<int,int> position;//记录当前的顺序下标
        // for(int i = 0;i<nums.size();i++){
        //
        // }

        int count = 0;
        cout << target << endl;
        vector<int>::iterator iter = nums.begin();
        vector<int> result;
        while(iter != nums.end()){
        	// cout << nums[count];
            int left = target - *iter;
            cout << count << ","<< *iter << "," << left <<endl;
            // iter++;
            vector<int>::iterator second = nums.begin();
            second = find(++iter,nums.end(),left);
            if(second != nums.end()){
            	result.push_back(count);
            	result.push_back(second-nums.begin());
            	return result;
            }
            // iter++;
            count ++;
        }
        
        return result;
    }

    //给定两个链表表示两个数，每个链表从个位开始表示。例3->2->4 代表423，求两数之和
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //两个链表同时遍历，用一个其它的变量来记录进位
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *l3 = NULL;//用于指向新的链表的尾部
        int cat = 0;
        int num = 0;

        while(p1 && p2){//因为不知道l1 l2谁长，所以两个都存在的时候才做相加，只要一个空了，就停止相加。
        	num = cat+p1->val+p2->val;
        	//cout << p1->val << "+" << p2->val << " = " << num ;
        	if(num>9){//如果进位加上两数对应位之和>9了，需要进位，则cat设置为1，num值本身-10
        		cat = 1;
        		num-=10;
        	}
        	else{
        		cat = 0;
        	}
        	p1->val = num;//把新的数放在p1的位置上，
        	l3 = p1;//l3指向新链的尾部
        	p1 = p1->next;
        	p2 = p2->next;
        	//cout << ",cat = " << cat << endl;
        }
        while(p1){//p2空了，则直接把cat加到p1后面的一位上，并返回p1这条链。
        	num = p1->val + cat;
        	//cout << p1->val << "+" << cat << " = ";
        	cat = num>9?1:0;
        	num = num>9?(num-10):num;
        	p1->val = num;
        	l3->next = p1;
        	l3 = l3->next;
        	p1 = p1->next;
        	//cout << num << ",cat = " << cat << endl;
        }
        while(p2){//p1空了，则把链表接到p2上，并且把p2的下一位加上cat
        	num = p2->val + cat;
        	//cout << p2->val << "+" << cat << " = ";
        	cat = num>9?1:0;
        	num = num>9?(num-10):num;
        	p2->val = num;
        	l3->next = p2;
        	l3 = l3->next;
        	p2 = p2->next;
        	//cout << num << ",cat = " << cat << endl;
        }
        if(cat == 1){
        	//ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));//释放空间的函数与分配空间的函数不对应，
            ListNode *newNode = new ListNode(1);//释放时用的delete，所以分配时要用new，并且ListNode这个结构体只有一种构造函数，就是ListNode(n),写在定义里的
        	l3->next = newNode;
        }
        return l1;
    }

    //给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。例abdacd 返回3：abc，bbbb返回1
    int lengthOfLongestSubstring1(string s) {
    	//思路，遍历字符串，遇到一个字符就去已有的字符中查找
    	string exitstStr = "";
    	int max_len = 0;
    	for(unsigned int i = 0;i<s.length();i++){
    		cout << endl << "--" << s[i] << "--" << endl;
    		cout << "exitstStr = " << exitstStr << endl;
    		cout << exitstStr.find_first_of(s[i]) << endl;
    		int pos = (int)exitstStr.find_first_of(s[i]);
    		cout << "find in " << pos << endl;
    		if(pos == -1){
    			exitstStr = exitstStr+s[i];
    			cout << "not find" << endl;
    		}
    		else{
    			max_len = max_len>(int)exitstStr.length()?max_len:(int)exitstStr.length();
    			exitstStr = exitstStr.substr(pos+1) + s[i];
    			cout << "find,max = " << max_len << endl;
    		}

    	}
    	max_len = max_len>(int)exitstStr.length()?max_len:(int)exitstStr.length();
    	return max_len;
    }
    //给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。例abdacd 返回3：abc，bbbb返回1
    int lengthOfLongestSubstring(string s) {
    	//思路，遍历字符串，遇到一个字符就去已有的字符中查找
    	int max_len = 0;
    	int start = 0;
    	for(int i = 1;i<(int)s.length();i++){
    		cout << endl << "--" << s[i] << "--" << endl;
    		cout << "start = " << start << endl;
    		int pos = s.find(s[i],start);
    		cout << "find in " << pos << endl;
    		if(pos<i && pos>=0){
    		// if(pos == -1 || pos >= i){//没找到就继续
    		// 	// exitstStr = exitstStr+s[i];
    		// 	cout << "not find" << endl;
    		// }
    		// else{//找到了就更新start
    			// max_len = max_len>(int)exitstStr.length()?max_len:(int)exitstStr.length();
    			// exitstStr = exitstStr.substr(pos+1) + s[i];
    			int current_len = i-start;
    			max_len = max_len>current_len?max_len:current_len;
    			start = pos+1;
    			cout << "find,max = " << max_len << endl;
    		}

    	}
    	int current_len = s.length()-start;
		max_len = max_len>current_len?max_len:current_len;
    	// max_len = max_len>(int)exitstStr.length()?max_len:(int)exitstStr.length();
    	return max_len;
    }


    //找两个有序数组的中位数
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //合并两个有序数组
        vector<int> nums;
        int p1 = 0;
        int p2 = 0;
        int len1 = (int)nums1.size();
        int len2 = (int)nums2.size();
        if(len1 == 0 && len2 == 0){
        	return 0.0;
        }
        showArr(nums1);
        showArr(nums2);

        while(p1<len1 || p2<len2){
            if(p1<len1 && p2<len2){//两个数组都没遍历完，则比较当前的大小，把小的数插入新的数组
            	cout << nums1[p1] << " ? " << nums2[p2] << endl; 
                nums.push_back(nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++]);
            }
            else{
	            //其中一个不存在时，直接把另一个剩余的部分接到新数组后面
	            if(p1<len1){
	                nums.push_back(nums1[p1++]);
	            }
	            else{
	                nums.push_back(nums2[p2++]);
	            }
            }
        	showArr(nums);
        }

        showArr(nums);
        
        //根据数组长度计算中位数
        int len = nums.size();
        if(len%2 == 0){//偶数个，中位数为两个数的平均函数
            return ((float)nums[len/2-1]+(float)nums[len/2])/2;
        }
        else{//及数个直接返回中间值
            return (float)nums[len/2];
        }
    }

    //给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
    string longestPalindrome(string s) {
        //暴力解法：时间复杂度为O(n^3)
        //遍历每一个子串看是不是回文，是则和当前最长回文子串比较长度
        //遍历子串n*n
        //判断是否为回文

        //易错解法
        //前后两个指针同时遍历，前序和后序看成两个分离的字符串，找这俩的最长公共子串。易错点倒叙后可能有不是回文的公共子串。比如abcd-cab-dcba 前后的abcd是镜像的，但是中间的cab并不是，所以找出来的这段并不是回文
        //正确解法，找到这种最长公共子串后还需要判断是不是回文，不是的要放弃

        //动态规划，若aba是回文，则cabac也是回文。
        //P(i,j) = true when Si...Sj是回文，=false otherwise.

        //中心展开法
        //回文串是对称的，所以它中心两边的字符串应该完全一样，一个n位的字符串中，有可能有2n+1个这样的中心，所以只需要遍历每一个可能的中心，并判断中心左右的字符串是否相同，相同则更新最长回文串的长度
        //为啥是2n+1，因为回文串有奇数个有偶数个字符，偶数个的时候中心在两个字符中间
        int n = s.size();
        if(n>1000) return "";
        int p1 = 0;
        int p2 = 0;
        int max_len = 0;
        int pos_start = 0;
        int pos_end = 0;
        string new_str = "";
        for(int i = 0;i<2*n-3;i++){
        	p1 = i/2;
        	p2 = (i%2==0)?(p1+1):(p1+2);
        	cout << endl << "center: p1 = " << p1 << ", p2 = " << p2 << ", ";
        	cout << "s["<<p1<<"] = " << s[p1] << ", s["<<p2<<"] = " << s[p2];
        	int len = (i%2==0)?0:1;
        	while(p1<n && p2<n && p1>=0 && p2>=0 && s[p1]==s[p2]){
        		cout << "s["<< p1 << "] = s[" << p2 << "] = " << s[p1] << endl;
        		len +=2;
        		--p1;
        		++p2;
        	}
        	if(max_len<len){//如果当前找到的回文串长度大于之前的，则更新最长回文子串的起止位置信息和长度信息
        		max_len = len;
        		pos_start = p1+1;
        		pos_end = p2-1;
        	}
        	cout << endl << "max_len = " << max_len << ", [" << pos_start << "," << pos_end << "]" << endl;
        }

        for(int i = pos_start;i<=pos_end;i++){
        	new_str += s[i];
        }
        return new_str;
    }

    //反转整数
    int reverse(int x) {
        queue<int> que;
        int y =x;//2147483647
        if(x<-2147483647)
        	return 0;
        x = abs(y);
        cout << "abs(" << y << ") = " << x << endl;
        while(x>0){
            int current = x%10;
            que.push(current);
            x/=10;
        }
        int return_value = 0;
        while(!que.empty()){
            int current = que.front();
            que.pop();
            if(return_value>214748364){//溢出
            	return 0;
            }
            return_value = return_value*10+current;
        }

		// cout << "x = "<< x <<",y="<<y<<",reverse(" << y << ") = " << return_value << endl;
        if(return_value<0){//溢出
        	cout << endl << "overflow" << endl;
        	return 0;
        }
        if(y<0){
            return_value = 0-return_value;
        }
        return return_value;
    }
    //把输入的字符串 转变为竖着输出，为z字形的形状的情况下，
    //返回横着输出的顺序。
    string convert(string s, int numRows) {
    	cout << s << endl;
    	int n = s.size();
    	if(numRows<=1 || numRows>=n){
    		return s;
    	}
    	string new_str = "";
    	vector<int> seq;
    	int last = -1;
    	for(int i = 0;i<numRows;i++){//2
    		for(int j = 0; j<=(n/(2*numRows-2)+1);j++){//0
    			for(int k = -1;k<=1;k+=2){//-1
	    			int tmp = k*i+2*j*(numRows-1);//
	    			if(last != tmp && tmp>=0 && tmp<n){
	    				last = tmp;
	    				seq.push_back(tmp);
	    			}
    			}
    		}
    	}

    	cout << "seq:" << endl;
    	for(int i = 0;i<(int)seq.size();i++){
    		cout << seq[i] << " ";
    		new_str += s[seq[i]];
    	}
    	cout << endl;
    	cout << "new_str = " << new_str << endl;
        return new_str;
    }


	/*
	给定一个单词，你需要判断单词的大写使用是否正确。
	我们定义，在以下情况时，单词的大写用法是正确的：

	    全部字母都是大写，比如"USA"。
	    单词中所有字母都不是大写，比如"leetcode"。
	    如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。

	否则，我们定义这个单词没有正确使用大写字母。
	*/
    bool detectCapitalUse(string word) {
    	cout << "word = " << word << endl;
        bool firstCapital = false;
        int small_count = 0;
        int capital_count = 0;
        if(word[0]-'a'<0){
        	firstCapital = true;
        }

        for(int i = 1;i<(int)word.size();i++){
        	if(word[i]-'a'<0){
        		++capital_count;
        	}
        	else{
        		++small_count;
        	}
        }
        if(firstCapital){//首字母大写，则后面要么全小写，要么全大写
        	cout << "first letter capital" << endl;
        	if(small_count>0 && capital_count>0){
        		return false;
        	}
        	else{
        		return true;
        	}
        }
        else{//首字母小写，后面只能全小写
        	cout << "all must be small" << endl;
        	if(small_count+1==(int)word.size()){
        		return true;
        	}
        	else{
        		return false;
        	}
        }
    }

    /*把字符串中的整数识别出来并返回整数的数值
    注意边界值：2147483647(2147483647),2147483648(2147483647),+(0),-(0),000000000(0)
    */
    int myAtoi(string str) {
    	int i = 0;
    	while(i<(int)str.size() && str[i]==' '){//找第一个非空格的字符
    		i++;
    	}

        if((str[i]<'0' || str[i]>'9') && str[i] != '-' && str[i] != '+'  ){//第一个非空字符不是数字，则输出0
        	return 0;
        }

        bool ifPositive = true;
        int num = 0;
        int max = INT_MAX;
        int max_last = INT_MAX%10;
        if(str[i]=='-'){
			ifPositive = false;
			max_last += 1;
        }
        else if(str[i]=='+'){}
        else{
        	num = str[i]-'0';
        }
        i++;
        while(str[i]>='0' && str[i]<='9'){//当后面的字符串都是整数的时候，把这一段截取出来放入新的字符串中
        	// if(num==(INT_MAX/10)){
        		cout << num << "*10 +" << (str[i]-'0') << " = " << num*10+ (str[i]-'0')<< endl << "max = " << max << endl;
        	// }
        	if(num<max/10){
	        	num = num*10+ (str[i++]-'0');
	        	// str_num += str[i++];
	        }
	        else if(num==(max/10)){
	        	if(ifPositive){
	        		if((str[i]-'0')>=max_last){
		        		return INT_MAX;
		        	}
	        	}
	        	else if((str[i]-'0')>=max_last){
		        	return INT_MIN;
	        	}
		        num = num*10+ (str[i++]-'0');
	        }
	        else{
	        	cout << "overflow" << endl;
	        	if(ifPositive) return INT_MAX;
	        	return INT_MIN;
	        }
	        cout << "num = " << num << endl;
        }
        if(num<0){
        	if(ifPositive) return INT_MAX;
        	return INT_MIN;
        }
        if(ifPositive)
        	return num;
    	return -num;
    }
};

int main(){
	Solution solution;

	// cout << solution.myAtoi("-2147483648") << endl;
	int a=5,b; 
	b=a>3&&0; a++;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	/*大小写正确性判断
	string word = "aaa";
	bool result = solution.detectCapitalUse(word);
	cout << word << " : " << result << endl;
	*/


	/*N字形转换
	string s = "ABCDE";
	int numRows = 4;
	solution.convert(s,numRows);
	*/

	// TreeNode node,node1,node2,node3;
	// node.value = 0;
	// node1.value = 1;
	// node2.value = 2;
	// node3.value = 3;
	// TreeNode *root = &node;
	// node.left = &node1;
	// node.right = &node2;
	// node1.left = NULL;
	// node1.right = &node3;
	// node2.left = NULL;
	// node2.right = NULL;
	// node3.left = NULL;
	// node3.right = NULL;
	// showTree(root);

	// int depth = solution.run(root);
	// cout << "depth is " << depth << endl;
	// vector<string> valList = {"2","3","+","3","*"};
	// cout << solution.calculate("+",2,3) << endl;
	// cout << solution.evalRPN(valList)<< endl;

	// vector<int> nums = {3,2,4};
	// cout << nums[0] << endl;
	// int target = 6;
	// vector<int> result = solution.twoSum(nums,target);
	// cout << result[0] << endl;
	// cout << result[1] << endl;

/*
	ListNode lnode1,lnode2,lnode3,lnode4,lnode5,lnode6;
	lnode1.val = 2;
	lnode2.val = 4;
	lnode3.val = 5;
	lnode4.val = 5;
	lnode5.val = 6;
	lnode6.val = 5;
	// lnode1.next = &lnode2;//1->9->8 891
	// lnode2.next = &lnode3;
	lnode3.next = NULL;
	// lnode4.next = &lnode5;//9->2 29
	// lnode5.next = &lnode6;
	lnode6.next = NULL;
	showList(&lnode3);
	showList(&lnode6);

	ListNode * result = solution.addTwoNumbers(&lnode3,&lnode6);
	
	cout << endl << "result =  " ;
	showList(result);
	cout << endl;

	//预期的结果 0->2->9
	*/

	// int max = solution.lengthOfLongestSubstring("avdbfascsdg");
	// cout << "max_len = " << max;

	/*
	vector<int> nums1 = {};
	vector<int> nums2 = {3,4};
	cout << endl << solution.findMedianSortedArrays(nums1,nums2) << endl;
	*/


	/*最长回文子串
	string s = "aaa";
	string new_s = solution.longestPalindrome(s);
	cout << "s = " << s << endl;
	cout << "new_s = " << new_s  << endl;

	short si = -3267;
	unsigned short usi = si;
	cout << "usi = " << usi << endl;
	*/



	/*反转整数
	// int a = -2147483648;
	int a = -263845412;
	int b = solution.reverse(a);
	cout << "reverse(" << a << ") = " << b << endl; 
	*/



	return 0;
}

void showList(ListNode* L){
	cout << endl;
	while(L){
		cout << L->val << " -> ";
		L = L->next;
	}
	cout << "null" << endl;
}

void showTree(TreeNode* root){
	if(!root) return;
	//递归遍历一棵树
	cout << root->value << endl;
	if(root->left) showTree(root->left);
	if(root->right) showTree(root->right);
	return;
}

void showArr(vector<int> arr){
	cout << endl << "arr : ";
	for (int i = 0; i < (int)arr.size(); ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}