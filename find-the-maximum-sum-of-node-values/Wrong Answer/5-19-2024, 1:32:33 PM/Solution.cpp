// https://leetcode.com/problems/find-the-maximum-sum-of-node-values

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int N = (int)nums.size();
        vector<vector<int>> adj_list(N);
        vector<int> dp(N, 0);

        for (auto i : edges) {
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }

        dp[0] = nums[0]; 
        for (int i=1; i<N; i++) {
            dp[i] = dp[i-1] + nums[i];
            for (int j : adj_list[i]) {
                if (i < j) continue;
                if (dp[i] < dp[i-1] + (nums[i]^k) - nums[j] + (nums[j]^k)) {
                    dp[i] = dp[i-1] + (nums[i]^k) - nums[j] + (nums[j]^k);
                    nums[i] ^= k;
                    nums[j] ^= k;
                }
            }
        }
        return dp[N-1];
    }
};