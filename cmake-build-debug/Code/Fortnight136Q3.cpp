#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int minFlips(vector<vector<int>>& grid) {
    // 思路：满足行列要求即grid[i][j] == grid[i][col_num - j - 1] == grid[row_num - i - 1][j]
    // 分别用左上方、右上方、左下方、右下方做模板，求变成所需的次数
    // 保证1的数量是4的倍数就是在线上的都是0,或者这条线上的数字是1的4倍
    int res = 0;
    int row_num = grid.size();
    int col_num = grid[0].size();
    if((row_num == 1) && (col_num == 1)) return grid[0][0];


    // 开始四次尝试
    for(int i = 0; i < row_num / 2;i++)
        for(int j = 0;j < col_num / 2;j++){
            map<int,int>mp;
            mp[grid[i][j]]++;
            mp[grid[row_num-i-1][j]]++;
            mp[grid[i][col_num-j-1]]++;
            mp[grid[row_num-i-1][col_num-j-1]]++;
            res += min(mp[1],mp[0]);
        }
//    int left_top = 0;
//    for(int i = 0; i < half_row; i++) {
//        for(int j = 0; j < half_col; j++) {
//            //分别是右上/左下/右下
//            if(grid[i][j] != grid[i][col_num - j - 1]) left_top++;
//            if(grid[i][j] != grid[row_num - i - 1][j]) left_top++;
//            if(grid[i][j] != grid[row_num - i - 1][col_num - j - 1]) left_top++;
//        }
//    }
//    int right_top = 0;
//    for (int i = 0; i < half_row; i++) {
//        for(int j = 0; j < half_col; j++) {
//            if(grid[i][col_num - j - 1] != grid[i][j]) right_top++;
//            if(grid[i][col_num - j - 1] != grid[row_num - i - 1][j]) right_top++;
//            if(grid[i][col_num - j - 1] != grid[row_num - i - 1][col_num - j - 1]) right_top++;
//        }
//    }
//    int left_bottom = 0;
//    for (int i = 0; i < half_row; i++) {
//        for(int j = 0; j < half_col; j++) {
//            if(grid[row_num - i - 1][j] != grid[i][j]) left_bottom++;
//            if(grid[row_num - i - 1][j] != grid[i][col_num - j - 1]) left_bottom++;
//            if(grid[row_num - i - 1][j] != grid[row_num - i - 1][col_num - j - 1]) left_bottom++;
//        }
//    }
//    int right_bottom = 0;
//    for (int i = 0; i < half_row; i++) {
//        for(int j = 0; j < half_col; j++) {
//            if(grid[row_num - i - 1][col_num - j - 1] != grid[i][j]) right_bottom++;
//            if(grid[row_num - i - 1][col_num - j - 1] != grid[row_num - i - 1][j]) right_bottom++;
//            if(grid[row_num - i - 1][col_num - j - 1] != grid[i][col_num - j - 1]) right_bottom++;
//        }
//    }

    int cnt = 0;
    int v=0;
    if(row_num % 2 == 1){
        int l = 0,r = col_num - 1;
        int i = row_num / 2;
        while(l < r){
            if(grid[i][l] != grid[i][r]) res++, v++;
            else if(grid[i][l] == 1) cnt += 2;
            l++,r--;
        }
    }
    if(col_num % 2 == 1){
        int l = 0,r= row_num - 1;
        int j = col_num/2;
        while(l < r){
            if(grid[l][j] != grid[r][j]) v++,res++;
            else if(grid[l][j] == 1)cnt += 2;
            l++,r--;
        }
    }

    if(row_num % 2 == 1 && col_num % 2 == 1 && grid[row_num/2][col_num/2] == 1) res++;
    if(cnt % 4 && v == 0) res += 2;

    return res;
}


int main() {
    vector<vector<int>> grid = {{1},{1},{1},{0}};
    int result = minFlips(grid);
    cout << result;
    return 0;
}

