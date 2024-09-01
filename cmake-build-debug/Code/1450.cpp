#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int result = 0;
    int size = startTime.size();
    for(int i = 0; i < size; i++) {
        if((queryTime >= startTime[i]) && (queryTime <= endTime[i]))
            result++;
    }

    return result;
}

int main() {
    vector<int> startTime = {1, 2, 3};
    vector<int> endTime = {3, 2, 7};
    int queryTime = 4;
    int result = busyStudent(startTime, endTime, queryTime);
    cout << result;
    return 0;
}
