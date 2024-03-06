/*
    swap 函数： 提供了一个用于交换两个整数的辅助函数，用于在递归中交换数组元素的位置。
    generate_permutations 函数： 这是主要的全排列生成函数。它采用递归的方式，从数组的第一个元素开始，不断地交换当前元素
        与后面的元素，然后递归生成剩余部分的排列。通过递归的方式，每次都在数组的某一位置确定一个元素，直到达到数组末尾，
        然后打印当前的排列。
*/
#include <iostream>
#include <vector>
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void generate_permutations(std::vector<int>& elements, int start, int end) {
    if (start == end) {
        // 当达到数组末尾时，打印当前排列
        for (int element : elements) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    } else {
        // 递归生成排列
        for (int i = start; i <= end; ++i) {
            swap(elements[start], elements[i]);
            generate_permutations(elements, start + 1, end);
            swap(elements[start], elements[i]); // 恢复原始顺序，以便进行下一次交换
        }
    }
}

int main() {
    // 生成 {1, 2, 3} 的全排列
    std::vector<int> elements = {1, 2, 3};
    // 调用递归函数生成并打印全排列
    generate_permutations(elements, 0, elements.size() - 1);
    return 0;
}
