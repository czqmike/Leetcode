/*
给定一幅由N × N矩阵表示的图像，其中每个像素的大小为4字节，编写一种方法，将图像旋转90度。

不占用额外内存空间能否做到？

 

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-matrix-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
1 2 3
4 5 6
7 8 9
沿主对角线对折==>

1 4 7
2 5 8
3 6 9
每一行左右互换==>

7 4 1
8 5 2
9 6 3
OK
*/

class Solution {
public:
    template<typename T>
    void mySwap(T& a, T& b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 沿主对角线对折
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mySwap(matrix[i][j], matrix[j][i]);
            }
        } 

        // 每一行左右互换
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                mySwap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};