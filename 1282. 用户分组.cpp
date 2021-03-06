/*
有 n 位用户参加活动，他们的 ID 从 0 到 n - 1，每位用户都 恰好 属于某一用户组。给你一个长度为 n 的数组 groupSizes，其中包含每位用户所处的用户组的大小，请你返回用户分组情况（存在的用户组以及每个组中用户的 ID）。

你可以任何顺序返回解决方案，ID 的顺序也不受限制。此外，题目给出的数据保证至少存在一种解决方案。

 

示例 1：

输入：groupSizes = [3,3,3,3,3,1,3]
输出：[[5],[0,1,2],[3,4,6]]
解释： 
其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
       vector<vector<int>> v;
    //    vector<bool> used = (groupSizes.size(), false); 
       bool used[groupSizes.size()];
       for (int i = 0; i < groupSizes.size(); ++i) {
           used[i] = false;
       }

       for (int i = 0; i < groupSizes.size();) {  // loop times, ++every push_back
         vector<int> tempv;
         int now = -1, j = 0;  // loop pointer j
         while (used[j] == true) {
             ++j;
         } 
         now = j;

         int num = 0;
         while (j < groupSizes.size() && num < groupSizes[now]) {
             if (!used[j] && groupSizes[j] == groupSizes[now]) {
                 tempv.push_back(j);
                 ++i;
                 used[j] = true;
                 ++num;
             }
             ++j;
         }
         v.push_back(tempv);
       }
       return v;
    }
};
