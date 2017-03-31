// NewKe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DynamicProgramming.h"

#include<regex>

#include<iostream>
#include<vector>
#include<string>
//#include<algorithm>
#include<map>
#include<math.h>
using namespace std;
////////////////////////牛客网-华为 第10字符串排序  ////////////////////////////////
int main(){
	DynamicProgramming DP;
	DP.run();
    

}
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
int main1(){
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