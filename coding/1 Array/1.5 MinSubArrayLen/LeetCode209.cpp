// 给定一个含有 n 个正整数的数组和一个正整数 s ，
// 找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

//思路：滑动窗口：不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果。一个for循环，表示滑动窗口的终止位置
// 窗口内是什么？             满足其和 ≥ s 的长度最小的 连续 子数组  
// 如何移动窗口的起始位置？     如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。
// 如何移动窗口的结束位置？     窗口的结束位置就是遍历数组的指针，也就是for循环里的索引。

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

int main(){
    vector<int> nums={2,3,1,2,4,3};
    int s=7;
    Solution solution;
    cout<<"最小长度为："<<solution.minSubArrayLen(s,nums)<<endl;
    return 0;
}
