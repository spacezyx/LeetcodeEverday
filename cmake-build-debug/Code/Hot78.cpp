#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    // 思路：每遇到一个新元素，把它加入，再把它和之前的vector的并集加入
    vector<vector<int>> result;
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        result.push_back({nums[i]});
        int iter_size = result.size() - 1;
        for(int j = 0; j < iter_size; j++) {
            vector<int> iter_vec = result[j];
            iter_vec.push_back(nums[i]);
            result.push_back(iter_vec);
        }
    }
    result.push_back({});
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    int size = result.size();
    for(int i = 0; i < size; i++) {
        for(int tmp : result[i]) {
            cout << tmp << " ";
        }
        cout << endl;
    }
    return 0;
}