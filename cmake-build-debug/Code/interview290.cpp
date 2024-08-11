#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

bool wordPattern(string pattern, string s) {
    // 思路：和interview205一样的思路，造两个hash表判断映射
    istringstream input( s );
    vector<string> t;
    string temp;
    while (input >> temp)
        t.push_back( temp );
    int len = pattern.length();
    int len2 = t.size();
    if(len != len2) return false;
    map<string, char> my_map;
    map<char, string> my_map2;
    for(int i = 0; i < len; i++) {
        if(my_map.find(t[i]) != my_map.end()) {
            if(my_map[t[i]] != pattern[i]) return false;
        } else if(my_map2.find(pattern[i]) != my_map2.end()){
            if(my_map2[pattern[i]] != t[i]) return false;
        } else {
            my_map[t[i]] = pattern[i];
            my_map2[pattern[i]] = t[i];
        }
    }
    return true;

}

int main() {
    string pattern = "aaa";
    string s = "aa aa aa aa";
    bool result = wordPattern(pattern, s);
    cout << result;
    return 0;
}
