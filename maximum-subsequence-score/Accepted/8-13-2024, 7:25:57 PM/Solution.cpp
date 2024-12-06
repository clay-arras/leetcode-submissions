// https://leetcode.com/problems/maximum-subsequence-score

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int N = (int)nums1.size();
        vector<pair<int, int>> nums;
        for (int i=0; i<N; i++) 
            nums.push_back({nums2[i], nums1[i]});
        sort(nums.rbegin(), nums.rend());

        priority_queue<int> pq;
        long long sum = 0, ans = 0;
        for (int i=0; i<N; i++) {
            sum += nums[i].second;
            pq.push(-nums[i].second);
            if ((int)pq.size() >= k) {
                ans = max(ans, sum * nums[i].first);
                sum += pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};