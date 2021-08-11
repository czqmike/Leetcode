/*** 
 * @Author: czqmike
 * @Date: 2021-07-24 15:54:06
 * @LastEditTime: 2021-07-24 16:48:25
 * @LastEditors: czqmike
 * @Description: 
	给定一个n，求 [1,n] 这 n 个数字的排列组合有多少个。
	条件：相邻的两个数字差的绝对值不能等于1.
	例如：
	4
	[2, 4, 1, 3]
	[3, 1, 4, 2]
 * @FilePath: \Leetcode\阿里2021秋招\排列组合.cpp
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n = 4;
vector<vector<int>> res;
vector<int> used(n + 1, 0);
vector<int> temp(n, 0);

void f(int index) { // index in [0, n - 1], stands layer.
    if (index == n) {
        res.push_back(temp);
        return;
    }

    for (int i = 1; i <= n; ++i) { // i in [1, n], stands each number in layer.
        if (!used[i] && (temp.size() == 0 || abs(i - temp[index - 1]) != 1)) {
            // temp is empty or is not standing by.
            used[i] = 1;
            temp[index] = i;
            f(index + 1);
            used[i] = 0;
        }
    }
}

int main() {
    f(0);

    // cout << "res.size = " << res.size() << '\n';
    for (auto v : res) {
        for (auto item : v) {
            cout << item << ' ';
        }
        cout << '\n';
    }

    return 0;
}
