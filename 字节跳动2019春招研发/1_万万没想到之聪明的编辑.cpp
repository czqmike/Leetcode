/*** 
 * @Author: czqmike
 * @Date: 2021-04-11 11:00:25
 * @LastEditTime: 2021-04-11 12:40:00
 * @LastEditors: czqmike
 * @Description: 
 * 我叫王大锤，是一家出版社的编辑。我负责校对投稿来的英文稿件，这份工作非常烦人，因为每天都要去修正无数的拼写错误。但是，优秀的人总能在平凡的工作中发现真理。我发现一个发现拼写错误的捷径：

    1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
    2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello
    3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC

    我特喵是个天才！我在蓝翔学过挖掘机和程序设计，按照这个原理写了一个自动校对器，工作效率从此起飞。用不了多久，我就会出任CEO，当上董事长，迎娶白富美，走上人生巅峰，想想都有点小激动呢！
    ……
    万万没想到，我被开除了，临走时老板对我说： “做人做事要兢兢业业、勤勤恳恳、本本分分，人要是行，干一行行一行。一行行行行行；要是不行，干一行不行一行，一行不行行行不行。” 我现在整个人红红火火恍恍惚惚的……

    请听题：请实现大锤的自动校对程序

    输入描述:
    第一行包括一个数字N，表示本次用例包括多少个待校验的字符串。

    后面跟随N行，每行为一个待校验的字符串。

    输出描述:
    N行，每行包括一个被修复后的字符串。

    输入例子1:
    2
    helloo
    wooooooow

    输出例子1:
    hello
    woow
 * @FilePath: \Leetcode\字节跳动2019春招研发\万万没想到之聪明的编辑.cpp
 */

#include <iostream>
#include <vector>
using namespace std;
bool AABB(string& s, int index) {
    if (s.length() - index < 4) { 
        return false;
    }
    return s[index] == s[index + 1] && s[index + 2] == s[index + 3];
}
bool AAA(string& s, int index) {
    if (s.length() - index < 3) { 
        return false;
    }
    return s[index] == s[index + 1] && s[index] == s[index + 2];
}
// void fix(string& s) {
//     vector<bool> mask;
//     for (int i = 0; i < s.length(); ++i) {
//         if (AAA(s, i)) {
//             mask.push_back(0);
//         } else if (AABB(s, i)) {
//             mask.push_back(1);
//             mask.push_back(1);
//             mask.push_back(0);
//             i += 2;
//         } else {
//             mask.push_back(1);   
//         }
//     }
//     string ns = "";
//     for (int i = 0; i < s.length(); ++i) {
//         if (mask[i]) {
//             ns += s[i];
//         }
//     }
//     s = ns;
// }

void fix(string& s) {
    for (int i = 0; i < s.length(); ++i) {
        if (AAA(s, i)) {
            s.erase(i, 1);
            --i;
        }
        if (AABB(s, i)) {
            s.erase(i + 2, 1);
            --i;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        fix(s);
        cout << s << '\n';    
    }
    return 0;
}