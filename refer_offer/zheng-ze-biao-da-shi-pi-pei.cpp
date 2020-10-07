//请实现一个函数用来匹配包含'. '和'*'的正则表达式。
//模式中的字符'.'表示任意一个字符，
//而'*'表示它前面的字符可以出现任意次（含0次）。
//在本题中，匹配是指字符串的所有字符匹配整个模式。
//例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
//

// f[i][j] 表示 s 的前 i 个字符与 p 的前 j 个字符能否进行匹配
// 当 p 的第 j 个字符是一个小写字母，那么我们必须在 s 中匹配一个相同的小写字母 
// f[i][j] = f[i-1][j-1] when s[i] = p[j]
//         = false       when s[i] != p[j]
// 如果 p 的第 j 个字符是 *，那么就表示我们可以对 p 的第 j-1 个字符匹配任意自然数次。在匹配 0 次的情况下，我们有 
// f[i][j]=f[i][j-2] 这里说明去除了一个字符 + 星号的组合，没有匹配任何 s 中的字符
// 字母 + 星号的组合在匹配的过程中，本质上只会有两种情况： 
// 1. 匹配 s 末尾的一个字符，将该字符扔掉，而该组合还可以继续进行匹配；
// 2. 不匹配字符，将该组合扔掉，不再进行匹配。 
// f[i][j] = f[i-1][j] or f[i][j-2] when s[i] = p[j-1] 
//         = f[i][j-2]              when s[i] != p[j-1] 
// 一种是匹配0个，那么只需要跳过p中的这两个字符，继续与s中的字符进行比较即可，
// 如果是匹配多个，那么将s中的游标往后移动一个，继续进行判断，这两个条件只要其中一个能满足即可
	

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};







