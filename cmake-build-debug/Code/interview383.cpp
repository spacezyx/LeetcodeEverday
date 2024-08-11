class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 太简单直接Leetcode写了，用数组代替map，遍历看有没有用的超过数量的
        int num[26] = {0};
        int size = magazine.length();
        for(int i = 0; i < size; i++) {
            num[magazine[i] - 'a']++;
        }
        int len = ransomNote.length();
        for(int i = 0; i < len; i++) {
            num[ransomNote[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(num[i] < 0) {
                return false;
            }
        }
        return true;
    }
};