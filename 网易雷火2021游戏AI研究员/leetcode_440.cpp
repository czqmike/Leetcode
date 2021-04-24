/*** 
 * @Author: czqmike
 * @Date: 2021-04-24 10:27:28
 * @LastEditTime: 2021-04-24 10:29:08
 * @LastEditors: czqmike
 * @Description: 
 * Leetcode 440:
    题目链接： https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

    1.题目描述：
    输入正整数n, k，n >= k, 找出[1,n]范围内按照字典排序的最小第k个值。

    输入描述：
    输入两个正整数n,k

    输出描述：
    一个正整数

    示例：
    输入
    15, 3

    输出
    11
 * @FilePath: \Leetcode\网易雷火2021游戏AI研究员\leetcode_440.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 55;
    vector<int> v;
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        v.push_back(cur);

        if (cur * 10 <= n) {
            cur *= 10;
        } else {
            if (cur >= n) {
                cur /= 10;
            }
            cur += 1;
            while (cur % 10 == 0) {
                cur /= 10;
            }
        } 
    }

    for (int item : v) {
        cout << item << ' ';
    }
    cout << endl;
    cout << "v.size: " << v.size() << endl;
    return 0;
}