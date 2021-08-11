/*** 
 * @Author: czqmike
 * @Date: 2021-08-01 17:02:46
 * @LastEditTime: 2021-08-02 19:11:30
 * @LastEditors: czqmike
 * @Description: 
 * @FilePath: \undefinedd:\git_repos\Leetcode\iqiyi2021秋招提前批Java\split_str.cpp
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> split_str(const string& s, const string& delimiter) {
	int pos1 = 0, pos2 = s.find(delimiter);
	vector<string> v;	

	while (pos2 != string::npos) {
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + delimiter.size();
		pos2 = s.find(delimiter, pos1);
	}
	if (pos1 != s.length()) {
		v.push_back(s.substr(pos1));
	}
	return v;
}

int main() {
	string s = "1, 2, 3, 4, 5, 6, 7";
	vector<string> v = split_str(s, ", ");
	for (auto item : v) {
		cout << item << " ";
	}
	return 0;
}