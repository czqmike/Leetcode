/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v;
        for (int i = 0; i < n; ++i) {
            vector<int> temp(n, 0);
            v.push_back(temp);
        }

        int l = 0, r = n - 1, t = 0, b = n - 1; // left, right, top, bottom

        for (int num = 1; num <= n * n; ) {
            for (int i = l; i <= r; ++i) { // left to right
                v[t][i] = num ++;
            }
            ++ t;

            for (int i = t; i <= b; ++i) { // top to bottom
                v[i][r] = num ++;
            }
            -- r;

            for (int i = r; i >= l; --i) { // right to left
                v[b][i] = num ++;
            }
            -- b;

            for (int i = b; i >= t; --i) { // bottom to top
                v[i][l] = num ++;
            }
            ++ l;
        }
        return v;
    }

};