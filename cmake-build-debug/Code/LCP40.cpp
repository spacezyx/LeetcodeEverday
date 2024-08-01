#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxmiumScore(vector<int>& cards, int cnt) {
    // 思路：数字可以分为奇数/偶数
    // 任意偶数之和为偶数，两个奇数之和为偶数
    // 排序后找最大的组合即可

    // 看题解后的修正：之前思路写的一坨
    // 题解思路为从大到小排序cards，将前cnt个相加
    // 若为偶数直接返回，若为奇数将最小的偶数与剩下最大的奇数交换
    int res = 0;
    int size = cards.size();
    vector<int> odd;
    vector<int> even;
    for(int i = 0; i < size; i++) {
        if(cards[i] % 2 == 0) {
            even.push_back(cards[i]);
        } else {
            odd.push_back(cards[i]);
        }
    }
    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());
    int min1 = -1;
    int min2 = -1;

    if(cnt == 0) return 0;
    int now = 0;
    while(now < cnt) {
        if(cnt - now >= 2) {
            if(odd.size() >= 2) {
                if(even.size() >= 2) {
                    if((odd[0] + odd[1]) < (even[0] + even[1])) {
                        res += (even[0] + even[1]);
                        min1 = even[0];
                        min2 = even[1];
                        vector<int>::iterator f = even.begin();
                        even.erase(f);
                        vector<int>::iterator s = even.begin();
                        even.erase(s);
                    }
                    else {
                        res += (odd[0] + odd[1]);
                        vector<int>::iterator f = odd.begin();
                        odd.erase(f);
                        vector<int>::iterator s = odd.begin();
                        odd.erase(s);
                    }
                } else {
                    res += (odd[0] + odd[1]);
                    vector<int>::iterator f = odd.begin();
                    odd.erase(f);
                    vector<int>::iterator s = odd.begin();
                    odd.erase(s);
                }
            } else {
                if(even.size() >= 2) {
                    res += (even[0] + even[1]);
                    min1 = even[0];
                    min2 = even[1];
                    vector<int>::iterator f = even.begin();
                    even.erase(f);
                    vector<int>::iterator s = even.begin();
                    even.erase(s);
                } else {
                    return 0;
                }
            }
            now += 2;
        } else if(cnt - now == 1){
            if(!even.empty()) {
                res += (even[0]);
                vector<int>::iterator f = even.begin();
                even.erase(f);
                now++;
            } else {
                if(odd.size() >= 2 && min2 >= 0) {
                    res += odd[0] + odd[1] - min2;
                    now++;
                } else {
                    return 0;
                }
            }
        }
    }

    return res;
}

int main() {
    vector<int> cards = {3,3,1};
    int cnt = 1;
    int result = maxmiumScore(cards, cnt);
    cout << result;
    return 0;
}
