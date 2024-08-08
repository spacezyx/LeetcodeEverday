class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 太简单直接在Leetcode里写了
        map<int, int> my_map;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(my_map.find(nums[i]) != my_map.end()) {
                my_map[nums[i]]++;
                if(my_map[nums[i]] > (size / 2)) return nums[i];
            } else {
                my_map[nums[i]] = 1;
            }
        }
        return nums[0];
    }
};