/*** 
 * @Author: czqmike
 * @Date: 2021-05-09 10:02:51
 * @LastEditTime: 2021-05-09 12:20:50
 * @LastEditors: czqmike
 * @Description: 
 *  网格
    时间限制： 3000MS
    内存限制： 1048576KB
    题目描述：
    小美和小团在有n行m列网格的图玩游戏.他们规定,有k个五元组(x,y,u,v,w),由x行y列网格向u行,v列网格移动时花费为w,其他移动方式一律不合法.同时为了降低游戏难度,保证x≤u,y≤v.现在请你求从1行1列到n行m列网格所需要花费总和最少是多少. 



    输入描述
    第一行三个数n,m,k，表示行数,列数以及五元组个数。

    接下来k行，每行五个数xi,yi,ui,vi,wi,含义如上文所述,保证给出的格点有效且合法。

    1≤n,m≤500，0≤wi≤100，0≤k≤50000

    输出描述
    输出一个整数，表示答案,若无法从1行1列到达n行m列, 输出整数-1。


    样例输入
    5 4 3
    1 1 2 2 1
    1 1 5 4 4
    2 2 5 4 1
    样例输出
    2
 * @FilePath: \Leetcode\美团2021\1.cpp
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<vector<int>> v;
    for (int i = 0; i < k; ++i) {
       vector<int> tv;
       int x, y, u, v1, w;
       scanf("%d %d %d %d %d", &x, &y, &u, &v1, &w); 
       tv.push_back(x);
       tv.push_back(y);
       tv.push_back(u);
       tv.push_back(v1);
       tv.push_back(w);

       v.push_back(tv);
    }
    
    sort(v.begin(), v.end());

    vector<int> costs;
    vector<int> starts;
    for (int i = 0; i < k; ++i) {
        if (v[i][0] == 1 && v[i][1] == 1) {
           bool rep = false;
           for (int j = 0; j < starts.size(); ++j) {
               if (v[j][2] == v[i][2] && v[j][3] == v[i][3]) {
                   rep = true;
                   break;
               }
           } 
           if (rep) {
               continue;
           }
           starts.push_back(i);
        }
    }
    cout << "starts: ";
    for (auto item : starts) {
        cout << item << ' ';
    }
    cout << endl;

    int cost;
    for (auto start : starts) {
        int px = 1, py = 1, cost = 0;
        for (int i = start; i < k && (px != m && py != n); ++i) {
            cout << "px = " << px << " py = " << py << endl;
            if (px == v[i][0] && py == v[i][1]) {
                px = v[i][2];
                py = v[i][3];
                cost += v[i][4];
                ++ i;
            }
            while (px != v[i][0] && py != v[i][1] && i < k) {
                ++ i;
            }
            -- i;
        }
        costs.push_back(cost);
    }
    cout << "cost: ";
    for (auto item : costs) {
        cout << item << ' ';
    }
    cout << endl;

    if (costs.empty()) {
        cout << -1;
    } else {
        int minc = INT32_MAX;
        for (int item : costs) {
            minc = min(minc, item);
        }
        cout << minc;
    }
    return 0;
}