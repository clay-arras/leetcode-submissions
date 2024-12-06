// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=0, m=0;
        int l1=(int)nums1.size(), l2=(int)nums2.size();

        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);

        int i = 0, lastnum = -1;
        while(n <= l1 and m <= l2) {
            if (n + m == (l1 + l2) / 2) {
                if ((l1+l2) % 2 == 1) {
                    return min(nums1[n], nums2[m]);
                } else {
                    return (min(nums1[n], nums2[m]) + lastnum)*1.0 / 2;
                }
            }
            if (nums1[n] < nums2[m]) lastnum = nums1[n], n++;
            else lastnum = nums2[m], m++;
            
        }
        return -1;
    }
};