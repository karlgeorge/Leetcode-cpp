// Leetcode-cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
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
	//53
	int maxSubArray(vector<int>& nums) {
		int length = nums.size();
		if (length == 0)
			return 0;
		int dp = nums[0];
		bool flag = dp >= 0;
		int maxd = nums[0];
		int ans = dp;
		for (int i = 1; i < length; ++i) {
			dp = max(dp + nums[i], max(0, nums[i]));
			ans = max(ans, dp);
			maxd = max(maxd, nums[i]);
			if (nums[i] >= 0)
				flag = true;
		}
		if (!flag) {
			return maxd;
		}
		return ans;
	}
	//53 div



	//198
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		if (len == 1) {
			return nums[0];
		}
		int dp[1001];
		memset(dp, 0, sizeof(dp));
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < len; ++i) {
			dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
		}
		return max(dp[len - 2], dp[len - 1]);
	}
	//303
	int sum[10000];
	vector<int> a;
	void NumArray(vector<int>& nums) {
		memset(sum, 0, sizeof(sum));
		a = nums;
		if (nums.size() != 0)
			sum[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			sum[i] = sum[i - 1] + nums[i];
		}
	}
	int sumRange(int i, int j) {
		return sum[j] - sum[i] + a[i];
	}
	//647
	int countSubstrings(string s) {
		string temp = "#";
		for (int i = 0; i < s.size(); ++i) {
			temp = temp + s[i] + '#';
		}
		int length = temp.size();
		int last_mid = 0;
		int max_edge = 0;
		int dp[10005];
		memset(dp, 0, sizeof(dp));
		int step = 0;
		int ans = 0;
		while (step < length) {

			//if (step < max_edge) {
			//	dp[step] = dp[2 * last_mid - step];
			//	ans += dp[step];
			//}
			//int i = 0;
			//for (i = 0; step + i < length && step - i >= 0; ++i) {
			//	if (temp[step + i] != temp[step - i]) {
			//		break;
			//	}
			//}
			//i = i - 1;
			//if (step + i >= max_edge) {
			//	max_edge = step + i;
			//	last_mid = step;
			//	if (!(i == 0 && temp[step] == '#')) {
			//		++dp[step];
			//		ans += dp[step];
			//	}
			//	++step;
			//}
			int base = 0;
			if (step <= max_edge) {
				base = dp[2 * last_mid - step];
			}
			//for (; step + base < length && step - base >= 0; ++base) {
			//	if (temp[step + base] != temp[step - base]) {
			//		base = base - 1;
			//		break;
			//	}
			//}
			int i = base;
			do{
				if (temp[step + i] == '#') {
					--base;
				}
				++i;
				++base;
				if (!(step + i < length && step - i >= 0)) {
					break;
				}
			} while (temp[step + i] == temp[step - i]);
			dp[step] += base;
			//cout << dp[step] << "";
			ans += dp[step];
			step++;
		}
		return ans;
	}
	string longestPalindrome(string s) {
		string temp = "#";
		for (int i = 0; i < s.size(); ++i) {
			temp = temp + s[i] + '#';
		}
		int length = temp.size();
		int last_mid = 0;
		int max_edge = 0;
		int dp[2005];
		memset(dp, 0, sizeof(dp));
		int step = 0;
		int ans = 0;
		int x = 0;
		while (step < length) {

			int base = 0;
			if (step <= max_edge) {
				base = dp[2 * last_mid - step];
			}
			int i = base;
			do{
				if (temp[step + i] == '#') {
				}
				++i;
				++base;
				if (!(step + i < length && step - i >= 0)) {
					break;
				}
			} while (temp[step + i] == temp[step - i]);
			dp[step] += base;
			if (dp[step] > ans) {
				ans = dp[step];
				x = step;
			}
			step++;
		}
		int i = 0;
		//cout << x << endl;
		string ss = "";
		while(temp[x + i] == temp[x - i]){
			if (temp[x + i] != '#') {
				if (i != 0) {
					ss = temp[x - i] + ss + temp[x - i];
				}
				else ss = temp[x];
			}
			++i;
			if (!(x + i < length && x - i >= 0)) {
				break;
			}
		}
		return ss;
	}
};



int main()
{
	Solution s;
	cout << s.longestPalindrome("cbbd") << endl;
}

