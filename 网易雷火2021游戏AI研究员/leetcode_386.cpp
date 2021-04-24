/*** 
 * @Author: czqmike
 * @Date: 2021-04-24 09:35:21
 * @LastEditTime: 2021-04-24 10:03:47
 * @LastEditors: czqmike
 * @Description: 
 * 题目描述：
    Given an integer n, return 1 - n in lexicographical order.

    For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

    Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.

 * @FilePath: /网易雷火2021游戏AI研究员/leetcode_386.cpp
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