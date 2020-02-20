/*
括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。

说明：解集不能包含重复的子集。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bracket-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        string temp("");
        f(temp, 0, 0, n);
        return ret;
    }

    void f(string temp, int left, int right, int n) {
        // 递归终点
        if (left + right == n * 2) {
            ret.push_back(temp);
            return ;
        }

        if (left < n) { // 若是左括号不足则一直添加左括号。 
            f(temp + '(', left + 1, right, n);
        }
        if (right < left) { // 若是有括号小于左括号则配对右括号。
            f(temp + ')', left, right + 1, n);
        }
    }
};