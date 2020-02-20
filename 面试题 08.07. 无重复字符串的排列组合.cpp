//又是全排列。。你有多喜欢这个啊
/*
无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。

示例1:

 输入：S = "qwe"
 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
示例2:

 输入：S = "ab"
 输出：["ab", "ba"]
提示:

字符都是英文字母。
字符串长度在[1, 9]之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-i-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<string> permutation(string S) {
        string temp(S.size(), '*');
        vector<string> ret;
        vector<bool> used(S.size(), false);

        f(ret, used, S, temp, 0);

        return ret;
    }

    void f(vector<string>& ret, vector<bool>& used, string& S, string& temp, int level) {
        if (level == S.size()) { // 递归终点
            ret.push_back(temp);
        } else {

            for (int i = 0; i < S.size(); ++i) { // 对全部S中的字符进行选择
                if (!used[i]) {
                    used[i] = true;
                    temp[level] = S[i]; // 这次循环选择的是第level个

                    f(ret, used, S, temp, level + 1);

                    used[i] = false;
                }
            }
        }    
    }
};