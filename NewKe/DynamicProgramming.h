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
  换钱最少的货币数目
*/
int MinCoins(vector<int> & arr,int aim){
	int m = arr.size();
	vector<vector<int>> dp(m,vector<int> (aim+1,INT_MAX));
	//=============初始化第一列与第一行
	for (size_t j = 0; j <= aim; j+=arr[0]){//只有面值为arr[0]的钱币
		 dp[0][j] = j / arr[0];
	}
	for (size_t i = 0; i < m;dp[i][0]=INT_MAX,i++);
	//=============初始化第一列与第一行
	for (size_t i = 1; i < m; i++)
		for (size_t j = 1; j <= aim; j++)
		{
			dp[i][j] = dp[i - 1][j];//当前面值的钱币一张都不使用
			for (size_t k = 1; k < j/arr[i]; k++)//穷举使用当前面值钱币k次的情况
			{
				if (dp[i][j]>dp[i - 1][j - arr[i] * k] + k){
					dp[i][j] = dp[i - 1][j - arr[i] * k] + k;
				}
			}
		}
		return dp[m - 1][aim];
}
void DynamicProgramming::run(){
	vector<vector<int>> A = {
		{ 1, 3, 5, 9 },
		{ 8, 1, 3, 4 },
		{ 5, 0, 6, 1 },
		{ 8, 8, 4, 0 }
	};
	cout << MinPathSum(A) << endl;
	vector<int> arr = {5,2,5,3};
	cout << MinCoins(arr,15)<<endl;

}