class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        // 太简单直接leetcode里写了，直接排序最小值相减就行
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        return nums2[0] - nums1[0];
    }
};