#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int size = points.size();
        vector<int> xpoints;
        if (size == 0) {
            return 0;
        }
        for (int i = 0; i < size; i++) {
            xpoints.push_back(points[i][0]);
        }
        sort(xpoints.begin(), xpoints.end());
        int output = 0;
        for (int i = 0; i < size;) {
            output++;
            int start = xpoints[i];
            int now = start;
            while (now - start <= w && i < size) {
                now = xpoints[i];
                i++;
            }
            if(now - start > w) {
                i--;
            }
        }
        return output;
    }

int main() {
    vector<vector<int>> points = {{0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6}};
    int w = 2;
    int result = minRectanglesToCoverPoints(points, w);
    cout << result;
    return 0;
}
