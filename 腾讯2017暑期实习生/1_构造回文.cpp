/*** 
 * @Author: czqmike
 * @Date: 2021-04-16 09:32:23
 * @LastEditTime: 2021-04-16 11:23:29
 * @LastEditors: czqmike
 * @Description: 
 * 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
    输出需要删除的字符个数。

    输入描述:

    输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
    


    输出描述:

    对于每组数据，输出一个整数，代表最少需要删除的字符个数。


    输入例子1:
    abcda
    google

    输出例子1:
    2
    2
 * @FilePath: /undefined/mnt/d/git_repos/Leetcode/腾讯2017暑期实习生/1_构造回文.cpp
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*** 
 * @description: 贪心算法，从两边向中间匹配回文串。
 * @param {string} input字符串s。
 * @return {int} 删除的字符个数。
 */
// int findL(string s) {
//     int i = 0, j = s.length() - 1;
//     int del = 0;

//     while (i < j) {
//         if (s[i] == s[j]) {
//             ++ i;
//             -- j;
//         } else {
//             -- j;
//             ++ del;
//         }
//     }
//     return del;
// }

const int MAX = 1001;
int dp[MAX][MAX];
/*** 
 * @description: 转化成原串s和reversed s求最长公共子序列问题。
 *             f(m - 1, n - 1) + 1,             s[m] == rs[n];
 *  f (m, n) = max( f(m, n - 1), f(m - 1, n) ), s[m] != rs[n];
 *             0,                               len(s) == 0 || len(rs) == 0.
 * @param {string} s
 * @return {int} 删除的字符个数。
 */
int f(string s) {
    string rs = string(s.rbegin(), s.rend());
    int n = s.length();
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i] == rs[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; 
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return n - dp[n][n];
}

int main() {
    string s = "";
    while (cin >> s) {
        cout << f(s) << endl;
    }
    return 0;
}