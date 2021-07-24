/*** 
 * @Author: czqmike
 * @Date: 2021-05-09 10:02:51
 * @LastEditTime: 2021-05-09 10:16:16
 * @LastEditors: czqmike
 * @Description: 
 * 题目描述：
    小美和小团要搬家,他们要把家具从围栏上搬过去.围栏由n个独立的木桩排成一条直线组成,第i个木桩编号为i.由于他们体力的限制,只能越过高度不高于h的围栏.同时家具又要有宽度限制,只有连续m个木桩都能搬过去才能成功将家具搬过去.现在他们想知道他们能否成功搬家.



    输入描述
    第一行三个整数n,m和h，含义如上文所述。

    第二行n个整数，height1,...,heightn，依次表示每个木桩的高度。

    1≤m≤n≤105,0≤h,heighti≤109。

    输出描述
    输出一个整数，若能成功搬家,输出第一个跨过的木桩的编号,若有多组答案输出最小的。否则,输出整数-1。


    样例输入
    5 3 2
    3 2 1 1 2
    样例输出
    2
 * @FilePath: \Leetcode\美团2021\1.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }

    int goThroughI = -1; 
    for (int i = 0; i < n && goThroughI == -1; ++i) {
        if (v[i] > h) {
            continue;
        }

        int cnt = 0;
        for (int j = i; j < n; ++j) {
            if (v[j] > h) {
                break;
            }
            ++ cnt;
            if (cnt >= m) {
                goThroughI = i + 1;
            }
        }
    }

    cout << goThroughI;
    return 0;
}