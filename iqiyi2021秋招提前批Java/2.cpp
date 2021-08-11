/*** 
 * @Author: czqmike
 * @Date: 2021-08-01 15:24:49
 * @LastEditTime: 2021-08-01 16:38:17
 * @LastEditors: czqmike
 * @Description: 
 求滑动窗口平均数最大增幅
时间限制： 1000MS
内存限制： 65536KB
题目描述：
一个自然数数组arr，有大小为k的数据滑动窗口从数组头部往数组尾部滑动，窗口每次滑动一位，窗口最后一位到达数组末尾时滑动结束。

窗口每次滑动后，窗口内k个整数的平均值相比滑动前会有一个变化幅度百分比p。



输入描述
输入数组和窗口大小k，数组和窗口大小用英文冒号分隔，数组内自然数用英文逗号分隔

输出描述
滑动开始到结束后出现的最大p值


样例输入
5,6,8,26,50,48,52,55,10,1,2,1,20,5:3
样例输出
475.00%

提示
过程如下：

滑动窗口位置                                                  窗口平均值        平均值增幅

----------------------------------       -------         --------

[5  6  8] 26  50  48  52  55  10  1  2  1  20  5          6.33 

 5 [6  8  26] 50  48  52  55  10  1  2  1  20  5          13.33                   110.53%

 5  6 [8  26  50] 48  52  55  10  1  2  1  20  5          28.00                   110.00%

 5  6  8 [26  50  48] 52  55  10  1  2  1  20  5          41.33                   47.62%

 5  6  8  26 [50  48  52] 55  10  1  2  1  20  5          50.00                   20.97%

 5  6  8  26  50 [48  52  55] 10  1  2  1  20  5          51.67                   3.33%

 5  6  8  26  50  48 [52  55  10] 1  2  1  20  5          39.00                   -24.52%

 5  6  8  26  50  48  52 [55  10  1] 2  1  20  5          22.00                   -43.59%

 5  6  8  26  50  48  52  55 [10  1  2] 1  20  5          4.33                     -80.30%

 5  6  8  26  50  48  52  55  10 [1  2  1] 20  5          1.33                     -69.23%

 5  6  8  26  50  48  52  55  10  1 [2  1  20] 5          7.67                     475.00%

 5  6  8  26  50  48  52  55  10  1  2 [1  20  5]        8.67                     13.04%
 * @FilePath: \undefinedd:\git_repos\Leetcode\iqiyi\2.cpp
 */

// 5,6,8,26,50,48,52,55,10,1,2,1,20,5:3

#include <bits/stdc++.h>
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
	string ts;
	cin >> ts;
	vector<string> v;
	split_str(ts, v, ",");
	vector<string> vv;
	split_str(v.back(), vv, ":");	
	v.pop_back();
	v.push_back(vv[0]);

	vector<int> nums;
	for (auto item : v) {
		nums.push_back(atoi(item.c_str()));
	}
	int k = atoi(vv[1].c_str());

	double pre = 0, now = 0;
	double max_incre = 0.0;

	for (int i = 0; i < k; ++i) {
		pre += nums[i];
	}
	pre /= k;
	now = pre;
	for (int i = 1; i < nums.size() - k + 1; ++i) {
		now *= k;
		now -= nums[i - 1];
		now += nums[i + k - 1];
		now /= k;
		double incre = (now - pre) / pre;
		pre = now;
		max_incre = incre > max_incre ? incre : max_incre;
		cout << "incre: " << incre <<endl;
	}

	printf("%.2f%c", max_incre * 100, '%');
	return 0;
}



























