/*** 
 * @Author: czqmike
 * @Date: 2021-05-09 12:00:12
 * @LastEditTime: 2021-05-09 12:00:15
 * @LastEditors: czqmike
 * @Description: 
 * 最优字符串
时间限制： 3000MS
内存限制： 589824KB
题目描述：
小美和小团各有一个由小写英文字母组成的字符串，分别为s和t。因为两人是好朋友，他们不想让彼此手中的字符串不相同，所以要在s，t中分别删除若干字符(可以不删除，也可全部删除)，使得两串相等，且删除后两串的价值和最大。一个字符串的价值为这个字符串每个字符对应价值的和。



输入描述
第一行26个整数，分别代表’a’，’b’ ...... ’z’字符对应的价值。

第二行一个字符串s。

第三行一个字符串t。

字符价值的绝对值≤10^9，1≤s，t的长度≤1000。

输出描述
输出一行一个整数代表答案。


样例输入
7 -5 4 6 2 5 8 -4 -8 4 10 -1 3 3 -5 10 7 0 -5 -4 -9 3 8 0 8 -3 
nygfh
lixawy
样例输出
16
 * @FilePath: \Leetcode\美团2021\5.cpp
 */
