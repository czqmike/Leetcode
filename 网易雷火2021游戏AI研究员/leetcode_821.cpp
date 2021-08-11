/*** 
 * @Author: czqmike
 * @Date: 2021-04-24 10:27:28
 * @LastEditTime: 2021-04-24 11:45:33
 * @LastEditors: czqmike
 * @Description: 
 * Leetcode 440:
 *  Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

    Example 1:

    Input: S = “loveleetcode”, C = ‘e’
    Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

    Note:

    S string length is in [1, 10000].
    C is a single character, and guaranteed to be in string S.
    All letters in S and C are lowercase.
 * @FilePath: \Leetcode\网易雷火2021游戏AI研究员\leetcode_440.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s = "loveleetcode";
    char c = 'e'; 

    int n = s.length();
    vector<int> v(n, n); // min distance

    int pos = -n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == c) {
            pos = i;
        }
        v[i] = min(v[i], abs(i - pos));
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == c) {
            pos = i;
        }
        v[i] = min(v[i], abs(i - pos));
    }

    for (auto item : v) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}