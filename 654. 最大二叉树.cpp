/*
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

 

示例 ：

输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

public:
    int getMax(vector<int>& nums, int left, int right) {
        int max = left;
        for (int i = left; i < right; ++i) {
            max = nums[max] < nums[i] ? i : max;
        }
        return max;
    }

    TreeNode* createTree(vector<int>&nums, int left, int right) {  // left bound, right bound
        if (right - left == 0) return NULL;

        int max = getMax(nums, left, right);
        TreeNode* root = new TreeNode(nums[max]); 
        root->left = createTree(nums, left, max);
        root->right = createTree(nums, max + 1, right);
        
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return createTree(nums, 0, nums.size());
    }
};
