/*** 
 * @Author: czqmike
 * @Date: 2021-04-18 21:20:35
 * @LastEditTime: 2021-04-18 21:36:53
 * @LastEditors: czqmike
 * @Description: 
 * @FilePath: /腾讯2020暑期实习/5_网购.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    srand(time(NULL));
    int randnum = 10e4;
    int cnt = 0;
    for (int i = 0; i < randnum; ++i) {
        int left = n, right = n;
        for (int j = 0; j < n; ++j) {
            bool isl = false, isr = false;
            for (int k = 0; k < 2; ++k) {
                if (rand() % (left + right) < left) {
                    left --;
                    isl = true;
                } else {
                    right --;
                    isr = true;
                }
            }
            if (isl && isr) {
                ++ cnt;
            }
        }
    }
    printf("%.2f0000\n", cnt * 1.0 / randnum);
    return 0;
}
