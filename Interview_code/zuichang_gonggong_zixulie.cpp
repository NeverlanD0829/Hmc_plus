/*
    custom_strlen 函数：该函数用于获取输入字符串的长度。通过遍历字符串中的字符，直到遇到字符串结束符 '\0'，计算字符串的长度。
    custom_max 函数：该函数是自定义的比较函数，返回两个整数中的较大值。
    longest_common_subsequence 函数：主要函数，用于找到两个字符串的最长公共子序列。采用动态规划的方法，
        创建一个二维数组 dp，其中 dp[i][j] 表示字符串 str1 的前 i 个字符和字符串 str2 的前 j 个字符的最长公共子序列的长度。
    填充二维数组：从左上角到右下角，如果 str1[i - 1] 等于 str2[j - 1]，则 dp[i][j] 等于 dp[i - 1][j - 1] + 1，
        否则取 dp[i - 1][j] 和 dp[i][j - 1] 中的较大值。
    构造最长公共子序列：通过回溯动态规划表，从右下角开始，根据当前位置的值和相邻位置的值，决定移动的方向，构造最长公共子序列。
*/

#include <iostream>
// 获取字符串长度
int custom_strlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}
// 自定义比较函数，返回较大值
int custom_max(int a, int b) {
    return (a > b) ? a : b;
}
// 找到两个字符串的最长公共子序列
void longest_common_subsequence(const char* str1, const char* str2, char* result) {
    int m = custom_strlen(str1);
    int n = custom_strlen(str2);
    // 创建一个二维数组来存储子问题的解
    int dp[100][100] = {0};
    // 填充二维数组，从左上角到右下角
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = custom_max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 构造最长公共子序列
    int i = m, j = n;
    int index = dp[m][n];
    result[index] = '\0';
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result[index - 1] = str1[i - 1];
            --i;
            --j;
            --index;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
}
int main() {
    // 示例
    const char* str1 = "ABCD";
    const char* str2 = "ACDF";
    char result[100];
    longest_common_subsequence(str1, str2, result);
    std::cout << "最长公共子序列: " << result << std::endl;
    return 0;
}
