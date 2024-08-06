#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findNumbers(vector<int>& nums) {
    int res = 0;
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        if(nums[i] == 0) continue;
        int tmp = nums[i];
        int len = 0;
        while(tmp != 0) {
            len++;
            tmp = tmp / 10;
        }
        if(len % 2 == 0) {
            res++;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {555,901,482,1771};
    int result = findNumbers(nums);
    cout << result;
    return 0;
}
