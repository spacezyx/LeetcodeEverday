#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

string convertToTitle(int columnNumber) {
    // 思路： 实际上就是转换成26进制，特殊情况是取余为0时
    string result = "";
    while(columnNumber > 26) {
        int tmp = columnNumber % 26;
        columnNumber = columnNumber / 26;
        if(tmp == 0) {
            result += "Z";
            columnNumber -= 1;
        } else {
            result += tmp + 'A' - 1;
        }

    }
    char t = columnNumber + 'A' - 1;
    result +=  t;
    reverse(result.begin(),result.end());
    return result;
}

int main() {
    int columnNumber = 52;
    string result = convertToTitle(columnNumber);
    cout << result;
    return 0;
}
