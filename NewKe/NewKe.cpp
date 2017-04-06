// NewKe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DynamicProgramming.h"

#include<regex>

#include <map>
#include <string.h>
#include<vector>
#include <algorithm>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#include <iostream>
#include<vector>
#include<string>
#include<map>
#include<stdlib.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////
// NeKe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;


//************************************************************
//-----------------------最小年龄的3个职工--------------------
int main(){
	int n;
	while (cin >> n){
		vector<vector<string> > inf(n, vector<string>(3));
		for (int i = 0; i<n; i++){
			for (int j = 0; j < 3; j++)
				cin >> inf[i][j];
		}
		sort(inf.begin(), inf.end(), [](const vector<string> &e1,vector<string> &e2)->int{});
		//



		for (int k = 3; k<n; k++){
			if (inf[k][2] <= max(inf[0][2], max(inf[1][2], inf[2][2]))){
				if (max(inf[0][2], max(inf[1][2], inf[2][2])) == inf[0][2])
					swap(inf[0], inf[k]);
				else if (max(inf[0][2], max(inf[1][2], inf[2][2])) == inf[1][2])
					swap(inf[1], inf[k]);
				else swap(inf[2], inf[k]);
			}
		}
		for (int s = 0; s < 2; s++){
			if (inf[s][2]>inf[s + 1][2]) swap(inf[s], inf[s + 1]);
			else if (inf[s][2] == inf[s + 1][2] && inf[s][0] > inf[s + 1][0])swap(inf[s], inf[s + 1]);
		}
		if (inf[0][2]>inf[1][2]) swap(inf[0], inf[1]);
		else if (inf[0][2] == inf[1][2] && inf[0][0] > inf[1][0]) swap(inf[0], inf[1]);
		for (int i = 0; i<3; i++){
			for (int j = 0; j < 3; j++)cout << inf[i][j] << ' ';
			cout << endl;
		}
	}
}





////////////////////////////////////////////////////////////////////////////
class Solution {
public:
	typedef struct TreeNode{
		int val;
		TreeNode * left, *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {};

	};
	TreeNode * root=NULL;
	bool VerifySquenceOfBST(vector<int> sequence) {

		for (int i = 0; i<sequence.size(); ++i){
			Insert2Tree(root, sequence[i]);
		}
		vector<int> PostOrder;
		post(root, PostOrder);
		for (int i = 0; i<sequence.size(); ++i){
			if (PostOrder[i] != sequence[i]){
				return false;
			}
		}
		deleteTree(root);
		return true;

	}
	void PostInsert(TreeNode * root,int node){
	    


	}

	void Insert2Tree(TreeNode *root, int node){
		if (root){

			if (node<root->val){
				if (root->left == NULL) root->left = new TreeNode(node);
				else  Insert2Tree(root->left, node);
			}
			else{
				if (root->right == NULL) root->right = new TreeNode(node);
				else  Insert2Tree(root->right, node);
			}
		}
		else{
			this->root = new TreeNode(node);
		}
	}
	void deleteTree(TreeNode * root){
		if (root){
			deleteTree(root->left);
			deleteTree(root->right);
			delete root;
		}
	}
	void post(TreeNode * root, vector<int> &PostOrder){
		if (root){
			post(root->left, PostOrder);
			post(root->right, PostOrder);
			PostOrder.push_back(root->val);

		}
	}
};
int main999(){
	Solution s;
	s.VerifySquenceOfBST({ 4, 8, 6, 12, 16, 14, 10 });

	return 0;
}


////////////////////二叉树层序遍历///////////////////////////////////////////
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
		if (!root)
			return result;

		deque<TreeNode *> dequeTN;
		dequeTN.push_back(root);

		while (dequeTN.size())
		{
			TreeNode* pNode = dequeTN.front();
			dequeTN.pop_front();

			result.push_back(pNode->val);

			if (pNode->left)
				dequeTN.push_back(pNode->left);
			if (pNode->right)
				dequeTN.push_back(pNode->right);
		}
		return result;
	}
};*/

////////////////////////////含最小值函数的栈//////////////////////////////////////
/*定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
// 设置一个正常的栈 stk，用于正常的压栈，弹出，
// 再设置一个存放最小值的栈MIN，栈顶始终保持 stk 栈顶到栈底的最小值，
// 有元素进栈时，先将其压入stk, 这个元素如果小于MIN 栈顶，则将其压入MIN,否则复制 MIN 栈顶压入MIN
// 有元素出栈时，stk 出栈，MIN也出栈，二者保持同步 
// MIN[top]=min{ MIN.top(),value }=min{ stk[1...top] }

class Solution {
public:
	stack<int> stk;
	stack<int> MIN;
	void push(int value) {
		if (stk.empty()){
			stk.push(value);
			MIN.push(value);
		}
		else{
			stk.push(value);
			if (value > MIN.top()){
				MIN.push(MIN.top());

			}
			else{
				MIN.push(value);
			}
		}
	}
	void pop() {
		stk.pop();
		MIN.pop();
	}
	int top() {
		return stk.top();
	}
	int min() {

		return MIN.top();
	}
};*/




//////////////////////////////////////////////////////////////////////
/* 
  输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
  假设压入栈的所有数字均不相等。
  分析：每压栈一个元素，就检查出栈序列，看是否能弹出一些元素，是的话就弹出一些元素，直到不能弹出
        为止，（原因在于，一旦某个元素压栈，则他之前压栈的元素只能反序出栈），
		直到所有元素（pushV）都入栈，如果栈不空的话，继续上次popV 的位置弹栈，一旦popV[j] 与栈顶不匹配
		，则返回false，直到j超出范围或者栈空，
*/
/*
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> stack1;
		int i, j, tmp;
		for (i = 0, j = 0; i<pushV.size() && j<popV.size(); ++i){
			stack1.push(pushV[i]);
			for (; j < popV.size()&&stack1.top() == popV[j]; stack1.pop(), ++j);
			//出栈序列和栈顶匹配的话就将弹栈，直到出栈序列不能匹配为止，
		}
		while (!stack1.empty()){
			tmp = stack1.top();
			if (tmp == popV[j]){
				stack1.pop(); j++;
			}
			else{
				return false;
			}
		}
		if (stack1.empty()) return true;
		else return false;
	}
};
int main(){
	Solution s;
	bool res=s.IsPopOrder({1, 2, 3, 4, 5}, { 4,5,3,2,1 });
	return 0;
}*/

//////////////////////浮点的整数次方 //////////////////////////////////
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	//============================================
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int &k) {
		if (pListHead){
			ListNode *p = FindKthToTail(pListHead->next, k);
			k--;
			if (p)  return p;
			if (k == 0) return pListHead;
			return NULL;
		}
		else{
			return pListHead;
		}
	}
	//====================递归版本=================
	ListNode * newHead;
	int depth = 0;
	ListNode* ReverseList(ListNode* pHead){
		if (pHead){//如果链表为空
			if (pHead->next){//如果没到尾节点
				depth++;
				ListNode * prior = ReverseList(pHead->next);
				if (prior)  prior->next = pHead;
				if ((--depth) == 0) { 
					pHead->next = NULL;
					return newHead; 
				}
				return pHead;
			}else{  // 如果到了尾节点，则给新的头结点赋值
				newHead = pHead;
				return pHead;
			}
		}else{//如果链表为空
			return pHead;
		}
	}
  //=====================迭代版本================
	ListNode* ReverseList_iter(ListNode* pHead) {
		if (!pHead) return pHead;
		ListNode* p = pHead->next, *q = pHead, *tmp = q;
		q->next = NULL;
		while (p){
			tmp = p->next;
			p->next = q;
			q = p;
			p = tmp;
		}
		return q;
	}
	ListNode * CreateList( vector<int> array){
		ListNode * pHead = new ListNode(array[0]);
		ListNode * p = pHead;
		for (size_t i = 1; i < array.size(); i++)
		{
			p->next = new ListNode( array[i] );
			p = p->next;

		}
		return pHead;
	}

};
int main(){
	Solution s;
	ListNode * head=s.CreateList({1,2,3,4,5});
	vector<int> t;
	
	ListNode * rp=s.ReverseList(head);
	return 0;
}*/



//////////////////////浮点的整数次方 //////////////////////////////////
/*  主要用位操作，矩阵的N次方可以在log(N) 复杂度下完成，注意此处N是幂次 
double Power(double base, int exponent) {

	int _exponent = abs(exponent);
	double res = 1, tmp = base;
	int test_bit = 1;
	for (; test_bit != 0; test_bit <<= 1){
		if (test_bit& _exponent){
			res *= tmp;
		}
		tmp *= tmp;
	}
	if (exponent>0)
		return res;
	else return 1 / res;

}
int main(){
	Power(2, -3);

	return 0;
}
*/


//////////////////////////计算变量二进制 1 的个数////////////////////
/*
一个很基本的想法是，我们先判断整数的最右边一位是不是1。
接着把整数右移一位，原来处于右边第二位的数字现在被移到第一位了，
再判断是不是1。这样每次移动一位，直到这个整数变成0为止。现在的问题
变成怎样判断一个整数的最右边一位是不是1了。很简单，如果它和整数1作与运算。
由于1除了最右边一位以外，其他所有位都为0。因此如果与运算的结果为1，
表示整数的最右边一位是1，否则是0。

这个思路当输入i是正数时没有问题，但当输入的i是一个负数时，
不但不能得到正确的1的个数，还将导致死循环。以负数0x80000000为例，
右移一位的时候，并不是简单地把最高位的1移到第二位变成0x40000000，
而是0xC0000000。这是因为移位前是个负数，仍然要保证移位后是个负数，
因此移位后的最高位会设为1。如果一直做右移运算，最终这个数字就会变
成0xFFFFFFFF而陷入死循环。

为了避免死循环，我们可以不右移输入的数字i。首先i和1做与运算，
判断i的最低位是不是为1。接着把1左移一位得到2，再和i做与运算，
就能判断i的次高位是不是1……这样反复左移，每次都能判断i的其中一位是不是1。
基于此，我们得到如下代码：
see:http://blog.csdn.net/wangjun_1218/article/details/4464129
*/
/*
int  NumberOf1(int number) {
	int test_bit = 0x00000001;
	int num=0;
	for (; test_bit != 0; test_bit <<= 1){
		if ((test_bit & number)){
			++num;
		}
	}
	return num;
}
int main(){

	int res=NumberOf1(-16);
	return 0;

}*/

/////////////////////////////剑指offer 二叉树层序遍历 /////////////////////
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:

	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > result;
		queue <TreeNode*> layer;
		TreeNode* tmp;
		vector<int> layer_vec;
		vector<TreeNode *> vec;
		layer.push(pRoot);
		while (!layer.empty()){
           
			while (!layer.empty()){ //把同一层的所有节点都拉出来
				vec.push_back(layer.front());
				layer.pop();
			}
			for (int i = 0; i<vec.size(); ++i){
				if (vec[i]){
					layer_vec.push_back(vec[i]->val);
					if (vec[i]->left) layer.push(vec[i]->left);
					if (vec[i]->right)layer.push(vec[i]->right);
				}
			
			}
			if (layer_vec.size()>0) result.push_back(layer_vec);
			layer_vec.clear();

			vec.clear();

		}
		return result;

	}

};*/




/////////////////////////////剑指offer 旋转数组的最小元素/////////////////////
/*
     初始化一个最小min，如果找到更小的，更新min,用二分法      

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {

		if (rotateArray.size() == 0) return 0;
		int a = 0, b = rotateArray.size() - 1, mid, min = rotateArray[0];
		while (a<=b){
			mid = (a + b) / 2;
			if (min <rotateArray[mid]){
				a = mid + 1;
			}
			else if (min >rotateArray[mid]) {
				b = mid - 1;
				min = rotateArray[mid];
			}
			else{
				a = mid + 1;
			}
		}
		return min;
	}
};

int main(){
	vector<int> nums = {3,4,5,1,2};

	Solution S;
	int a=S.minNumberInRotateArray(nums);
	
	return 0;
}*/

/////////////////////////////剑指offer 双栈模拟队/////////////////////
/*
   双栈模拟队
    1 入队时：stack1 用来存队尾段，如果stack2 空了，则把stack1 所有元素出栈，压入stack2,等待出队
      然后把新的元素压入stack1
	2 出队时：如果stack2 为空，则把stack1 元素弹出并压入stack2,然后从stack2 弹出栈顶元素即队头



class Solution
{
public:
	void push(int node) {
		if (stack2.empty()){  
	    	while (!stack1.empty() ){
			   stack2.push(stack1.top());
			   stack1.pop();
		    }
		}
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			} 
		}
		int ret = stack2.top();
		stack2.pop();
		return ret;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};*/



////////////////////////////剑指offer — build binary tree//////////////////
 /*struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size()<1) return NULL;
		if (vin.size()<1) return NULL;

		if (pre.size() == 1) return new TreeNode(pre[0]);
		if (vin.size() == 1) return new TreeNode(vin[0]);

		int root_val = pre[0];
		vector<int> in_left, in_right, pre_left, pre_right;
		int i, flag = -1;
		for (i = 0; i<vin.size(); ++i){
			if (root_val == vin[i]){
				flag = i;
			}
			else{
	           if (flag == -1) in_left.push_back(vin[i]);
			   else in_right.push_back(vin[i]);
			}
		}
		for (i = 1; i <= flag; ++i){ pre_left.push_back(pre[i]); };
		for (i = flag + 1; i<pre.size(); ++i) pre_right.push_back(pre[i]);


		TreeNode* root = new TreeNode(root_val);
		root->left = reConstructBinaryTree(pre_left, in_left);

		root->right = reConstructBinaryTree(pre_right, in_right);

		return root;

	}
};
int main(){
	Solution S;
	TreeNode*  tree = S.reConstructBinaryTree({ 1, 2, 3, 4 }, { 1, 2, 3, 4 });

	return 0;
}*/

/////////////////////////剑指offer 矩阵查找//////////////////////////////////
/*class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int mid_i,mid_j ,ai,aj,bi,bj;
		for ( ai = 0, aj = 0,bi = array.size() - 1,bj=array[0].size()-1;ai<bi && aj<bj;)
		{
			mid_i = (ai + bi) / 2;
			mid_j = (aj + bj) / 2;
			if (target > array[mid_i][mid_j]){
				ai = mid_i+1;
				aj = mid_j+1;
			}else if (target < array[mid_i][mid_j]){
				bi = mid_i-1;
				bj = mid_j-1;
			}else { 
				return true; 
			}
		}
		int a = 0, b = mid_j,mid;
		while (a<b)  
		{   mid=(a+b)/2;
			if (target>array[mid_i][mid]) a = mid+1;
			else if (target < array[mid_i][mid]) b = mid - 1;
			else return true;
		}
		a = 0; b = mid_i; 
		while (a<b)
		{
			mid = (a + b) / 2;
			if (target>array[mid][mid_j]) a = mid + 1;
			else if (target < array[mid][mid_j]) b = mid - 1;
			else return true;
		}
		return false;
	}
};
int main(){
	vector<vector<int>> array = {
	    { 2, 4, 5, 8, 9, 12, 15, 18, 19, 21 },
		{ 4, 7, 8, 10, 13, 16, 18, 20, 21, 24 },
		{ 7, 9, 11, 12, 14, 19, 22, 24, 25, 28 },
		{ 8, 10, 14, 17, 19, 22, 23, 27, 30, 32 },
		{ 10, 12, 16, 20, 22, 25, 27, 30, 32, 35 },
		{ 11, 13, 17, 23, 25, 28, 31, 32, 35, 38 },
		{ 13, 16, 18, 24, 27, 30, 34, 36, 39, 40 },
		{ 14, 19, 22, 26, 30, 32, 37, 39, 42, 45 },
		{ 15, 21, 25, 29, 33, 34, 40, 43, 44, 47 },
		{ 16, 23, 27, 32, 35, 37, 43, 45, 47, 50 } 
	};
	Solution s;

	cout<<s.Find(5,array );
	return 0;
}*/


////////////////////////////////////////////////////////////////
int _0_1_knapsack(){
	int x, n, m;
	while (cin>>x>>n>>m)
	{  
		vector<string> items(x);
		
	    
		for (size_t i = 0; i < x; i++)
		{
			cin>>items[i];
		}
	}
	return 0;
}

////////////////////////////////////////////////////////////////
int classify_str(){
	int n;
	while (cin>>n)
	{
		vector<string> strs(n);
		vector<map<char, int>> tree_group;
		for (size_t i = 0; i < n; i++)
		{
			cin >> strs[i];

			map<char, int> tmp;
			for (size_t j = 0; j < strs[i].length(); j++)
			{
				if (tmp.find(strs[i][j]) == tmp.end()) tmp[strs[i][j]] = 0;
				else tmp[strs[i][j]] += 1;
				
			}
			int flag = 0;
			for (size_t j = 0; j < tree_group.size(); j++)
			{
				if (tmp == tree_group[j]) flag = 1;

			}
			if (!flag) tree_group.push_back(tmp);
		}
		cout << tree_group.size() << endl;
	}

	return 0;
}



////////////////////////////////////////////////////////////////
int check(vector<int> nums,int pos,int mult){
	if (pos >= nums.size() - 1) {
		if (mult == nums[pos]) return -1;
		else return nums[pos];
	}
	int ret = check(nums, pos + 1, nums[pos] * mult);
	if (ret==-1) {
		return -1;
	}else {
		if (ret*nums[pos] == mult) return -1;
		else return ret*nums[pos];
	}
}

int banlance_num(){
	string num;
	while (cin>>num)
	{
		vector<int> nums(num.length());
		for (size_t i = 0; i < num.length(); i++)
			nums[i] = atoi( to_string(num[i]-'0').c_str() );

		int ret=check(nums,1,nums[0]);
		if (ret != -1) cout << "NO\n";
		else  cout << "YES\n";
	}
	return 0;
}



/////////////////////////////////////////////////////////////////
int min_Rect(){
	int n,x_min=99999999,x_max=-99999999;
	int y_min = 9999999, y_max = -9999999;
	while (cin>>n)
	{
		vector<pair<int, int>>  coord(n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> coord[i].first >> coord[i].second;
		}
		for (size_t i = 0; i < n; i++)
		{
			if (coord[i].first < x_min) x_min = coord[i].first;
			if (coord[i].first>x_max) x_max = coord[i].first;
			if (coord[i].second < y_min) y_min = coord[i].second;
			if (coord[i].second>y_max) y_max = coord[i].second;

		}
		cout << (x_max - x_min)*(y_max - y_min) << endl;
  	}
	return 0;
}

//////////////////////////////////////////////////////////////
bool isTrag(int a, int b, int c){
	if (a + b > c && a + c > b && b + c > a && abs(a - b) < c && abs(a - c) < b && abs(b - c) < a) return true;
	return false;
}
int Assm(){
	int n;
	while (cin>>n)
	{
		vector<int> nums(n);
		int count = 0;
		for (size_t i = 0; i < n; i++)
			cin >> nums[i];
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = i+1; j < n; j++)
			{

				for (size_t k = j+1; k < n; k++)
				{
					if (isTrag(nums[i], nums[j], nums[k])){
						count++;
					}
				}
			}
		}
		cout << count << endl; 
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
int findInt(){
	int a, b, x;
	while (cin>>a>>b>>x)
	{
		if (a >= 0){
			int a1 = a / x,b1=b/x;
			if(a>0) cout << b1 - a1 << endl;
			else   cout << b1 - a1+1 << endl;

		}else
		{
			int p = b / x + 1;
			int n = a / x;
			cout << p + n << endl;
		}
	}

	return 0;
}


////////////////////////////////////////////////////////////////////////////////
int LongestPublicSubstr1(){
	string str1,str2;
	while (getline(cin,str1))
	{
		getline(cin , str2);
		vector<vector<int>> opt(str1.length()+1,
			vector<int>(str2.length()+1,0));
		int i, j,max=0;
		for ( i = 1; i < str1.length()+1; i++)
		{
			for ( j = 1; j < str2.length()+1; j++)
			{
				if (str1[i - 1] == str2[j - 1] && opt[i][j] < opt[i - 1][j - 1] + 1)
				{ 
					opt[i][j] = opt[i - 1][j - 1] + 1;
					if (opt[i][j]>max) max = opt[i][j];
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////////////
/////字符串排序 by WillWu
/*
int main()
{
	string s;
	vector<char> tempChar;
	while (getline(cin, s))
	{
		tempChar.clear();
		int len = s.size();
		for (int j = 0; j<26; j++)
		{
			for (int i = 0; i<len; i++)
			{
				if (s[i] - 'a' == j || s[i] - 'A' == j)
				{
					tempChar.push_back(s[i]);
				}
			}
		}
		for (int i = 0, k = 0; (i<len) && k<tempChar.size(); i++)
		{
			if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z'))
				s[i] = tempChar[k++];
		}
		cout << s << endl;
	}
	return 0;
}*/
////////////////////////////////////////////////////////////////////////////////

/*
int main(){
	int In, Rn;
	while (cin >> In)
	{
		vector<int> I(In);
		for (size_t i = 0; i < In; i++)
			cin >> I[i];
		cin >> Rn;
		map<int, vector<pair<int, int>>> R;
		int tmp;
		for (size_t i = 0; i < Rn; i++)
		{
			cin >> tmp;
			R[tmp] = {};
		}
		string str;
		tmp = 0;
		for (auto r : R)
		{
			for (size_t i = 0; i < In; i++)
			{
				str = to_string(I[i]);
				if (str.find(to_string(r.first)) != -1){
					R[r.first].push_back({ i, I[i] });
				}
			}
			tmp += (R[r.first].size() * 2);
			if (R[r.first].size()) tmp += 2;
		}
		cout << tmp ;
		//auto rend = R.end(); (*R.end()).second.clear();
		for (auto r = R.begin(); r != R.end();r++)
		{
			if ((*r).second.size())
				cout << " " << (*r).first  << " " <<(*r).second.size();
			for (size_t i = 0; i < (*r).second.size(); i++)
				cout<< " "  << (*r).second[i].first << " "<< (*r).second[i].second ;
		}
		cout << endl;
	}
}*/
////////////////////////////////////////////////////////////////////////////////

int str_match(char * s,char * t){
	// time complexity O(n^2) 的字符串匹配算法，在s 中找t 第一次出现的位置
	// 匹配成功返回第一次出现的位置
	int slen = strlen(s),tlen=strlen(t);
	for (int i = 0,j,ii; i<slen; i++)
	{
		for (j = 0, ii = i; s[ii] == t[j] && t[j] != '\0'; ++ii, j++);
		if (j == tlen) return i;
	}
	return -1;
}
int main1(){
	cout << str_match("vgsgbdrtjgndtrkihn","n");
	return 0;
}
////////////////////////牛客网-华为 第10实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。  ////////////////////////////////
//  time complexity : O(n) space :O(n)
/*
int main(){
	string str;
	while (cin>>str)
	{ 
		map<char, int>  stat;
		int min=INT_MAX;
 		for (size_t i = 0; i < str.length(); i++)
		{
			if (stat.find(str[i]) != stat.end()){
				stat[str[i]] += 1;
			}else
			{
				stat[str[i]] = 1;
			}
		}
		for (auto s = stat.begin(); s != stat.end(); ++s){
			if ((*s).second<min) min = (*s).second;
		}
		for (auto s = stat.begin(); s != stat.end(); ++s){
			if ((*s).second > min){
				(*s).second = -1;
			}
		}
		string newStr;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (stat[str[i]] == -1) newStr.push_back(str[i]);

		}
		cout << newStr<<endl;

	}
}*/

////////////////////////牛客网-华为 第10字符串排序  ////////////////////////////////
/*
int exchange(int n){
	if (n == 1) return 0;
	if (n == 2) return 1;
	return n / 3 + exchange(n % 3 + n / 3);

}
int main(){
	int n,x,tmp;
	while (cin>>n)
	{   
	
		cout << exchange(n) << endl;

	}
 
}*/


////////////////////////牛客网-华为 第10字符串排序  ////////////////////////////////
/*
int main(){
	string str;
	string dict = "22233344455566677778889999";
	while (cin>>str)
	{   
		string pwd = str;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A'&& str[i] <= 'Z'){
				pwd[i] = (str[i] + 32 + 1);
				if (pwd[i]>'z') pwd[i] = 'a';

			}else if (str[i] >= 'a' && str[i] <= 'z')
			{
				pwd[i] = dict[str[i] - 'a'];
			}
			
		}
		cout << pwd;
	} 
}*/

int main_shopping_bill(){
	int v[61]; int p[61]; int q[61];
	int dp[61][3200] = { 0 };
	int N, m;
	cin >> N >> m;
	for (int i = 1; i <= m; i++){
		cin >> v[i] >> p[i] >> q[i];
	}
	
	for (int i = 1; i <= m; i++){  //m 件物品的约束条件
		for (int j = 1; j <= N; j++){
			if (q[i] == 0){//是主件
				if (v[i] <= j)// 买得起
					dp[i][j] = max(dp[i - 1][j - v[i]] + p[i] * v[i], dp[i - 1][j]);//买还是不买
			}
			else {//是附件  
				if (v[i] + v[q[i]]<j)//是否可以买 第i件物品的主件和附件
					dp[i][j] = max(dp[i - 1][j - v[i]] + p[i] * v[i], dp[i - 1][j]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[m][N];//重复的问题怎解决？多件物品有共同附件，只要一次购买主件，就后面就无需计算此主件
	return 0;
}

////////////////////////牛客网-华为 第10字符串排序  ////////////////////////////////
/*
int main(){//statistic the number of 1 int a integrater, usage of bit operator
	int n;
	while (cin >> n){
		int count = 0;
		for (; n != 0; (n & 1) == 1 ? count += 1 : count, n >>= 1);
		cout << count << endl;
	}
	return 0;
}*/

////////////////////////牛客网-华为 第10字符串排序  ////////////////////////////////
/*
int main(){
	int n;
	while (cin>>n)
	{
		vector<string> strs(n,"");
		for (size_t i = 0; i < n; i++)
			cin >> strs[i];
		
		sort(strs.begin(), strs.end(), [](const string&s1, const string &s2)
			->int{return s1 < s2; });
		for (size_t i = 0; i < strs.size(); i++)
		{
			cout << strs[i] << endl;
		}
	}
	return 0;
}*/
////////////////////////牛客网-华为 第4  ////////////////////////////////
/*
int main(){
	char ch[20];
	
	while (scanf("%s ",ch)!=EOF)
	{
		string tmp(ch);
		vector<string> strs = {tmp};
		while (scanf("%s ", ch) != EOF)
		{
			strs.push_back(string(ch));
		}
		std::reverse(strs.begin(),strs.end());
		int i;
		for ( i = 0; i <strs.size()-1 ; i++)
		{
			cout << strs[i] << " ";
		}
		cout << strs[i] << endl;
	}

}*/


////////////////////////牛客网-华为 第4  ////////////////////////////////
/*
int main(){
	int n;
	string tmp;
	while (cin>>n)
	{
		tmp = to_string(n);
		std::reverse(tmp.begin(),tmp.end());
		cout << tmp << endl;
	}
	return 0;
}*/

////////////////////////牛客网-华为 第4  ////////////////////////////////
/*
int main(){
	string str;
	while (cin>>str){
		map<char, int> hashtb;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (hashtb.find(str[i])==hashtb.end() )
			{
				hashtb[str[i]] = 1;
			}
		}
		cout << hashtb.size() << endl; 
	}
	return 0;
}*/

////////////////////////牛客网-华为 第4  ////////////////////////////////
/*
int main(){
	int n;
	string tmp,newNum;
	while (cin>>n)
	{
		vector<bool> status(10,false);
		tmp = to_string(n);
		for (size_t i = 0, N = tmp.length()-1; i <=N; i++)
		{
			if (!status[tmp[N-i]-'0'])
			{
				newNum.push_back(tmp[N - i]);
				status[tmp[N - i] - '0'] = true;
			}
		}
		cout << atoi(newNum.c_str()) << endl;
	}
	return 0;
}*/

////////////////////////牛客网-华为 第4  ////////////////////////////////
/*
int main(){
	int n, a, b;
	while (cin >> n){
		map<int, int> dict;
		for (int i = 0; i < n; ++i){
			cin >> a >> b;
			if (dict.find(a) != dict.end()){
				dict[a] += b;
			}
			else{
				dict[a] = b;
			}
		}
		for (auto d : dict){
			cout << d.first <<" "<< d.second<< endl;
		}
	}
	return 0;
}*/


////////////////////////牛客网-华为 第4  ////////////////////////////////
/*
template<typename _ToNum>
long k_num_to_10_num(int k, string num, int start, _ToNum ToNum){
	//把k进制数转换成十进制,ToNum为用户指定的把num 的一位转成十进制的数字的方法，用lambda表达式即可 
	long res=ToNum(num[start]);
	for (size_t i = start+1; i < num.length(); i++)
		res = res * k + ToNum(num[i]);
	return res;
}
int main(){
	string _0xNum;
	long _10_num;
	while (cin >> _0xNum)
	{
		_10_num = _0xNum[2] >= 'A' ? 10 + _0xNum[2] - 'A' : _0xNum[2] - '0';
		for (size_t i = 3; i < _0xNum.length(); i++)
		{  // 非常重要的进制转换公式，也可以递归
			_10_num = _10_num * 16 + (_0xNum[i] >= 'A' ? 10 + _0xNum[i] - 'A' : _0xNum[i] - '0');
		}

		//_10_num=k_num_to_10_num(16, _0xNum, 2, [](const char ch)->int{ return ch >= 'A' ?
		//	10+ch - 'A' : ch - '0'; });

		cout << _10_num << endl;

	}
	return 0;
}*/
////////////////////////牛客网-华为 第4  ////////////////////////////////
/*
vector<vector<int>> multi(vector<vector<int>> M1, const vector<vector<int>> &M2){
//M1*M2 结果放在M1中
vector<vector<int>> tmp(M1.size(), vector<int>(M1.size(), 0));
for (size_t i = 0; i < M1.size(); i++)
for (size_t j = 0; j < M1.size(); j++)
{
for (size_t k = 0; k < M1.size(); k++)
tmp[i][j] += (M1[i][k] * M2[k][j]);
}
return tmp;
}
int main(){
int _N, m, k;
while (cin >> _N)
{
for (size_t i = 0; i < _N; i++)
{
cin >> m >> k;
vector<vector<int>> M(m, vector<int>(m)), result,tmp;
for (size_t i = 0; i < m;result[i][i]=1, i++)
for (size_t j = 0; j < m; j++)
cin >> M[i][j];

tmp = M;
for (; k!=0; k>>=1)  //在O(log(n)) 复杂度完成矩阵n 次方
{
if ((k & 1) == 1){
result = multi(result,tmp);
}
tmp = multi(tmp, tmp);
}
for (size_t i = 0, j; i < m; i++){
for (j = 0; j < m - 1; j++)
cout << result[i][j] << " ";
cout << result[i][j] << endl;
}
}
}
}*/

////////////////////////牛客网-华为 第4  ////////////////////////////////
/*
int main(){
	string str,sub;
	while (cin>>str)
	{  
		for (size_t i = 0; i < str.length(); i++)
		{
			if (sub.length()==8)
			{
				cout << sub << endl;
				sub.clear();
			}
			sub.push_back(str[i]);
		}
		if (sub.length()>0){
			for (size_t i = sub.length(); i < 8; i++)
				sub.push_back('0');
			cout << sub << endl;
		}
		sub.clear();
	}
	return 0;
}*/

////////////////////////牛客网-华为 第3  ////////////////////////////////
/*
int main(){
	int n,tmp;
	while (cin>>n)
	{
		map<int, int> nums;
		for (size_t i = 0; i < n; i++)
		{
			cin >> tmp;
			if (nums.find(tmp) == nums.end()){
				nums[tmp] = 1;
			}
		}
		for (auto num:nums)
		{
			cout << num.first<<endl;
		}

	}


	return 0;
}*/

////////////////////////牛客网-华为 第2  ////////////////////////////////
/*
int main(){
	string str;
	char c;
	int count;
	while (cin>>str)
	{
		cin >> c;
		count = 0;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')) &&
				((str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z')))
			{
				if (abs(c - str[i]) % 32 == 0){
					count++;
				}
			}
			else if (c == str[i]) count++;
				
		}
		cout << count << endl;

	}
	return 0;
}*/

////////////////////////牛客网第43 字符串匹配 ////////////////////////////////
/*
int main(){
	int n;
	while (cin>>n)
	{
		for (size_t i = 1; i < n; i+10)
		{

		}

	}

	return 0;

}*/

////////////////////////牛客网第43 字符串匹配 ////////////////////////////////
/*
int main(){
	int n;
	string goal;
	while (cin>>n)
	{
		vector<string> str(n, "");
		for (size_t i = 0; i < n; i++)
		{
			cin >> str[i];
		}
		cin >> goal;
		regex pattern(goal, regex_constants::icase);
		for (size_t i = 0; i < n; i++)
		{
			std::match_results<std::string::const_iterator> result;
			bool valid = std::regex_match(str[i], result, pattern);
			//此处result参数可有可无，result是一个字符串数组，用来存储正则表达式里面括号的内容。
			if (valid && (result.size()>0))
			{
				for (int j = 0; j<result.size(); j++)
				{
					cout<<i+1<<" " << result[j] << endl;
				}
			}
		}
	}

	return 0;
}*/

////////////////////////牛客网第43 霍夫曼树 ////////////////////////////////
/*
void to_base_k_num(int x,int k,vector<int> &k_nums){
	if (x < k){
		k_nums.push_back(x);
		return;
	}
	k_nums.push_back(x%k);
	to_base_k_num(x / k, k, k_nums);	
}
int main(){
	int n,tmp;
	while (cin>>n){
		vector<int> base_k;
		for (size_t i = 0; i < n; i++)
		{
			cin >> tmp;
			to_base_k_num(tmp, 2, base_k);
			for (int i = base_k.size()-1; i > 0; i--)
			{
				cout << base_k[i];
			}
			cout << base_k[0] << endl;
			base_k.clear();
		}

	}
	return 0;
}*/

////////////////////////牛客网第43 霍夫曼树 ////////////////////////////////
/*
typedef struct HTNode {
	int w=0,p=-1,l=-1,r=-1,key=_MAX_INT_DIG;
	bool used = false;
	HTNode(int wi = 0, int pi = -1, int li = -1, int ri = -1, int keyi = _MAX_INT_DIG,bool u=false) :
		w(wi), p(pi), l(li), r(ri),key(keyi),used(u){}

} HTNode,*HuffmanTree;
int getMin(vector<HTNode> &Tree){
	int min = _MAX_INT_DIG, min_id = -1;
	for (size_t i = 0; i < Tree.size(); i++)
	{
		if (Tree[i].key <min  && !Tree[i].used)
		{
			min = Tree[i].key;  min_id = i;
		}	
	}
	if (min != _MAX_INT_DIG)Tree[min_id].used = true;
	return min_id;
}
int getSumWeight(vector<HTNode> &Tree,int id,int depth){
	if (id!=-1)
	{
		if (Tree[id].l == -1 && Tree[id].r == -1)//只有到达叶子节点才返回，豪夫曼树的特点就是每个节点的度要么是0，要么是2
		{
			Tree[id].w = depth;
			return Tree[id].key*depth;
		}
		return getSumWeight(Tree, Tree[id].l, depth + 1)+
			   getSumWeight(Tree, Tree[id].r, depth + 1);
	}else return 0;
}
int main(){
    int _N,tmp,min_1,min_2;
	while (cin>>_N)
	{
		vector<HTNode> Tree(2*_N-1);
		for (size_t i = 0; i < _N; i++)
			cin >> Tree[i].key;
		for (size_t i = 0; i <_N-1; i++)
		{
			min_1 = getMin(Tree);
			min_2 = getMin(Tree);
			Tree[_N + i].l = min_1; Tree[_N + i].r = min_2;
			Tree[_N + i].key = Tree[min_1].key + Tree[min_2].key;
			
			Tree[min_1].p = _N + i; Tree[min_2].p = _N + i;
		}
		 
		cout << getSumWeight(Tree, 2 * _N - 2, 0) << endl;
	}
	return 0;
}*/
////////////////////////牛客网第42奇偶校验 ////////////////////////////////
/*
int main(){
	int N, tmp;
	while (cin>>N)
	{
		map<int, vector<int>> nums;
		nums[0] = {}; nums[1] = {};
		for (size_t i = 0; i < N; i++)
		{
			cin >> tmp;
			nums[tmp % 2].push_back(tmp);
		}
		if (nums[0].size()>nums[1].size()) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}*/

////////////////////////牛客网第27 第k小数////////////////////////////////
/* 充分利用map 从小到大的遍历顺序及Hash消除重复的功能
int main(){
	int N,tmp,k;
	while (cin>>N)
	{
		map<int, int>  nums;
		for (size_t i = 0; i < N; i++)
		{
			cin >> tmp;
			if (nums.find(tmp) != nums.end())
				nums[tmp] += 1;
			else  nums[tmp] = 0;	
		}
		int k;
		cin >> k;
		for (auto n:nums)
		  if (k-- == 1){ cout << n.first<<endl; break; }
	}
	return  0;
}*/


////////////////////////牛客网第27 矩阵乘法////////////////////////////////
/*
void multi(vector<vector<int>> &M1, const vector<vector<int>> &M2){
	//M1*M2 结果放在M1中
	vector<vector<int>> tmp(M1.size(),vector<int>(M1.size(),0));
	for (size_t i = 0; i < M1.size(); i++)
		for (size_t j = 0; j < M1.size(); j++)
		{  
			for (size_t k = 0; k < M1.size(); k++)
			{
				tmp[i][j] +=( M1[i][k] * M2[k][j]);
			}
		}
		M1 = tmp;
}
int main(){
	int _N,m,k;
	while (cin>>_N)
	{
		for (size_t i = 0; i < _N; i++)
		{
			cin >> m >> k;
			vector<vector<int>> M(m,vector<int>(m)),result;
			for (size_t i = 0; i < m; i++)
			for (size_t j = 0; j < m; j++)
				cin >> M[i][j];
			result = M;
			for (int u = 1; u < k;++u)
			{
				multi(result, M);
			}
			for (size_t i = 0, j; i < m; i++){
				for (j = 0; j < m - 1; j++)
					cout << result[i][j] << " ";
				cout << result[i][j] << endl;
			}
		}
	}
}*/



////////////////////////牛客网第27 打牌////////////////////////////////
void operate_1_2(vector<vector<int>> &M,int x, int y){
	//1 2 表示：90度，顺时针，翻转4个数  
	for (int i = x-1; i < x; i++)
	for (int j = y-1; j < y; j++)
		swap(M[i][j],M[x][j]);

}
void operate_1_3(vector<vector<int>> &M, int x, int y){
	// 1 3 表示：90度，顺时针，翻转9个数  
}
void operate_2_2(vector<vector<int>> &M, int x, int y){
	//2 2 表示：90度，逆时针，翻转4个数  

}
void operate_2_3(vector<vector<int>> &M, int x, int y){
	//2 3 表示：90度，逆时针，翻转9个数
}
int main2(){
#define N 5
	vector<vector<int>> M(N,vector<int>(N));
	int p, q, x, y;
	vector<vector< void(*)(vector<vector<int>> &M, int x, int y) >>  operate_p_q(3,
		vector< void(*)(vector<vector<int>> &M, int x, int y) >(4, nullptr));
	operate_p_q[1][2] = operate_1_2;
	operate_p_q[1][3] = operate_1_3;
	operate_p_q[2][2] = operate_2_2;
	operate_p_q[2][3] = operate_2_3;

	while (cin >> M[0][1] >> M[0][2] >> M[0][3]>>M[0][4])
	{
		for (size_t i = 1; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> M[i][j];
			}
		}
		cin >> p >> q >> x >> y;
		if (operate_p_q[p][q]) operate_p_q[p][q](M, x, y);
		
		for (size_t i = 0,j; i < N; i++){
			for ( j = 0; j < N-1; j++)
				cout<< M[i][j]<<" ";
			cout << M[i][j] << endl;
		}
	}
	return 0;
}


////////////////////////牛客网第27 打牌////////////////////////////////
/*int main(){
	string a, b;
	while (cin>>a)
	{
		cin >> b;
	}

	return 0;
}*/

////////////////////////牛客网第27 复数////////////////////////////////
/*  考二叉树的公式
// 1 深度为d的完全二叉树有 2^d-1个节点，完全二叉树用数组存储即可
// 输出第i层的节点，可先计算出i-1层节点数目，得出第i层开始的下标。
int main(){
	int n,d;
	while (cin>>n)
	{
		vector<int> tree(n, 0);
		for (size_t i = 0; i < n; i++)
		{
			cin >> tree[i];
		}
		cin >> d;
		int i;
		if (pow(2, d - 1) - 1<n)
		{
            for ( i = pow(2,d-1)-1; i < pow(2,d)-2 &&i<n; i++)
	     	{
			    cout << tree[i] << " ";
	    	}
		    cout << tree[i] << endl;
		}
		else  cout << "EMPTY" << endl;
	}
	return  0;

}*/

////////////////////////牛客网第27 复数////////////////////////////////
/*
int main(){
	int N,a,b;
	string C;
	

	while (cin>>N)
	{
		map<pair<int, int>, float> set;
		for (size_t i = 0; i < N; i++)
		{
			cin >> C;
			if (C=="Pop")
			{
				if (set.size()){
					auto max = set.begin();
					for (auto i = set.begin(); i !=set.end(); i++)
					{
						if ((*i).second>(*max).second){ max = i; }
					}
					cout << (*max).first.first << "+i" << (*max).first.second<<endl;
			     	set.erase(max);   
			    	cout << "SIZE = " << set.size() << endl;
				}
				else
				{
					cout << "empty" << endl;
				}
			}else
			{
				scanf("%d+i%d", &a, &b);
				pair<int, int> tmp(a,b);
				set[tmp] = sqrt(a*a + b*b);
				cout << "SIZE = " << set.size() << endl;
			}
		}
	}
	return 0;
}*/

////////////////////////牛客网第27 找数////////////////////////////////
/*
int main(){
	int N;
	while (cin>>N)
	{
		vector<pair<int, int>> nums(N,pair<int,int>(0,0) );
		for (size_t i = 0; i < N; i++)
		{
			cin >> nums[i].first >> nums[i].second;
		}
		sort(nums.begin(), nums.end(), [](const pair<int, int> &p1, const pair<int, int> &p2)->int{
			if (p1.first != p2.first) { return p1.first < p2.first; }
			else return p1.second < p2.second;
		});
		cout << nums[0].first << " " << nums[0].second << endl;

	}

	return  0;
}*/

////////////////////////牛客网第27 找数////////////////////////////////
/*
int main(){
	int m, n,key;
	while (cin>>n)
	{
		map<int, int> dict;
		for (size_t i = 0; i < n; i++)
		{
			cin >> key;
			dict[key] = 1;
		}
		cin >> m;
		for (size_t i = 0; i < m; i++)
		{
			cin >> key;
			if (dict.find(key) != dict.end()) cout << "YES\n";
			else cout << "NO\n";
		}

	}
	return  0;

}*/



////////////////////////牛客网第28 矩阵调整////////////////////////////////
/*
int main(){
	//==============================time complexity O(n^2)
	int N,max_id;
	while (cin>>N)
	{
		vector<vector<int>> M(N,vector<int>(N,0));
		vector<int> Index(N);
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> M[i][j];
			}
		}
		for (size_t i = 0; i < N; Index[i] = i, i++);
		//////////////////////关键代码/////////////////////////////
		for (size_t j= 0; j < N; j++)
		{
			max_id = j;
			for (size_t i = j; i < N; i++)
			{
				if (M[Index[i]][j]>M[Index[max_id]][j])
				{
					max_id = i;
				}
			}
			swap(Index[j], Index[max_id]);
		}
		/////////////////////////////////////////////////////////
		
		for (size_t i = 0,j; i < N; i++)
		{
			for ( j = 0; j < N-1; j++)
			{
				cout << M[Index[i]][j] << " ";
			}
			cout << M[Index[i]][j] << endl;
		}
	}
	return 0;
}
*/

////////////////////////牛客网第27 合并串////////////////////////////////
/*
int main(){
	string s1, s2, a, b, result = "";
	int i, j;

	while (cin >> s1){

		cin >> s2;
		for (i = 0, j = s2.length() - 1; i < s1.length() || j>-1; i++, j--)
		{
			if (i < s1.length()) result.push_back(s1[i]);
			if (j>-1) result.push_back(s2[j]);

		}
		cout << result << endl;
	    result = "";
	}

	return 0;

}*/



////////////////////////牛客网第26 多项式加法////////////////////////////////
/*
int main(){
	int m,n;
	int a, b;
	while (scanf("%d", &m) != EOF&&m> 0){
		map<int, int> poly1,poly2,result;
		for (size_t i = 0; i < m; i++)
		{
			cin >> a >> b;
			poly1[b] = a;
		}
		scanf("%d", &n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> a >> b;
			poly2[b] = a;
			if (poly1.find(b) != poly1.end()){
				result[b] = poly1[b] + poly2[b];
                poly1[b] = 0;
			}else{
				result[b] = a;
			}  
			  ///将系数置0
		}
		for (auto p:poly1)
		{
			if (p.second != 0){
				result[p.first] = p.second;
			}
		}
		vector<pair<int, int>> out;
		for (auto res:result)
		{
			out.push_back(pair<int, int>(res.second, res.first));
		}
	
		for (auto i = out.end()-1; i>out.begin(); --i)
		{
			if ((*i).first!=0)  cout << (*i).first << " " << (*i).second << " ";
		}
		if ((*out.begin()).first != 0) cout << (*out.begin()).first << " " << (*out.begin()).second;
		 cout << endl;
	}

}*/


////////////////////////牛客网第25 yang hui san jiao   ////////////////////////////////
/*
int yanghui(int i,int j,vector<vector<int>> &M){

}

int main(){
	int N;
	while (cin>>N)
	{
         
	}

	return 0;
}*/

////////////////////////牛客网第24 statistic  ////////////////////////////////
/*
int main(){
	int N;
	while (cin>>N)
	{  //////////输入时直接放在转置的位置即可 
		vector<vector<int>> M(N,vector<int>(N));
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> M[j][i];
			}
		}
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cout << M[i][j]<<" ";
			}
			cout << endl;
		}
	}
}*/

////////////////////////牛客网第23 statistic  ////////////////////////////////
/*
int main(){
	char words[10001];
	while (scanf("%s", words) != EOF)
	{//该代码利用了scanf函数在输入字符串时，不能输入空格的性质
		int len = strlen(words);
		if (words[len - 1] == '.'){
			cout << len - 1 << endl;;
		}else
		{
			cout << len << " ";
		}
	}	
	return 0;
}*/

////////////////////////牛客网第23 checking ip  ////////////////////////////////
/*
int main(){
	string IP;
	string num;
	int prior;
	bool flag = false;
	int N;
	while (cin>>N)
	{ 
		for (int k = 0; k < N; k++)
		{
			IP += '.';
			for (int i = 0, prior = 0; i < IP.length(); i++)
			{
				if (IP[i] == '.')
				{
					num = IP.substr(prior, i);
					int a = atoi(num.c_str());
					if (!(a >= 0 && a <= 255)){
						flag = true;
						break;
					}
					prior = i + 1;
				}
			}
			if (!flag)
				cout << "Yes!\n";
			else  cout << "No!\n";
			flag = false;
		}
	}
	return 0;
}
int main()
{
	int n, a, b, c, d;
	scanf("%d", &n);
	while (n--){
		scanf("%d.%d.%d.%d", &a, &b, &c, &d);
		if (a < 0 || b < 0 || c < 0 || d < 0 || a > 255 || b > 255 || c > 255 || d > 255)
			printf("No!\n");
		else
			printf("Yes!\n");
	}
	return 0;
}
*/

////////////////////////牛客网第22 sorting of binary tree  ////////////////////////////////
/*
typedef struct BTNode{
	long key=0;
	BTNode * left=nullptr, *right=nullptr;
	BTNode(int v, BTNode * l=nullptr, BTNode *r=nullptr) :key(v), left(l), right(r){}
};
class Tree
{
public:
	BTNode * root;
	Tree(){ root = nullptr; };
	~Tree(){
		destory_tree(this->root);
	};
	int Insert(BTNode * &root, long num){
		if (root)
		{
			if (num<root->key)
			{
				if (!root->left) { root->left = new BTNode(num); return root->key; }
				else  return Insert(root->left, num);
			}else
			{
				if (!root->right) { root->right = new BTNode(num); return root->key; }
				else  return Insert(root->right, num);
			}
		}
		else
		{
			root = new BTNode(num);
			return -1;
		}
	
	}
	void destory_tree(BTNode *root){
		if (root){
			destory_tree(root->left);
			destory_tree(root->right);
			delete root;
		}
	}
};
int main(){

	int N,tmp,rn;
	while (cin>>N)
	{
		Tree *tree= new Tree();
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			rn=tree->Insert(tree->root,tmp);
			cout << rn << endl;
		}
		int a = 0;
		delete tree;
	}
	return 0;
}*/
////////////////////////牛客网第22   ////////////////////////////////
/*
int main(){
	string s1, s2;
	while (cin>>s1>>s2)
	{
		cout << s1 + s2<<endl;
	}
}
*/
////////////////////////牛客网第22 a+b ////////////////////////////////
/*
int main(){
	string a, b,result="";
	int ai, bi;
	while (cin>>a>>b)
	{    
		int carry = 0;
		for (int i = a.length()-1,j=b.length()-1;i>=0||j>=0;--i,--j)
		{
			ai = i>=0 ? a[i]-'0':0;
			bi = j>=0 ? b[j]-'0':0;
			result += to_string( (ai+bi+carry)%10 );
			carry = (ai + bi + carry) / 10;

		}
		if (carry)  result += to_string(carry);
		for (auto i = result.end()-1; i >=result.begin(); --i)
		{
			cout << *i ;
		}
		cout << endl;
		result.clear();
	}
	return 0;
}*/

////////////////////////牛客网第21 ////////////////////////////////
/*
int  main(){
	int N;
	while (cin >> N){
		vector<int> nums(N);
		for (int i = 0; i < N; i++)
		{
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end(), [](const int a, const int b)->int { return a < b; });
		for (int i = 0; i < N; i++)
		{
			cout<< nums[i]<<" ";
		}
		cout << endl;
	}
}*/
////////////////////////牛客网第19题 //////////////////////////////////
/*
int main(){
	int N;
	while (cin>>N)
	{
		vector<int> Nums(N, -65535);
		int max_id = 0,tmp;
		for (int i = 0; i < N; i++)
		{
			cin >> Nums[i];
		}
		sort(Nums.begin(), Nums.end(), [](const int a, const int b)->int{return a<b; });
		cout << Nums[N-1] << endl;
		for (int i = 0; i<N-1; ++i)
		{
			cout << Nums[i] << " ";
		}
		if (N == 1) cout << -1 << " ";
		cout << endl;

	}

}
*/

////////////////////////牛客网第18题阶乘///////////////////////////////
/*
void K(int x, int k, vector<int> &res)
{
	if (x<k){
		res.push_back(x%k);
		return;
	}
	res.push_back(x%k);
	K(x / k, k, res);
}
int main(){
	string str;
	while (cin >> str){
		
		for (int i = 0; i < str.length(); i++){
			string result;
			vector<int> bin;
			K((int)str[i], 2, bin);
			for (size_t j = bin.size(); j <= 7; bin.push_back(0), j++);
			int count = 0;
			for (size_t j = 0; j < bin.size(); j++)
			{
				if (bin[j] == 1) count++;
			}
			bin[bin.size() - 1] = !(count % 2);
			string tmp;
			for (int j = bin.size()-1; j >= 0; j--)
			{  
				tmp += to_string(bin[j]);
			}
			result += tmp;
			cout << result << endl;
		}
		
	 
	
	}

}*/


////////////////////////牛客网第17 题阶乘///////////////////////////////
/*线下通过，线上不过
int main(){
	int n;
	while (cin>>n)
	{
		vector<vector<int>> M(4, vector<int>(5,0));
		vector<vector<int>> result(2, vector<int>(5, 0));
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				cin >> M[i][j];

			}
		}
		////////////////////////find////////////////////////////
	   for (size_t j = 0; j < 5; j++)
			{
				int max0_id = 0,max1_id=0;
				for (size_t i = 0; i < 4; i++){
					if (M[i][j]>M[max0_id][j]){//如果比当前最大数大，则当前最大数变成次大数
						max1_id = max0_id;
						max0_id = i;
					}else //如果比当前最大数小，最大数不动，次大数可能需要更新
					{
						if ( M[i][j]>M[max1_id][j]){
							max1_id = i;
						}else{
							if (max0_id == max1_id){
								max1_id = i;
							}
						}

					}//if
				}
				if (max0_id > max1_id){
					result[0][j] = M[max1_id][j];result[1][j] = M[max0_id][j];
				}else{
					result[0][j] = M[max0_id][j]; result[1][j] = M[max1_id][j];
				}	              
			}
		///////////////////////////output////////////////////////////////////
	   for (size_t i = 0; i < 2; i++)
	   {
		   for (size_t j = 0; j < 5; j++)
		   {
			   cout<<result[i][j]<<" ";
		   }
		   cout << endl;
	   }

	}
}
*/

////////////////////////牛客网第二题阶乘///////////////////////////////
/*
int main(){
	typedef struct Stu{
		string name="";
		int age = 0; int score = 0;
	};
	int N;
	while (cin>>N){
		vector<Stu> Info(N);
		for (size_t i = 0; i < N; i++)
		{
			cin >> Info[i].name >> Info[i].age >> Info[i].score;
		}
		sort(Info.begin(), Info.end(), [](const Stu&s1,const Stu &s2)->int{
			if (s1.score != s2.score) return s1.score < s2.score;
			else
			{
				if (s1.name != s2.name) return s1.name < s2.name;
				else{return s1.age < s2.age;}
			}
		});
		for (size_t i = 0; i < N; i++)
		{
			cout << Info[i].name<<" "<< Info[i].age <<" "<< Info[i].score<<endl;
		}
	}
}*/
////////////////////////牛客网第15题 ///////////////////////////////
/*  逻辑一定要严谨，尤其是指针的操作，注意对象的生命周期
int main(){
	typedef struct Link_Node{
		int val;
		Link_Node * next = nullptr;
		Link_Node(){}
		Link_Node(int v, Link_Node *nxt) :val(v), next(nxt){}
	};
	int N;
	Link_Node Head(-1, nullptr);
	Link_Node *head = &Head, *p = head, *q = head;
	while (cin >> N){
		///////////////////////////create link///////////////////////
		for (size_t i = 0; i < N; i++)
		{
			Link_Node *node=new Link_Node;
			p = head->next;q=head;
			cin >> node->val;
			while (p && node->val>p->val)
			{
				q = p;
				p = p->next;
			}
			q->next = node;
			node->next = p;
		}
		///////////////////////output result//////////////////////////
		p = head->next;
		while (p->next)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << p->val << endl;
		////////////////////free link/////////////////////////////
		p = head->next;
		q = p;
		while (p)
		{
			q = p;
			p = p->next;
			delete q;
		}
		head->next = nullptr;

	}
}*/

////////////////////////牛客网第14题shou xin gshu  ///////////////////////////////
/*
int main(){
	int A;
	long A2;
	string strA,strA2;
	while (cin>>A)
	{
		A2 = A*A;
		strA = to_string(A);
		strA2 = to_string(A2);
		if (strA2.substr(strA2.length() - strA.length(), strA2.length())==strA ){
			cout << "Yes!\n";
		}
		else{
			cout << "No!\n";
		}
	}
}
*/
////////////////////////牛客网第13题 矩阵最大值///////////////////////////////
/*
int main(){
#define _INF -65535
	int m, n,max,max_id,sum;
	while (cin>>m>>n)
	{
		vector<vector<int>> M(m, vector<int>(n, 0));
		for (size_t i = 0; i < m; i++)
		{   
			sum = 0;
			max = _INF;
			max_id = 0;
			for (int j = 0; j < n; ++j){
				cin >> M[i][j];
				if (M[i][j]>max){
					max = M[i][j];
					max_id = j;
				}
				sum += M[i][j];
			}
			M[i][max_id] = sum;
		}

		for (int i = 0,j; i < m; ++i){
			for (int j = 0; j < n-1; ++j){
				cout << M[i][j] << " ";
			}
			cout << M[i][j] << endl;
		}
			
	}
}*/

////////////////////////牛客网第12题  ///////////////////////////////
/*
int main(){
#define topk 3
	typedef struct empolyee{
		int ID = 0;
		string name;
		int age = 0;
		empolyee(){}
		empolyee(int id, string na, int age) :ID(id), name(na), age(age){}
	};
	int N;
	while (cin >> N){
		vector<empolyee> E_topk(N, empolyee(0, "", 101));
		for (size_t i = 0; i < N; i++)
		{
			cin >> E_topk[i].ID >> E_topk[i].name >> E_topk[i].age;
		}
		sort(E_topk.begin(), E_topk.end(), [](const empolyee &e1,const empolyee &e2)->int{
			if (e1.age != e2.age) return e1.age<e2.age;
			else {
				if (e1.ID != e2.ID) return e1.ID < e2.ID;
				else  return e1.name < e2.name;	
			}	
		});
		for (size_t i = 0; i < topk; i++)
		{
			if (E_topk[i].age <= 100){
				cout << E_topk[i].ID << " " << E_topk[i].name << " " << E_topk[i].age << endl;
			}
		}
	}
}
*/
/*
int main(){
    #define topk 3
	typedef struct empolyee{
		int ID = 0;
		string name;
		int age = 0;
		empolyee(){}
		empolyee(int id, string na, int age) :ID(id), name(na), age(age){}

	};
	int N;
	vector<empolyee> E_topk(topk, empolyee(0, "", 101));////维护年龄从小到大的顺序
	empolyee tmp;
	while (cin >> N){
		for (size_t i = 0; i < N; i++)
		{
			cin >> tmp.ID >> tmp.name >> tmp.age;
			cin.clear();
			for (size_t j = 0; j < topk; j++)
			{
				if (tmp.age < E_topk[j].age){
					for (size_t k = E_topk.size() - 1; k>j; k--)
					{
						E_topk[k] = E_topk[k - 1];
					}
					E_topk[j] = tmp;
					break;
				}
			}
		}
		for (size_t i = 0; i < topk; i++)
		{
			if (E_topk[i].age <= 100){
				cout << E_topk[i].ID << " " << E_topk[i].name << " " << E_topk[i].age<<endl;
			}
		}

	
	}


}
*/

////////////////////////牛客网第11题 矩阵对称///////////////////////////////
/////////本地调试通过，线上不过
/*
int main(){
	int N;
	while (cin>>N)
	{
		bool flag = false;
		vector<vector<int>> Matrix(N, vector<int>(N, 0));
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> Matrix[i][j];
				if (i>j)
				{
					if (abs(Matrix[i][j] - Matrix[j][i])>1e-5){
						cout << "No!\n";
						flag = true;
						break;
					}
				}
			}
		}
		if (!flag) cout << "Yes!\n";

	}
	return 0;
}*/
////////////////////////牛客网第10题A+B///////////////////////////////
/*
int main(){
	string sA, sB;
	int i,u;
	while (cin>>sA>>sB)
	{ 
		for ( i = 0, u = 0; i < sA.length();++i)
		{
			if (sA[i] != ','){
				sA[u++] = sA[i];
			}
		}
		sA[u] = '\0';
		for (i = 0, u = 0; i<sB.length(); ++i)
		{
			if (sB[i] != ',') sB[u++] = sB[i];
		}
		sB[u] = '\0';
		cout << atoi(sA.c_str()) + atoi(sB.c_str()) << endl;
	}

	return 0;
}
*/

////////////////////////牛客网第 9 题打印日期///////////////////////////////
/*
int main(){
	int year, x;
	int month, day;
	vector<int> tb = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
	while (cin >> year >> x){
		if ((abs(year % 4) < 1e-5 && year % 100 != 0) || year % 400 == 0){
			tb[2] = 29;
		}
		int sum = 0,i;
		for (i = 1; i <=12 ; i++)
		{
			if (sum + tb[i]>x){
				month = i;
				day =x-sum;
				break;
			}else if (sum + tb[i]<x)
			{
				sum += tb[i];
			}else
			{
				month = i;
				break;
			}
		}
		string ft_m = month < 10 ? "0" + to_string(month) : to_string(month);
		string ft_d = day < 10 ? "0" + to_string(day) : to_string(day);
		cout << year << "-" << ft_m << "-" << ft_d << endl;
		tb[2] = 28;

	}
	return 0;
}
*/
////////////////////////牛客网第8题二叉树排序///////////////////////////////
/*
//////注意对象的生命周期 

typedef struct Node{
	int val = 0;
	Node *left = nullptr, *right = nullptr;
	Node(int x) :val(x){}
}Node;
class tree{
public:
	Node * root=nullptr;
	void insert(Node * root, int num){
		if (root){
			if (num<root->val)
			{
				if (!root->left){
					root->left = new Node(num);
					return;
				}
				insert(root->left, num);
			}
			else if (num>root->val)
			{
				if (!root->right){
					root->right = new Node(num);
					return;
				}
				insert(root->right, num);
			}
			else  /// if there exist this number in the tree,then discharge it
			{
				return;
			}
		}else
		{
			this->root = new Node(num);
		}
	}
	void free_tree(Node *root){
		if (root)
		{
			free_tree(root->left);
			free_tree(root->right);
			delete root;
		}
	}
	void pre(Node * root){
		if (root){
			cout << root->val << " ";
			pre(root->left);
			pre(root->right);
		}
	}
	void InOrder(Node* root){
		if (root){
			InOrder(root->left);
			cout << root->val << " ";
			InOrder(root->right);
		}
	}
	void post(Node *root){
		if (root){
			post(root->left);
			post(root->right);
			cout << root->val << " ";
		}
	}

};
int main(){
	int N;
	while (cin>>N)
	{
		int Num;
		tree mytree;
		for (int i = 0; i < N; ++i){
			cin >> Num;
			mytree.insert(mytree.root,Num);
		}
		mytree.pre(mytree.root); cout << endl;
		mytree.InOrder(mytree.root); cout << endl;
		mytree.post(mytree.root); cout << endl;
		mytree.free_tree(mytree.root);

	}
	return 0;
}
*/
////////////////////////牛客网第7题sorting of big integraters ///////////////////////////////
/*
int main(){
	int N = 0;

	while (cin >> N){
		vector<string> Nums(N, string());
		for (int i = 0; i < N; ++i){
			cin >> Nums[i];
		}
		sort(Nums.begin(), Nums.end(), [](const  string &s1, const string &s2)->int{
			if (s1.length() != s2.length()){
				return s1.length() < s2.length();
			}
			return s1 < s2; });
			for (size_t i = 0; i < N; i++)
			{
				cout << Nums[i] << endl;
			}
	}
		return 0;
}*/
////////////////////////牛客网第6题 爬楼梯///////////////////////////////
/*
int main(){
	int a;
	while (cin>>a){
		int pre = 0, cur = 1, tmp;
		for (int i = 1; i <= a; ++i){
			tmp = cur;
			cur += pre;
			pre = tmp;
		}
		cout << cur << endl;
	}
	return 0;
}
*/
int f(int n){
	if (n <= 1){
		return 1;
	}
	return f(n - 1) + f(n - 2);
}

////////////////////////牛客网第5题a+b///////////////////////////////
/*
int main(){
	int a,b;
	while (cin>>a>>b){
		cout << a + b << endl;
	}
}
*/

////////////////////////牛客网第四题 回文///////////////////////////////
/*
int main(){ 
	char str[1000];

	while (scanf("%s",str)!=EOF){

		bool failed = false;
		for (int i = 0,j=strlen(str)-1; i<j; ++i,--j)
		{
			if (str[i] != str[j]){
				failed = true;
				break;
			}
		}
		if (!failed){
			printf("Yes!\n");
		}
		else{
			printf("No!\n");
		}
	}
	return  0;
}

*/
////////////////////////牛客网第三题找位置///////////////////////////////
/*
int main(){
	char ch[100];
	map<char, vector<int>> cache;
	///abcaaAB12ab12
	while (scanf("%s",ch)!=EOF)
	{
		cache.clear();
		string str(ch);
		for (size_t i = 0; i < str.length(); i++)
		{
			cache[str[i]].push_back(i);
		}
		for (int s = 0; s<str.length();++s){
			auto ca = cache[str[s]];
			if (ca.size()>1  )
			{
				int p;
				for ( p = 0; p < ca.size()-1;++p)
				{
					printf("%c:%d,", str[s],ca[p]);
				}
				printf("%c:%d\n", str[s], ca[p]);
				cache[str[s]].clear(); 
			}
		}
	}
	return 0;
}
*/

////////////////////////牛客网第二题阶乘///////////////////////////////

////////////////////////牛客网第二题阶乘///////////////////////////////
/*
int f(int n,int &sum1,int &sum2){
	if (n == 0 || n == 1){
		sum1 += 1;
		return 1;
	}
	int x = n*f(n - 1,sum1,sum2);
	if (n % 2){
		sum1 += x;
	}else{
		sum2 += x;
	}
	return x;
}
int main(){
	int a,sum1,sum2;
	while (scanf("%d", &a) != EOF){
		sum1 = 0; sum2 = 0;
		f(a, sum1, sum2);
		printf("%d %d\n", sum1 ,sum2);
	}
}*/
/////////////////////////牛客网第一题8进制///////////////////////////////////////
/*
void K(int x, int k, vector<int> &res)
{
	if (x<k){
		res.push_back(x%k);
		return;
	}
	res.push_back(x%k);
	K(x / k, k, res);
}
int main(int argc, char**argv)
{
	int a;
	vector<int> res;
	while (scanf("%d", &a) != EOF){
		res.clear();
		K(a, 8, res);
		for (int i = res.size()-1; i >= 0; i--){
			printf("%d",res[i]);
		}
		printf("\n");
	}
}*/
///////////////////////////////////////////////////////
/*typedef char DataType;
int find(string str, vector<string> strVec);

int _tmain(int argc, _TCHAR* argv[])
{   
	vector<string> strVec;
	vector<string> desVec;
	char temp[11] = "   ";
	int i, len;

	for ( i = 0; strlen(temp)!=0;i++){
		gets_s(temp);
		if (strlen(temp) == 0) break;
           strVec.push_back(temp);
	}
	*temp = 'd';
	for ( i = 0; strlen(temp)!=0; i++){
		gets_s(temp);
		if (strlen(temp) == 0) break;
		desVec.push_back(temp);
	}
	int *counter = new int[i];
	for (int j = 0; j < i; j++){
		counter[j] = find(desVec[j], strVec);
		cout << counter[j] << endl;
	}
	
	return 0;
}
int find(string str, vector<string> strVec){
	int c = 0;
	for (int i = 0; i < strVec.size(); i++){
		if (str==strVec[i].substr(0,str.length()) ){
			c++;
		}	
	}
	return c;
}*/