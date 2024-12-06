// https://leetcode.com/problems/grumpy-bookstore-owner

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int N = (int)customers.size();
        int sum = 0;
        for (int i=0; i<N; i++) 
            sum += grumpy[i] * customers[i];

        int ans = 0;
        for (int i=0; i<minutes; i++) 
            if (!grumpy[i]) sum += customers[i];
        ans = max(ans, sum);
        for (int i=minutes; i<N; i++) {
            if (!grumpy[i]) sum += customers[i];
            ans = max(ans, sum);
            if (!grumpy[i-minutes]) sum -= customers[i-minutes];
        }

        return ans;
    }
};