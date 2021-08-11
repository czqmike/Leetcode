/*** 
 * @Author: czqmike
 * @Date: 2021-08-02 19:12:10
 * @LastEditTime: 2021-08-02 19:46:29
 * @LastEditors: czqmike
 * @Description: 
 * @FilePath: \undefinedd:\git_repos\Leetcode\阿里秋招2022提前批\1.cpp
 */
// 2
// 3 3
// 0 1 5
// 1 1 6
// 2 3 4
// 2 2
// 0 1
// 1 1
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m;
	vector<vector<int>> v;
	cin >> t;
	for (int times = 0; times < t; ++ times) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			vector<int> temp;
			for (int j = 0; j < m; ++j) {
				int tp;
				cin >> tp;
				temp.push_back(tp);
			}
			v.push_back(temp);
		}
		int p1 = 0, p2 = 0;
		int time = 0;
		bool could = false;
		while (p1 < n && p2 < m) {
			if (time > v[p1][p2]) {
				cout << "NO" << endl;
				break;
			}
			if (v[p1][p2 + 1] <= v[p1 + 1][p2]) { // down
				p2 ++;	
			} else {
				p1 ++;
			}
			if (p1 >= n || p2 >= m) {
				could = true;
				break;
			}
			time ++;
		}
		if (could) {
			cout << "YES" << endl;
			could = false;
		}

		for (auto item : v) {
			item.clear();
		}
		v.clear();
	}

	return 0;	
}