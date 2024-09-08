// 思路太简单了直接写，先平方再排序

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            nums[i] = nums[i]* nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};