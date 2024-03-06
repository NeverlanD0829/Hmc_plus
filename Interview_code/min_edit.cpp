/*
    采用动态规划的思想，通过填充一个二维数组，计算字符串间的最小编辑距离。这样的算法在处理字符串相似性、拼写纠错等任务时非常有用。
    初始化： 创建一个二维数组 dp 用于存储编辑距离。dp[i][j] 表示将字符串的前 i 个字符转换为另一个字符串的前 j 个字符所需的最小操作数。
    边界条件初始化： 将第一行和第一列初始化为从空字符串到相应位置的距离，即 dp[i][0] = i 和 dp[0][j] = j。
    动态规划计算： 使用嵌套循环遍历两个字符串的每个字符，计算编辑距离。如果当前字符相等，则 dp[i][j] = dp[i-1][j-1]，
    否则，dp[i][j] 等于其左、上、左上三个相邻位置中的最小值加1，表示插入、删除或替换操作。
    返回结果： 最终的编辑距离存储在右下角的 dp[m][n]，其中 m 和 n 分别是两个字符串的长度。
*/

#include <iostream>
#include <vector>
using namespace std;

int minimum(int a, int b, int c) {
    return min(a, min(b, c));
}

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    // 创建一个二维数组来存储编辑距离
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 初始化边界条件
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    // 动态规划计算编辑距离
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + minimum(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }
    // 返回最终的编辑距离
    return dp[m][n];
}

int main() {
    string word1 = "horse";
    string word2 = "ros";
    int result = minDistance(word1, word2);
    cout << "Minimum operations required: " << result << endl;
    return 0;
}
