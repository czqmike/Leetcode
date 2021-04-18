/*** 
 * @Author: czqmike
 * @Date: 2021-04-16 10:20:14
 * @LastEditTime: 2021-04-18 18:52:35
 * @LastEditors: czqmike
 * @Description: 
 *  小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
    你能帮帮小Q吗？


    输入描述:

    输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
    


    输出描述:

    对于每组数据，输出移位后的字符串。


    输入例子1:
    AkleBiCeilD

    输出例子1:
    kleieilABCD
 * @FilePath: /undefined/mnt/d/git_repos/Leetcode/腾讯2017暑期实习生/2_字符移位.cpp
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string& srt(string& s) {
    for (int i = 0; i < s.length() - 1; ++i) {
        for (int j = 0; j < s.length() - i - 1; ++j) {
            if (isupper(s[j]) && islower(s[j + 1])) {
                swap(s[j], s[j + 1]);
            }
        }
    }
    return s;
}

int main() {
    string s = "";
    while (cin >> s) {
        cout << srt(s) << endl;
    }
    return 0;
}