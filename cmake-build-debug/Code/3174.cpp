#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

string clearDigits(string s) {
    int size = s.size();
    string res = "";
    vector<char> remains;
    for(int i = 0; i < size; i++) {
        if((s[i] >= '0') && (s[i] <= '9')) {
            remains.pop_back();
        } else {
            remains.push_back(s[i]);
        }
    }
    int len = remains.size();
    for(int i = 0; i < len; i++) {
        res += remains[i];
    }
    return res;
}

int main() {
    string s = "cb3";
    string result = clearDigits(s);
    cout << result;
    return 0;
}
