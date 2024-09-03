#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long maxStrength(vector<int>& nums) {
    // 思路：正整数都可以乘，负整数必须取2的倍数个，0是除0以外只有一个负整数的情况
    long long result = 1;
    int size = nums.size();
    bool zero_flag = false;
    bool changed_flag = false;
    vector<int> negatives;
    for(int i = 0; i < size; i++) {
        if(nums[i] > 0) {
            result *= nums[i];
            changed_flag = true;
        } else if(nums[i] < 0) {
            negatives.push_back(nums[i]);
        } else {
            zero_flag = true;
        }
    }
    int negatives_size = negatives.size();
    if(negatives_size >= 2) {
        sort(negatives.begin(), negatives.end());
        int end = negatives_size / 2 * 2;
        for(int i = 0; i < end; i++) {
            result *= negatives[i];
            changed_flag = true;
        }
    }
    if(!changed_flag) {
        if(zero_flag) return 0;
        else return negatives[0];
    }

    return result;
}

int main() {
    vector<int> nums = {-2,-3,8,9};
    long long result = maxStrength(nums);
    cout << result;
    return 0;
}
