/*** 
 * @Author: czqmike
 * @Date: 2021-04-30 17:56:11
 * @LastEditTime: 2021-05-08 15:59:53
 * @LastEditors: czqmike
 * @Description: 
 * @FilePath: \Leetcode\test.cpp
 */

#include <iostream>
#include <vector>
using namespace std;
// 第k大的元素 O(N)

int partition(vector<int> & v, int left, int right) {
    int p = v[left];
    int i = left, j = right - 1;
    if (i >= j) {
        return i;
    }
    while (i < j) {
        while (i < j && v[j] >= p) {
            -- j;
        }
        v[i] = v[j];
        while (i < j && v[i] <= p) {
            ++ i;
        }
        v[j] = v[i];
    }
    v[j] = p;

    // for (auto item : v) {
    //     cout << item << ' ';
    // }
    // cout << endl;

    return j;
}

int topk(vector<int>& v, int k) {
    int pat = 0;
    pat = partition(v, 0, v.size());
    for (int i = 0; i < v.size() && pat != k; ++i) {
        if (pat == k) {
            break;
        }
        if (k < pat) {
            pat = partition(v, 0, pat);
        } else {
            pat = partition(v, pat + 1, v.size());
        }
        // cout << "pat = " << pat << endl;
    }
    return v[pat];
}

int main() {
    vector<int> v = {4, 5, 2, 1, 3, 8, 6, 7, 9};
    int k = 3;
    cout << topk(v, k - 1);
    return 0;
}