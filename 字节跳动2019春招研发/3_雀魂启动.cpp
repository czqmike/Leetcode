/*** 
 * @Author: czqmike
 * @Date: 2021-04-11 16:37:27
 * @LastEditTime: 2021-04-11 18:07:38
 * @LastEditors: czqmike
 * @Description: 
    小包最近迷上了一款叫做雀魂的麻将游戏，但是这个游戏规则太复杂，小包玩了几个月了还是输多赢少。
    于是生气的小包根据游戏简化了一下规则发明了一种新的麻将，只留下一种花色，并且去除了一些特殊和牌方式（例如七对子等），具体的规则如下：

    总共有36张牌，每张牌是1~9。每个数字4张牌。
    你手里有其中的14张牌，如果这14张牌满足如下条件，即算作和牌
    14张牌中有2张相同数字的牌，称为雀头。
    除去上述2张牌，剩下12张牌可以组成4个顺子或刻子。顺子的意思是递增的连续3个数字牌（例如234,567等），刻子的意思是相同数字的3个数字牌（例如111,777）

    例如：
    1 1 1 2 2 2 6 6 6 7 7 7 9 9 可以组成1,2,6,7的4个刻子和9的雀头，可以和牌
    1 1 1 1 2 2 3 3 5 6 7 7 8 9 用1做雀头，组123,123,567,789的四个顺子，可以和牌
    1 1 1 2 2 2 3 3 3 5 6 7 7 9 无论用1 2 3 7哪个做雀头，都无法组成和牌的条件。

    现在，小包从36张牌中抽取了13张牌，他想知道在剩下的23张牌中，再取一张牌，取到哪几种数字牌可以和牌。

    输入描述:
    输入只有一行，包含13个数字，用空格分隔，每个数字在1~9之间，数据保证同种数字最多出现4次。

    输出描述:
    输出同样是一行，包含1个或以上的数字。代表他再取到哪些牌可以和牌。若满足条件的有多种牌，请按从小到大的顺序输出。若没有满足条件的牌，请输出一个数字0

    输入例子1:
    1 1 1 2 2 2 5 5 5 6 6 6 9

    输出例子1:
    9

    例子说明1:
    可以组成1,2,6,7的4个刻子和9的雀头

    输入例子2:
    1 1 1 1 2 2 3 3 5 6 7 8 9

    输出例子2:
    4 7

    例子说明2:
    用1做雀头，组123,123,567或456,789的四个顺子

    输入例子3:
    1 1 1 2 2 2 3 3 3 5 7 7 9

    输出例子3:
    0

    例子说明3:
    来任何牌都无法和牌
 * @FilePath: \Leetcode\字节跳动2019春招研发\3_雀魂启动.cpp
 */


/*** 
 * @description: 
 * 思路：顺子只能有7种情况，雀头和刻子有9种情况，总共是16^4*9=589,824种胡牌情况。
 *      只需要构造这些情况再与14张牌的分布进行比对即可。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool correct(vector<int>& v) {
    vector<int> times = vector<int>(9, 0);
    for (auto i : v) {
        times[i] ++;
    }
    for (auto i : times) {
        if (i > 4) {
            return false;
        }
    }
    return true;
}

bool test(vector<int>& v) { // 14张手牌
    vector<int> cv = vector<int>(v);

    for (int i = 0; i < 13; ++i) { // 本来就有4张牌的情况
        int cnt = 0;
        if (v[i] == v.back()) {
            cnt ++;
        }
        if (cnt == 4) {
            return false;
        }
    }

    const vector<vector<int>> k1 = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}, {5, 6, 7}, {6, 7, 8}, {7, 8, 9}, 
                              {1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}, {5, 5, 5}, {6, 6, 6}, {7, 7, 7}, {8, 8, 8}, {9, 9, 9}};
    const vector<vector<int>> k2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};

    vector<int> tr;

    for (auto i : k1) {
        tr.insert(tr.end(), i.begin(), i.end());
        // if (!correct(tr)) continue;
        for (auto j : k1) {
            tr.insert(tr.end(), j.begin(), j.end());
            if (!correct(tr)) continue;
            for (auto k : k1) {
                tr.insert(tr.end(), k.begin(), k.end());
                if (!correct(tr)) continue;
                for (auto l : k1) {
                    tr.insert(tr.end(), l.begin(), l.end());
                    if (!correct(tr)) continue;
                    for (auto m : k2) {
                        tr.insert(tr.end(), m.begin(), m.end());
                        if (!correct(tr)) continue;

                        sort(tr.begin(), tr.end()); 
                        sort(cv.begin(), cv.end());

                        for_each(tr.begin(), tr.end(), [](int n){cout << n << ' ';});
                        cout << endl;

                        if (tr == cv) {
                            return true;
                        }
                        tr.clear();
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    vector<int> v;
    for (int i = 0; i < 13; ++i) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    bool canWin = false;
    for (int i = 1; i <= 9; ++i) {
        v.push_back(i);
        if (test(v)) {
            cout << i << ' ';
            canWin = true;
        }
        v.pop_back();
    }
    if (!canWin) {
        cout << 0;
    }
    return 0;
}
