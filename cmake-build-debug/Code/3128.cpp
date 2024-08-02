#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long numberOfRightTriangles(vector<vector<int>>& grid) {
    // 思路： 从第一行开始遍历到最后一行，只要这行有2个及以上的1
    // 看这些1同列的数字，如果存在1即可组成直角三角形
    // 但是这样做会超时，所以事先统计一下每列1的数量
    long long res = 0;
    int row_num = grid.size();
    if (row_num < 2) {
        return res;
    }
    int col_num = grid[0].size();
    if (col_num < 2) {
        return res;
    }

    // 统计每列1的数量
    vector<int> num_in_every_col(col_num, 0);
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            if (grid[i][j] == 1) {
                num_in_every_col[j]++;
            }
        }
    }

    // 遍历每一行
    for (int i = 0; i < row_num; i++) {
        int row_position_size = 0;
        // 对每一列操作
        int same_col = 0;
        for (int j = 0; j < col_num; j++) {
            // 计数
            if (grid[i][j] == 1) {
                row_position_size++;
                same_col += num_in_every_col[j] - 1;
            }
        }
        if (row_position_size >= 2) {
            res += same_col * (row_position_size - 1);
        }
    }

    return res;
}

int main() {
    vector<vector<int>> grid = {{0,1,0},{0,1,1},{0,1,0}};
    long long result = numberOfRightTriangles(grid);
    cout << result;
    return 0;
}



