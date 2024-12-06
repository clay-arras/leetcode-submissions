// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    const static int MAXN = 1e2 + 3;
    int dp[MAXN][2];

    int rob(vector<int>& nums) {
        int N = (int)nums.size();
        if (N == 1)
            return nums[0];

        int ans = 0;
        dp[0][0] = nums[0];
        dp[1][0] = max(nums[0], nums[1]);
        for (int i=2; i<N-1; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-2][0] + nums[i]);
        }

        dp[N-1][1] = nums[N-1];
        dp[N-2][1] = max(nums[N-1], nums[N-2]);
        for (int i=N-3; i>=1; i--) {
            dp[i][1] = max(dp[i+1][1], dp[i+2][1] + nums[i]);
        }

        ans = max(dp[N-2][0], dp[1][1]);
        return ans;
    }
};