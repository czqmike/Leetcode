/*** 
 * @Author: czqmike
 * @Date: 2021-04-18 20:25:54
 * @LastEditTime: 2021-04-18 20:58:32
 * @LastEditors: czqmike
 * @Description: 
 * Input:
 *  abcd
    adcb
    4
    1 1
    2 2
    2 3
    3 3
   Output:
    7
    6
    5
    2
 * Result:
 *  9.19%
 * @FilePath: /腾讯2020暑期实习/2_最大字符数.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main() {
    string s = "";
    string t = "";
    cin >> s >> t;

    int q = 0;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int idx1, idx2;
        cin >> idx1 >> idx2;
        string s1 = s.substr(idx1 - 1);
        string s2 = t.substr(idx2 - 1);

        bool found = false;
        for (int j = 0; j <= s1.length() && !found; ++j) {
            for (int k = 0; k < s2.length() && !found; ++k) {
                string sj = s1.substr(j);
                string sk = s2.substr(k);
                // cout << sj << endl << sk << endl;
                if (sj.length() == 0 || sj[0] < sk[0]) {
                    cout << sj.length() + sk.length();
                    if (i != q - 1) {
                        cout << endl;
                    }
                    found = true;
                }
            }
        }
    }
    return 0;
}
