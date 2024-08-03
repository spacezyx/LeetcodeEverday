#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>


using namespace std;

bool cmp (const vector<int> a, const vector<int> b)
{
//    if((abs(a[0]) <= abs(b[0])) && (abs(a[1]) <= abs(b[1]))) {
//        return a < b;
//    } else if ((abs(a[0]) > abs(b[0])) && (abs(a[1]) > abs(b[1]))) {
//        return a > b;
//    } else

    if((max(abs(a[0]), abs(a[1]))) <= max(abs(b[0]), abs(b[1]))) {
        return true;
    } else {
        return false;
    }
}

int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
    // 思路：先把每个点对应到不同的标签
    // 对存放在同一标签下的坐标操作，找到边界
    // 再按坐标进行排序，然后计数
    // 这题写的又是一坨
    // 官解是定义正方形的半径为边长的一半 max(∣x∣,∣y∣)
    // 对于每个字符，计算字符到原点的最小的半径，并维护所有字符的次小半径
    // 根据题意，半径小于次小半径的正方形，是合法正方形。
    //最后遍历所有字符的最小距离，返回在合法正方形内的个数。
    map<char, vector<vector<int>>> myMap;
    int size = points.size();
    if(points.empty()) return 0;
    if(size == 1) return 1;
    int res = 0;

    for(int i = 0; i < size; i++) {
        // 使用find查找键
        auto it = myMap.find(s[i]);
        if (it != myMap.end()) {
            // 键存在，修改其对应的值
            (it->second).push_back(points[i]);
        } else {
            // 键不存在，可以选择插入新的键值对
            vector<vector<int>> tmp(1, points[i]);
            myMap[s[i]] = tmp;
        }
    }

    sort(points.begin(), points.end(), cmp);
//    for(int i = 0; i < size; i++) {
//        cout << points[i][0] << " " << points[i][1] << endl;
//    }

    int bound = INT_MAX;
    bool flag = false;
    for(auto it : myMap) {
//        cout << it.first << " " << it.second.size() << endl;
        if(it.second.size() > 1) {
            flag = true;
            vector<int> elements;
            for(auto ele : it.second) {
                elements.push_back(max(abs(ele[0]), abs(ele[1])));
            }
            sort(elements.begin(), elements.end());
            if(elements[0] < elements[1]) {
                if(elements[1] > 1) {
                    bound = min((elements[1] - 1), bound);
                } else {
                    bound = 0;
                }
            } else {
                if(elements[0] > 1) {
                    bound = min((elements[0] - 1), bound);
                } else {
                    bound = 0;
                }
            }
        }
    }
    if((bound == INT_MAX) && flag) bound = 0;

    if(!flag) return size;

    int now = 0;
    while ((max(abs(points[now][0]), abs(points[now][1])) <= bound) && (now < size)) {
        res++;
        now++;
    }

    return res;

}

int main() {
    vector<vector<int>> points = {{-1000000000,-1000000000}, {-1000000000,1000000000}};
    string s = "ab";
    int result = maxPointsInsideSquare(points, s);
    cout << result;
    return 0;
}
