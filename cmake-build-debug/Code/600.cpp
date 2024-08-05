#include <iostream>

using namespace std;

int findIntegers(int num) {
    // 没做出来，看了极客学长题解的
//    作者：极客学长Bravo
//    链接：https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/solutions/991246/leetcode-ac-dong-tai-gui-hua-jie-fa-han-eqceq/
//    来源：力扣（LeetCode）
//    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    // dp[i]是二进制长度为i的数字中不包含连续1的数量（可以以0开头）
    int dp[32];
    // 只有一位时
    dp[0] = 1;
    dp[1] = 2;
    // 这里是观察出的斐波那契，其实就是对于i来说，首位要么是0要么是1，如果是0就看i-1位，如果是1就看i-2位
    for (int i = 2; i < 32; ++i)  dp[i] = dp[i - 1] + dp[i - 2];
    int res = 0;
    // 这里非常奇妙，如果发现右边每出现一次 1xxxx(1后有k个digit, 每个x表示0或1)样子的连续数字
    // 满足不含有连续1的二进制数的总个数count 就需要增加f(k)，因为可以在这个数字上放一个'0',后面放任意一个有效长度为k的字符串
    // 继续循环考虑剩下的情况，也就是在这个digit上放一个'1'
    // 如果发现有连续的1，就退出循环并返回答案
    // 在循环结束时，返回count+1，包括数字n本身。
    int preBit = 0; // 记录当前digit的前一个digit
    int k = 30;     // 指针k, 从二进制数的末位开始向前移动
    while (k >= 0)
    {
        if (num & (1 << k)) // 从低位向高位扫描, 判断第k位是否为1
        {
            res += dp[k];
            if (preBit) return res; // 出现了连续的1, 直接返回res
            preBit = 1; // 当前digit是1, 将preBit更新为当前digit 1, 为下一轮迭代做准备
        }
        else preBit = 0;

        --k;
    }
    return res + 1; // 算上 num 本身
}

int main() {
    int n = 100;
    int result = findIntegers(n);
    cout << result;
    return 0;
}
