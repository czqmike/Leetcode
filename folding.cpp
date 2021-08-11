/*** 
 * @Author: czqmike
 * @Date: 2021-05-08 13:44:51
 * @LastEditTime: 2021-05-08 13:44:51
 * @LastEditors: czqmike
 * @Description: 
 * @FilePath: \Leetcode\folding.cpp
 */
/*** 
 * @Author: czqmike
 * @Date: 2021-04-30 17:56:11
 * @LastEditTime: 2021-05-08 13:44:32
 * @LastEditors: czqmike
 * @Description: 
 * 【题目】 请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折1次，
 * 压出折痕后展开。此时 折痕是凹下去的，即折痕突起的方向指向纸条的背面。
 * 如果从纸条的下边向上方连续对折2 次，压出折痕后展开，此时有三条折痕，
 * 从上到下依次是下折痕、下折痕和上折痕。
 * 给定一 个输入参数N，代表纸条都从下边向上方连续对折N次，
 * 请从上到下打印所有折痕的方向。 
 * 例如：N=1时，打印： down N=2时，打印： down down up
 * @FilePath: \Leetcode\test.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void folding(int n, int branch) { // branch = 0 means left, 1 means right
    if (n == 0) {
        return ;
    }
    folding(n - 1, 0);
    cout << branch << ' ';
    folding(n - 1, 1);
}

int main() {
    folding(5, 0);
    cout << endl;
    return 0;
}
