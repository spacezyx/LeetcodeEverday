#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxConsecutiveAnswers(string answerKey, int k, char type) {
    int size = answerKey.size();
    int left = 0;
    int maxnum = 0;
    int diff = 0;
    int right = 0;
    for(; right < size; right++) {
        if(answerKey[right] == type) {
            continue;
        } else {
            diff++;
            if(diff <= k) {
                continue;
            } else {
                maxnum = max((right - left), maxnum);
                while(diff > k) {
                    if(answerKey[left] != type) diff--;
                    left++;
                }
            }
        }
    }
    return max((right - left), maxnum);
}

int maxConsecutiveAnswers(string answerKey, int k) {
    // 思路：分开算T和F的
    // 用滑动窗口法
    int t_num = maxConsecutiveAnswers(answerKey, k, 'T');
    int f_num = maxConsecutiveAnswers(answerKey, k, 'F');
    return max(t_num, f_num);
}

int main() {
    string answerKey = "TTFTTTTTFT";
    int k = 1;
    int result = maxConsecutiveAnswers(answerKey, k);
    cout << result;
    return 0;
}
