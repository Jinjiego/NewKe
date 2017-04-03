#pragma once
#include "stdafx.h"
#include <algorithm>
class DynamicProgramming
{
public:
	DynamicProgramming(){};
	int MinPathSum(vector<vector<int>> &A);


	void run();
	~DynamicProgramming(){};
};
/*
动态 1
矩阵最短路径和
*/

int DynamicProgramming::MinPathSum(vector<vector<int>> &A){
	int m = A.size();
	if (!m) return 0;
	int n = A[0].size();
	vector<vector<int>> dp = A;
	for (size_t i = 1; i < m; dp[i][0] += dp[i - 1][0], i++);
	for (size_t j = 1; j < n; dp[0][j] += dp[0][j - 1], j++);
	
	for (size_t i = 1; i < m; i++)
	 for (size_t j = 1; j < n; j++)
		dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + dp[i][j];
	return dp[m - 1][n - 1];
}
/*
动态 2
  换钱最少的货币数目
  每张面值的钱可以使用任意次
*/
int MinCoins(vector<int> & arr,int aim){
	int m = arr.size();
	vector<vector<int>> dp(m,vector<int> (aim+1,INT_MAX));
	//=============初始化第一列与第一行===============
	for (size_t j = 0; j <= aim; j+=arr[0]){//只有面值为arr[0]的钱币
		 dp[0][j] = j / arr[0];
	}
	for (size_t i = 0; i < m;dp[i][0]=INT_MAX,i++);
	//================================================
	for (size_t i = 1; i < m; i++)
		for (size_t j = 1; j <= aim; j++)
		{
			dp[i][j] = dp[i - 1][j];//当前面值的钱币一张都不使用
			//===========处理每张面值可以选多次的关键==================
			for (size_t k = 1; k < j/arr[i]; k++)//穷举使用当前面值钱币k次的情况
			{
				if (dp[i][j]>dp[i - 1][j - arr[i] * k] + k && dp[i - 1][j - arr[i] * k] !=INT_MAX){
					dp[i][j] = dp[i - 1][j - arr[i] * k] + k;
				}
			}
			//==========================================================

		}
		return dp[m - 1][aim] != INT_MAX ? dp[m - 1][aim]: -1;
}
int MinCoinsOnce(vector<int> &arr,int aim){
	int m = arr.size();
	int n = aim + 1;
	vector<vector<int>> opt(m, vector<int>(n,INT_MAX));

	for (size_t i = 0; i < m; opt[i][0]=0,i++);//面值为0时
	opt[0][arr[0]] = 1;

	for (size_t i = 1; i < m; i++)
	  for (size_t j = 1; j < n; j++)
	  {
		  if (  j>=arr[i] && opt[i-1][j- arr[i]]!=INT_MAX )
			  // 条件 opt[i-1][j- arr[i]]!=INT_MAX 是必须的，如果当Item=1->i-1 
			  // 容量为j-arr[i] 时opt  无解的话，j opt[i - 1][j - arr[i]] + 1 会溢出，
			  // 变成无穷小，导致错误的解
		    
		    opt[i][j] = min(opt[i - 1][j], opt[i - 1][j - arr[i]] + 1);  // 每个面值只能用一次，不选或选
		    //潜在的bug 此处会溢出
		  else opt[i][j] = opt[i - 1][j];
	   } 
	  return opt[m - 1][n - 1] != INT_MAX ? opt[m - 1][n - 1] : -1;
}

//////////////////////最少出队人数 ////////////////////////
/*
动态 3
两遍动态规划,第一次从前往后，结果为opt_1
第二次从后往前，结果为opt_2,
 opt 为一维，opt[j]表示当前仅有item[1:j]时的最长递增序列
 则opt_1[i],opt_2[i] 分别表示从0:i的最长递增序列、从n-1:i的最长递增序列，
 opt_1[i]+opt_2[i] 则表示 选第i 个位置为最大值时队列的最多人数，找
 opt_1[i]+opt_2[i] 的最大值，即找到了队列最多人数，也就得到了最少
 出队人数
*/

void chorus(){
	int n;
	while (cin >> n)
	{
		vector<int> stus(n);
		vector<int> opt_1(n, 1);
		vector<int> opt_2(n, 1);
		for (int i = 0; i < n; i++)
			cin >> stus[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (stus[i]>stus[j] && opt_1[i] < opt_1[j] + 1)
					opt_1[i] = opt_1[j] + 1;
			}
		}
		for (int i = n - 1; i >0; i--)
		{
			for (int j = i + 1; j <n; j++)
			{
				if (stus[i] > stus[j] && opt_2[i] < opt_2[j] + 1)
					opt_2[i] = opt_2[j] + 1;
			}
		}
		int max = -INT_MAX;
		for (int i = 0; i < n; i++)
		{
			opt_1[i] += opt_2[i];
			if (opt_1[i]>max) max = opt_1[i];
		}
		cout << n - max + 1 << endl;
	}
}


/////////////////////////////////////////////////////////
void DynamicProgramming::run(){
	vector<vector<int>> A = {
		{ 1, 3, 5, 9 },
		{ 8, 1, 3, 4 },
		{ 5, 0, 6, 1 },
		{ 8, 8, 4, 0 }
	};
	cout << MinPathSum(A) << endl;
	vector<int> arr = {5,2,3};
	cout << MinCoins(arr,11)<<endl;
	arr = { 5, 2, 5,3 };
	cout << MinCoinsOnce(arr, 10)<<endl;

}