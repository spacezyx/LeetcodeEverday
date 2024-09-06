#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool isPalindrome(string s) {
    int len = s.size();
    string cleared = "";
    for(int i = 0; i < len; i++) {
        if((s[i] >= '0') && (s[i] <= '9'))
            cleared.push_back(s[i]);
        else if((s[i] >= 'a') && (s[i] <= 'z'))
            cleared.push_back(s[i]);
        else if(((s[i] >= 'A') && (s[i] <= 'Z')))
            cleared.push_back(s[i] + 'a' - 'A');
    }
    int size = cleared.size();
    for(int i = 0; i < (size / 2); i++) {
        if(cleared[i] != cleared[size - 1 - i])
            return false;
    }
    return true;
}

int main() {
    string s = "race a car";
    bool result = isPalindrome(s);
    cout << result;
    return 0;
}
