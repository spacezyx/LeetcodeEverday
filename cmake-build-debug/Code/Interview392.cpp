class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 思路： 其实就是一个简单双指针
        int s_len = s.length();
        int t_len = t.length();
        int i = 0;
        int j = 0;
        for(; i < s_len;) {
            for(; j < t_len; j++) {
                if(s[i] == t[j]) {
                    i++;
                }
            }
            if(i != s_len) {
                return false;
            }
        }
        return true;
    }
};