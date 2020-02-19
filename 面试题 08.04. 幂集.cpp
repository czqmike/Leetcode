/*
幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

说明：解集不能包含重复的子集。

示例:

 输入： nums = [1,2,3]
 输出：
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-set-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*  NOTE:
#用八皇后问题的方法产生
[0, 0, 0]
[0, 0, 1]
[0, 1, 0]
[0, 1, 1]
[1, 0, 0]
[1, 0, 1]
[1, 1, 0]
[1, 1, 1]
的序列，然后1和0对应着nums里的数字是否加到集合中.
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> used(nums.size(), 0);
        vector<int> bitemp(nums.size(), 0);

        f(ret, nums, used, bitemp, 0); 

        return ret;
    }

    // 递归函数，bitemp用来存放生成的bit序列，used数组防止重复使用同一level。
    void f(vector<vector<int>>& ret, vector<int>& nums, vector<int>& used,
           vector<int>& bitemp, int level) {
        if (level == nums.size()) {// 递归终点，将bit序列转换成子集。
            vector<int> temp;
            for (int i = 0; i < nums.size(); ++i) {
                if (bitemp[i]) {
                    temp.push_back(nums[i]);
                }
            }
            ret.push_back(temp);
            return ;
        }

        // 将每一level的位置尝试0、1，使用过的位置used标记为1。
        for (int i = 0; i <= 1; ++i) {
            if (!used[level]) {
                bitemp[level] = i;
                used[level] = 1;

                f(ret, nums, used, bitemp, level + 1);

                used[level] = 0;
            }
        }
    }
};