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
��̬ 1
�������·����
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
��̬ 2
  ��Ǯ���ٵĻ�����Ŀ
  ÿ����ֵ��Ǯ����ʹ�������
*/
int MinCoins(vector<int> & arr,int aim){
	int m = arr.size();
	vector<vector<int>> dp(m,vector<int> (aim+1,INT_MAX));
	//=============��ʼ����һ�����һ��===============
	for (size_t j = 0; j <= aim; j+=arr[0]){//ֻ����ֵΪarr[0]��Ǯ��
		 dp[0][j] = j / arr[0];
	}
	for (size_t i = 0; i < m;dp[i][0]=INT_MAX,i++);
	//================================================
	for (size_t i = 1; i < m; i++)
		for (size_t j = 1; j <= aim; j++)
		{
			dp[i][j] = dp[i - 1][j];//��ǰ��ֵ��Ǯ��һ�Ŷ���ʹ��
			//===========����ÿ����ֵ����ѡ��εĹؼ�==================
			for (size_t k = 1; k < j/arr[i]; k++)//���ʹ�õ�ǰ��ֵǮ��k�ε����
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

	for (size_t i = 0; i < m; opt[i][0]=0,i++);//��ֵΪ0ʱ
	opt[0][arr[0]] = 1;

	for (size_t i = 1; i < m; i++)
	  for (size_t j = 1; j < n; j++)
	  {
		  if (  j>=arr[i] && opt[i-1][j- arr[i]]!=INT_MAX )
			  // ���� opt[i-1][j- arr[i]]!=INT_MAX �Ǳ���ģ������Item=1->i-1 
			  // ����Ϊj-arr[i] ʱopt  �޽�Ļ���j opt[i - 1][j - arr[i]] + 1 �������
			  // �������С�����´���Ľ�
		    
		    opt[i][j] = min(opt[i - 1][j], opt[i - 1][j - arr[i]] + 1);  // ÿ����ֵֻ����һ�Σ���ѡ��ѡ
		    //Ǳ�ڵ�bug �˴������
		  else opt[i][j] = opt[i - 1][j];
	   } 
	  return opt[m - 1][n - 1] != INT_MAX ? opt[m - 1][n - 1] : -1;
}

//////////////////////���ٳ������� ////////////////////////
/*
��̬ 3
���鶯̬�滮,��һ�δ�ǰ���󣬽��Ϊopt_1
�ڶ��δӺ���ǰ�����Ϊopt_2,
 opt Ϊһά��opt[j]��ʾ��ǰ����item[1:j]ʱ�����������
 ��opt_1[i],opt_2[i] �ֱ��ʾ��0:i����������С���n-1:i����������У�
 opt_1[i]+opt_2[i] ���ʾ ѡ��i ��λ��Ϊ���ֵʱ���е������������
 opt_1[i]+opt_2[i] �����ֵ�����ҵ��˶������������Ҳ�͵õ�������
 ��������
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