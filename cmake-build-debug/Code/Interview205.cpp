#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t) {
    // 思路：造两个hash表判断映射
    int len = s.length();
    map<char, char> my_map;
    map<char, char> my_map2;
    for(int i = 0; i < len; i++) {
        if(my_map.find(t[i]) != my_map.end()) {
            if(my_map[t[i]] != s[i]) return false;
        } else if(my_map2.find(s[i]) != my_map2.end()){
            if(my_map2[s[i]] != t[i]) return false;
        } else {
            my_map[t[i]] = s[i];
            my_map2[s[i]] = t[i];
        }
    }
    return true;
}

int main() {
    string s = "egg";
    string t = "add";
    bool result = isIsomorphic(s, t);
    cout << result;
    return 0;
}
