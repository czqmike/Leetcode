/*** 
 * @Author: czqmike
 * @Date: 2021-04-18 20:04:13
 * @LastEditTime: 2021-04-18 20:57:45
 * @LastEditors: czqmike
 * @Description: 
 * Input: 
 *  4 1
    2 4 5 6
    1
   Output:
   4 5
   Result:
   18.18%
 * @FilePath: /腾讯2020暑期实习/1_摘果子.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 0, m = 0;
    // cin >> n >> m;
    scanf("%d %d", &n, &m);
    
    vector<int> w;
    for (int i = 0; i < n; ++i) {
        int temp;
        // cin >> temp;
        scanf("%d", &temp);
        w.push_back(temp);
    }

    sort(w.begin(), w.end());

    getchar();
    int range = w.back() - w.front();
    for (int i = 0; i < m; ++i) {
        int q = 0;
        // cin >> q;
        scanf("%d", &q);
        if (q > range) {
            // cout << -1 << ' ' << -1;
            printf("-1 -1");
            if (i != m - 1) {
                // cout << endl;
                printf("\n");
            }
            break;
        }       

        bool found = false;
        for (int j = 0; j < n && !found; ++j) {
            for (int k = j + 1; k < n && !found; ++k) {
                if (w[k] - w[j] == q) {
                    // cout << w[j] << ' ' << w[k];
                    printf("%d %d", w[j], w[k]);
                    found = true;
                }
                if (i != m - 1) {
                    // cout << endl;
                    printf("\n");
                }
            }
        }

    }
    return 0;
}
