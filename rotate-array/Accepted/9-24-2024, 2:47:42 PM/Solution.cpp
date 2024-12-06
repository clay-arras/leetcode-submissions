// https://leetcode.com/problems/rotate-array

class Solution {
public:

    const static long long MX = 2e5+1;
    void rotate(vector<int>& nums, int k) {
        int N = (int)nums.size();
        
        const auto sol1 = [&]() {
            vector<int> ans;
            for (int i=(MX*N-k)%N; i<N; i++)
                ans.push_back(nums[i]);
            for (int i=0; i<(MX*N-k)%N; i++)
                ans.push_back(nums[i]);
            nums = ans;
        };        
        const auto sol2 = [&]() {
            for (int j=0; j<gcd(N, k); j++) {
                int ptr = nums[j];
                for (int i=1; i<=N/gcd(N, k); i++) 
                    swap(nums[(k*i + j)%N], ptr);
            }
        };
        const auto sol3 = [&]() {
            deque<int> dq(nums.begin(), nums.end());
            for (int i=0; i<k; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            nums = {dq.begin(), dq.end()};
        };

        sol3();
    }
};