/*** 
 * @Author: czqmike
 * @Date: 2021-04-30 17:09:18
 * @LastEditTime: 2021-08-11 16:33:01
 * @LastEditors: czqmike
 * @Description: 
 * @FilePath: \Leetcode\quick_sort.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

// int partition(vector<int>& v, int begin, int end) {
//     int k = v[begin];
//     int i = begin, j = end - 1;
//     if (i >= j) {
//         return i;
//     }
//     while (i < j) {
//         while (i < j && v[j] >= k) {
//             -- j;
//         }
//         v[i] = v[j];
//         while (i < j && v[i] <= k) {
//             ++ i;
//         }
//         v[j] = v[i];
//     }
//     v[j] = k;

//     return j; 
// }

// void quick_sort(vector<int>& v, int begin, int end) { // v in [begin, end)
//     int p = partition(v, begin, end);

//     if (p < 0 || p >= end) { // WARNING: v[end] is illegal, exclude it!
//         return ;
//     }

//     quick_sort(v, begin, p);
//     quick_sort(v, p + 1, end);
// }

// int partition(vector<int>& v, int begin, int end) {
//     int saved = v[begin];
//     int l = begin, r = end - 1;
//     while (l < r) {
//         while (r >= saved && l < r) {
//             -- r;
//         }
//         v[l] = v[r];
//         while (l <= saved && l < r) {
//             ++ l;
//         }
//         v[r] = v[l];
//     }
//     v[l] = saved;
//     return l;
// }
int partition(vector<int>& v, int begin, int end) {
    int saved = v[begin], pk = begin;
    for (int i = begin + 1; i < end; ++i) {
        if ( (v[i] > saved && i < pk) || (v[i] < saved && i > pk) ) { 
            // divide to 2 parts, if in_left && bigger_than_k or in_right && smaller_than_k, then swap()
            swap(v[i], v[pk]);
            pk = i;
        }
    }
    return pk;
}

void quick_sort(vector<int>& v, int begin, int end) { // [begin, end)
    if (begin >= end) {
        return ;
    }
    int p = partition(v, begin, end);

    quick_sort(v, begin, p);
    quick_sort(v, p + 1, end);
}

int main() {
    vector<int> v = {3, 1, 2, 5, 4, 7, 6}; 
    quick_sort(v, 0, v.size());

    for (int item : v) {
        cout << item << ' ';
    }
    cout << '\n';
    return 0;
}