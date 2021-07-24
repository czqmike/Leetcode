/*** 
 * @Author: czqmike
 * @Date: 2021-05-09 10:02:51
 * @LastEditTime: 2021-05-09 10:50:17
 * @LastEditors: czqmike
 * @Description: 
 *  时间限制： 1000MS
    内存限制： 524288KB
    题目描述：
    小美在假期练习吉他，但由于她是一个新手，所以不可能连续练习时，还能保持最佳状态。小美拥有一个当前状态值x，每小时，她可以选择练习或者休息。如果练习，小美可以获得x点收益，然后状态值下降a（若x<a，则只会下降x点），如果休息，小美的状态值会上升b。

    给出小美的初始状态值x和总时间n，求最大收益。



    输入描述
    第一行一个正整数t，代表数据组数。

    接下来t行，四个正整数x，a，b，n。

    测试数据保证1<=t<=10^4，1<=x,a,b,n<=10^6。

    输出描述
    t行，每行一个正整数，表示答案。保证答案能使用64位有符号整数储存。


    样例输入
    1
    10 5 5 3
    样例输出
    25

    提示
    第一小时休息，收益为0，总收益为0，状态值为15

    第二小时练习，收益为15，总收益为15，状态值为10

    第三小时练习，收益为10，总收益为25，状态值为5
 * @FilePath: \Leetcode\美团2021\3_小美练吉他.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, x, a, b, n;
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++ i) {
        scanf("%d %d %d %d", &x, &a, &b, &n);
        int state = x, time = n, gain = 0;
        int t1 =  a * n / (a + b);
        // cout << "t1 = " << t1 << endl;
        for ( int j = 0 ; j < t1; ++ j) {
            state += b;
        } 
        int t2 = n - t1;
        // cout << "t2 = " << t2 << endl;
        
        for ( int j = 0; j < t2; ++j) {
            gain += state;
            state -= min(a, state);
        }

        printf("%d\n", gain);
    }

    return 0;
}