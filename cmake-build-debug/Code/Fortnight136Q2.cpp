#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minFlips(vector<vector<int>>& grid) {
    // 思路：对每行进行操作，看有多少个从头到尾和从尾到头不能匹配的，翻转次数为 min(x, col_num - x)
    // 列回文同理
    int res = 0;
    int row_num = grid.size();
    int col_num = grid[0].size();
    if((row_num == 1) || (col_num == 1)) return 0;
    // 行回文
    int row_times = 0;
    for(int i = 0; i < row_num; i++) {
        int half_col = col_num / 2;
        int this_row = 0;
        for(int j = 0; j < half_col; j++) {
            if(grid[i][j] != grid[i][col_num - j - 1]) {
                this_row++;
            }
        }
        row_times += min(this_row, (col_num - this_row));
    }
    // 列回文
    int col_times = 0;
    for(int i = 0; i < col_num; i++) {
        int half_row = row_num / 2;
        int this_col= 0;
        for(int j = 0; j < half_row; j++) {
            if(grid[j][i] != grid[row_num - j - 1][i]) {
                this_col++;
            }
        }
        col_times += min(this_col, (row_num - this_col));
    }

    res = min(row_times, col_times);

    return res;
}


int main() {
    vector<vector<int>> grid = {{1},{0}};
    int result = minFlips(grid);
    cout << result;
    return 0;
}

