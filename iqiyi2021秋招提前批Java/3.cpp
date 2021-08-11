/*** 
 * @Author: czqmike
 * @Date: 2021-08-01 16:31:07
 * @LastEditTime: 2021-08-01 16:59:40
 * @LastEditors: czqmike
 * @Description: 
 湖泊抽水问题
时间限制： 1000MS
内存限制： 65536KB
题目描述：
你的省份有多个湖泊，所有湖泊一开始都是空的。当第 n 个湖泊下雨的时候，如果第 n 个湖泊是空的，那么它就会装满水，否则这个湖泊会发生洪水。你的目标是避免任意一个湖泊发生洪水



输入描述
给你一个整数数组 rains ，其中：

rains[i] > 0 表示第 i 天时，第 rains[i] 个湖泊会下雨。

rains[i] == 0 表示第 i 天没有湖泊会下雨，你可以选择 一个 湖泊并 抽干 这个湖泊的水

输出描述
返回一个数组 ans ，满足：

ans.length == rains.length

如果 rains[i] > 0 ，那么ans[i] == -1 。

如果 rains[i] == 0 ，ans[i] 是你第 i 天选择抽干的湖泊。

如果有多种可行解，请返回它们中的 任意一个 。如果没办法阻止洪水，请返回一个 空的数组


样例输入
[1,2,0,0,2,1]
样例输出
[-1,-1,2,1,-1,-1]

提示
贪心、搜索；

请注意，如果你选择抽干一个装满水的湖泊，它会变成一个空的湖泊。但如果你选择抽干一个空的湖泊，那么将无事发生
 * @FilePath: \undefinedd:\git_repos\Leetcode\iqiyi\3.cpp
 */

#include<bits/stdc++.h>
using namespace std;

void split_str(const string&s, vector<string> &v, const string& c) {
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2) {
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}

	if (pos1 != s.length()) {
		v.push_back(s.substr(pos1));
	}
}

int main() {
	vector<string> tv;
	vector<int> rains, ans;
	string ts;
	cin >> ts;
	split_str(ts, tv, ",");
	tv.front().erase(0, 1);
	tv.back().erase(tv.back().length() - 1);

	for (auto item : tv) {
		rains.push_back(atoi(item.c_str()));
	}

	int most_rain = 0;
	while (rains[++ most_rain]) {}
	vector<int> pools(rains.size(), 0);
	for (int i = 0; i < rains.size(); ++i) {
		for (auto item : pools) {
			if (item < 0) {
				cout << "[]" << endl;
				return 0;
			}
		}

		if (rains[i] > 0) {
			ans.push_back(-1);
			++ pools[i];
			continue;
		} else {
			while (rains[++ most_rain] == 0) {}
			ans.push_back(rains[most_rain]);
			pools[rains[most_rain]] = 0;

		}
	}


	cout << "[";
	for (int i = 0; i < ans.size(); ++i) {
		if (i == ans.size() - 1) {
			cout << ans[i] << ']';
		} else {
			cout << ans[i] << ',';
		}
	}	
	return 0;
}