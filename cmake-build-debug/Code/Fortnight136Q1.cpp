#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int winningPlayerCount(int n, vector<vector<int>>& pick) {
    // 思路：排序后计数即可
    int size = pick.size();
    if(size == 0) return 0;
    int res = 0;
    map<vector<int>, int> myMap;
    for(int i = 0; i < size; i++) {
        auto it = myMap.find(pick[i]);
        if (it != myMap.end()) {
            // 键存在，修改其对应的值
            (it->second)++;
        } else {
            // 键不存在，可以选择插入新的键值对
            myMap[pick[i]] = 1;
        }
    }

    int last = -1;
    int now = -1;
    for(auto k : myMap) {
        now = (k.first)[0];
        if(now == last) continue;
        if((k.second) > now) {
            res++;
            last = now;
        }
    }

    return res;
}

int main() {
    vector<vector<int>> pick = {{0,8},{0,3}};
    int n = 2;
    int result = winningPlayerCount(n, pick);
    cout << result;
    return 0;
}
