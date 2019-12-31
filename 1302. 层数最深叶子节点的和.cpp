/*
给你一棵二叉树，请你返回层数最深的叶子节点的和。

示例：

输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
输出：15
 
提示：

树中节点数目在 1 到 10^4 之间。
每个节点的值在 1 到 100 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/deepest-leaves-sum
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
    // Object node to sum: have no lchild or rchild && depth == height of tree
public:
    int H = 0, SUM = 0;
    int getHeight(TreeNode* root) {
        if (root == NULL) 
            return 0;
        if (root != NULL && root->left == NULL && root->right == NULL)
            return 1;
        int H1 = getHeight(root->left) + 1;
        int H2 = getHeight(root->right) + 1;
        return H1 > H2 ? H1 : H2;
    }

    void dfs(TreeNode* root, int nowh) {
        if (root == NULL) return;
        if (root != NULL && root->left == NULL && root->right == NULL && nowh == H) {
            SUM += root->val;
        }
        dfs(root->left, nowh + 1);
        dfs(root->right, nowh + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        H = 0, SUM = 0;
        H = getHeight(root);
        dfs(root, 1);
        return SUM;
    }

};
