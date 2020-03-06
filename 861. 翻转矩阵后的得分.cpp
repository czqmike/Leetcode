/*
有一个二维矩阵 A 其中每个元素的值为 0 或 1 。

移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。

在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

返回尽可能高的分数。

示例：

输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
输出：39
解释：
转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 
提示：

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] 是 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/score-after-flipping-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
对于二进制数来说，我们只要保证最高位是1，就可以保证这个数是最大的，因为移动操作会使得它取反，因此我们进行行变化的时候只需要考虑首位即可。
对于后面的列处理，由于只影响的是该列，所以若要取得最大值，只需要保证该列1的个数 不少于0的个数即可。
但是我们在进行列判断的时候，可以简化移动操作，因为这个过程我们会进行记录1的个数的计算，所以我们可以直接由1个个数去计算最后的总和即可。

作者：er-zong
链接：https://leetcode-cn.com/problems/score-after-flipping-matrix/solution/c-4ms-by-er-zong/
*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size(), col = A[0].size();
        int ret = 0;
        // First column
        for (int i = 0; i < row; ++i) {
            if (A[i][0] == 0) {
                for (int j = 0; j < col; ++j) {
                    A[i][j] ^= 1;
                } 
            }
        }
        ret += row * pow(2, col - 1);

        // Others
        for (int j = 1; j < col; ++j) {
            int cnt = 0; // Record number of "1"
            for (int i = 0; i < row; ++i) {
                if (A[i][j]) {
                    ++ cnt;
                }
            }
            cnt = max<int> (cnt, row - cnt); 
            ret += cnt * pow(2, col - j - 1);
        } 

        return ret;
    }
};