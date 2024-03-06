#include <iostream>
#include <vector>

// 定义矩阵乘法函数
std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int m = A.size();    // A 的行数
    int n = A[0].size(); // A 的列数，同时也是 B 的行数
    int p = B[0].size(); // B 的列数
    // 初始化结果矩阵 C
    std::vector<std::vector<int>> C(m, std::vector<int>(p, 0));
    // 执行矩阵乘法
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    // 定义两个矩阵 A 和 B
    std::vector<std::vector<int>> A = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> B = {{5, 6}, {7, 8}};

    // 执行矩阵乘法
    std::vector<std::vector<int>> result = matrixMultiply(A, B);

    // 输出结果矩阵
    std::cout << "Result Matrix C:" << std::endl;
    for (const auto& row : result) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
