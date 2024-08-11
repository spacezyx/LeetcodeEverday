#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    // 思路：把元素往左移动，遇到val就跳过，等待不是val的去填这个位置
    int size = nums.size();
    int left = 0;
    for(int i = 0; i < size; i++) {
        if(nums[i] != val) {
            nums[left] = nums[i];
            left++;
        }
    }
    return left;
}

int main() {
    vector<int> nums = {4,5};
    int val = 4;
    int result = removeElement(nums, val);
    cout << result;
    return 0;
}
