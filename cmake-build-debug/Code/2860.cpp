#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int countWays(vector<int>& nums) {
    // 思路：先排序，然后遍历
    // 如果出现一个位置的index大于值的情况，则可能从头到它是一种选择方法
    // 但还需要再验证一遍它后面的那个数是否满足严格大于选择数量的情况
    // 最后还有一种特殊情况，如果第一个数不是0，那么什么都不选也是一种方法
    int result = 0;
    int size = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < size; i++) {
        if(nums[i] < (i + 1)) {
            if(i < (size - 1) && (nums[i+1] > (i + 1))) result++;
            else if(i == (size - 1)) result++;
        }
    }
    if(nums[0] != 0) {
        result++;
    }
    return result;
}

int main() {
    vector<int> nums = {1,1,0,1};
    long long result = countWays(nums);
    cout << result;
    return 0;
}
