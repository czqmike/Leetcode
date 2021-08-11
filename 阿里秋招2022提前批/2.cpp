/*** 
 * @Author: czqmike
 * @Date: 2021-08-02 19:37:54
 * @LastEditTime: 2021-08-02 20:02:52
 * @LastEditors: czqmike
 * @Description: 
 * @FilePath: \undefinedd:\git_repos\Leetcode\阿里秋招2022提前批\2.cpp
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> v;
void build_tree(int b, int e) {
	if (b >= e) {
		return;
	}
	swap(v[e], v[(b + e) / 2]);
	build_tree(b, (b + e) / 2 - 1);
	build_tree((b + e) / 2 + 1, e);
}

int main() {
	int t, n;
	cin >> t;
	for (int times = 0; times < t; ++ times) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());

		build_tree(0, v.size() - 1);

		for (int i = 0; i < n; ++i) {
			if (i != 0) cout << ' ';
			cout << v[i];
		}
		cout << endl;
		v.clear();
	}
	return 0;	
}