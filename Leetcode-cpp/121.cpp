#include "pch.h"

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
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
};