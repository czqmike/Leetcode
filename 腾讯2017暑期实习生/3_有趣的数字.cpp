/*** 
 * @Author: czqmike
 * @Date: 2021-04-16 11:21:59
 * @LastEditTime: 2021-04-18 19:55:22
 * @LastEditors: czqmike
 * @Description: 
 * 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，相差最小的有多少对呢？相差最大呢？


    输入描述:

    输入包含多组测试数据。

    对于每组测试数据：

    N - 本组测试数据有n个数

    a1,a2...an - 需要计算的数据

    保证:

    1<=N<=100000,0<=ai<=INT_MAX.
    


    输出描述:

    对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。


    输入例子1:
    6
    45 12 45 32 5 6

    输出例子1:
    1 2
 * @FilePath: /undefined/mnt/d/git_repos/Leetcode/腾讯2017暑期实习生/3_有趣的数字.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
   int N = 0;
   cin >> N;
   vector<int> v;
   int temp;
   for (int i = 0; i < N; ++i) {
      cin >> temp;
      v.push_back(temp);
   }

   map<int, int> m;
   for (int item : v) {
      int cnt = m.count(item);
      if (cnt == 0) {
         m.insert(pair<int, int>(item, 1));
      } else {
         m[item] = cnt + 1;
      }
   }

   for (auto item : m) {
      cout << item.first << ": " << item.second << endl;
   }
   // sort(v.begin(), v.end());

   // // Find max range.
   // int max_range = v.back() - v.front();
   // int max_cnt_1 = 0;
   // for (int i = 0; i < N; ++i) {
   //    if (v.back() - v[i] == max_range) {
   //       ++ max_cnt_1;
   //    } else {
   //       break;
   //    }
   // }
   // int max_cnt_2 = 0;
   // for (int i = N - 1; i >= 0; --i) {
   //    if (v[i] - v.front() == max_range) {
   //       ++ max_cnt_2;
   //    } else {
   //       break;
   //    }
   // }
   // if (max_cnt_1 == 2 && max_cnt_1 == 1) {
   //    -- max_cnt_2;
   // }

   // // Find min range.
   // int min_range = INT32_MAX;
   // int min_cnt = 0;
   // for (int i = 0; i < N - 2; ++i) {
   //    if (v[i + 1] - v[i] < min_range) {
   //       min_range = v[i + 1] - v[i];
   //    }
   // }
   // for (int i = 0; i < N - 2; ++i) {
   //    if (v[i + 1] - v[i] == min_range) {
   //       ++ min_cnt;
   //    }
   // }
   // cout << min_cnt << ' ' << max_cnt_1 + max_cnt_2 << endl;
   return 0;
}