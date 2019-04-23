// Leetcode-cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	//121
	int maxProfit(vector<int>& prices) {
		int length = prices.size();
		if (length <= 1)
			return 0;
		int last_max = prices[length - 1];
		int ans = 0;
		for (int i = length - 2; i >= 0; --i) {
			ans = max(ans, -prices[i] + last_max);
			last_max = max(last_max, prices[i]);
		}
		return ans;
	}
	//746
	int minCostClimbingStairs(vector<int>& cost) {
		int length = cost.size();
		int dp[1001];
		for (int i = 2; i <= length; ++i) {
			dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
		}
		return dp[length - 1];
	}
	//70
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		int a = 1;
		int b = 2;
		for (int i = 3; i <= n; ++i) {
			int c = a;
			a = b;
			b = c + b;
		}
		return b;
	}
};



int main()
{
	Solution s;
	cout << s.climbStairs(4) << endl;
}

