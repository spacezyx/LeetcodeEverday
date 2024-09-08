#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int strStr(string haystack, string needle) {
    int long_len = haystack.size();
    int short_len = needle.size();
    if(long_len < short_len) return -1;
    int subtraction = long_len - short_len;
    if(subtraction == 0) {
        if(haystack == needle) {
            return 0;
        }
    }
    bool flag =true;
    for(int i = 0; i <= subtraction; i++) {
        int j = 0;
        for(; j < short_len; j++) {
            flag = true;
            if(haystack[i + j] != needle[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            return i;
        }
    }
    return -1;
}

int main() {
    string haystack = "abc";
    string needle = "c";
    int result = strStr(haystack, needle);
    cout << result;
    return 0;
}