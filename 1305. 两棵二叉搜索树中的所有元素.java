/*
给你 root1 和 root2 这两棵二叉搜索树。

请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.

示例 1：

输入：root1 = [2,1,4], root2 = [1,0,3]
输出：[0,1,1,2,3,4]
示例 2：

输入：root1 = [0,-10,10], root2 = [5,1,7,0,2]
输出：[-10,0,0,1,2,5,7,10]
示例 3：

输入：root1 = [], root2 = [5,1,7,0,2]
输出：[0,1,2,5,7]
示例 4：

输入：root1 = [0,-10,10], root2 = []
输出：[-10,0,10]
示例 5：

输入：root1 = [1,null,8], root2 = [8,1]
输出：[1,1,8,8]
 

提示：

每棵树最多有 5000 个节点。
每个节点的值在 [-10^5, 10^5] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 Definition for a binary tree node.
 public class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
     TreeNode(int x) { val = x; }
  }
 */

import java.util.*;
class Solution {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        LinkedList<Integer> ret = new LinkedList<Integer>();
        LinkedList<Integer> L1 = new LinkedList<>();
        LinkedList<Integer> L2 = new LinkedList<>();
        firstOrderVisit(root1, L1); 
        firstOrderVisit(root2, L2);

        ret = merge(L1, L2); 

        return ret;
    }

    private void firstOrderVisit(TreeNode root, LinkedList<Integer> L) {
        if (root != null) {
            firstOrderVisit(root.left, L);
            L.add(root.val);
            firstOrderVisit(root.right, L); 
        }
    }

    private LinkedList<Integer> merge(LinkedList<Integer> L1, LinkedList<Integer> L2) {
        LinkedList<Integer> L = new LinkedList<>();
        while (!L1.isEmpty() && !L2.isEmpty()) {
            Integer t1 = L1.get(0);
            Integer t2 = L2.get(0);

            if (t1 < t2) {
                L.add(t1);
                L1.remove(0);
            } else {
                L.add(t2);
                L2.remove(0);
            }
        }

        if (L1.isEmpty()) {
            L.addAll(L2);
        } else {
            L.addAll(L1);
        }
        return L;
    }

}