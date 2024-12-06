// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minVal = INT_MAX;
        for (int i=0; i<(int)prices.size(); i++) {
            minVal = min(minVal, prices[i]);
            ans = max(ans, prices[i] - minVal);
        }
        return ans;
    }
};