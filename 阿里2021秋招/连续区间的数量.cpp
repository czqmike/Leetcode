/*** 
 * @Author: czqmike
 * @Date: 2021-07-24 16:58:23
 * @LastEditTime: 2021-07-24 18:24:19
 * @LastEditors: czqmike
 * @Description: 
	长度为 n 的数组，数组中每个元素 a 满足：1<=a<=n
	求连续区间的数量，要求区间中相同元素的数量 >=m
	例如：
	5 2
	1 2 1 2 5
	5
	可以有5种可能：[1,3]，[1,4]，[1,5]，[2,5]，[1,4]
	source: https://www.nowcoder.com/discuss/457491?channel=-2&source_id=discuss_terminal_discuss_sim
 * @FilePath: \Leetcode\阿里2021秋招\连续区间的数量.cpp
 */

// 思路：用map存一个当前数的list集合，从前往后遍历，符合m条件的，则将对应数量添加到res
// 并且维护一个变量pt，用来判断当前数不符合m条件，但之前有符合m条件的数出现过的首个数的下标

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, m = 0;
	int num;
	int pt = -1, ans = 0;
	unordered_map<int, vector<int>> hash; // the map means (number, number indexs vectors)

	cin >> n >> m;
	for (int i = 0; i < n; ++ i) {
		cin >> num;
		hash[num].push_back(i); // map::operator[] could access the map entry, but if the key does not exist, a new entry with that key will be created:
		// Note that std::map::insert only succeeds when no existed keys in the map.

		if (hash[num].size() >= m) {
			int pre_m = hash[num].at(hash[num].size() - m); // get the index of biggest history pt.
			pt = max(pt, pre_m);  // update pt.
		}
		ans += pt + 1; // not += pt, pt itself should be counted.
	}

	cout << ans << endl;
    return 0;
}

