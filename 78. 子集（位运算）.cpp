/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
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
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*
[1, 2, 3]的子集可以表示成
[0 0 0]
[0 0 1]
[0 1 0]
[0 1 1]
[1 0 0]
[1 0 1]
[1 1 0] 
[1 1 1]
其中1代表pick那一位。
故只需要产生0~7，然后用位运算分离每一位即可得到结果。
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int end = 1 << nums.size(); // end = 2 ^ n

        for (int i = 0; i < end; ++i) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); ++j) { // 分离每一位
                if (1<<j & i) { // 制作掩码，提取第j位
                    temp.push_back(nums[j]);
                }
            } 
            ret.push_back(temp);
        }

        return ret;
    }
};