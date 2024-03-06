// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
// 思路：排序后最大的数由两边之一得到，首先确定排序后的数组大小，双指针从两端开始往中间移动，每移动一步，将结果取平方保存，直至left=right

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> sorted_Squares(vector<int>& nums){
        int n=nums.size()-1;
        vector<int> result(n+1,0);          //创建整数向量，长度为n+1，初始化所有值为0。
        int left=0;
        int right=n;
        // int i=0;
        while(left<=right){
            int a=nums[left]*nums[left];
            int b=nums[right]*nums[right];
            // n-- 是后缀递减操作符，表示先使用 n 的当前值，然后再将 n 的值减 1。
            // n -= 1 是赋值运算符，表示将 n 的值减 1，并将结果赋给 n。
            // n - 1 是一个表达式，表示将 n 的值减 1，但不会修改 n 的值。
            if(a>b){
                result[n--]=a;
                left++;
            }
            else{
                result[n--]=b;
                right--;
            }
        }
        for(int i=0;i<nums.size();i++){
            cout<<result[i]<<" ";
        }
        return result;
    }
};

int main(){
    vector<int> nums={-4,-1,0,3,10};
    Solution solution;
    solution.sorted_Squares(nums);
    
    return 0;
}