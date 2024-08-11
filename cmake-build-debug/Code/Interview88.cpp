#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // 思路：非常暴力，直接拼接后sort
    if(n == 0) {
        sort(nums1.begin(), nums1.end());
        return nums1;
    }
    for(int i = 0; i < n; i++) {
        nums1[m + i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
    return nums1;
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    vector<int> result = merge(nums1, m, nums2, n);
    cout << result[0];
    return 0;
}
