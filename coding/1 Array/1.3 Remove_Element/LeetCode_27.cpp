#include <iostream>
#include <vector>
using namespace std;

//暴力解法
// class Solution {
// public:
//     int removeElement(vector<int>& nums,int val){       //模板类vector，表示一个存储整数类型（int）元素的动态数组。 &使用引用作为参数，允许函数直接修改原始数据，而不是对数据进行复制
//     /*
//         思路：先确定数组的大小，第一个for循环遍历数组中的每个元素，如果发现要移除的数据，进入第二个for循环，将数组集体前移。
//             每前移一次，数组大小减1，
//     */
//    int size=nums.size();
//    for(int i=0;i<size;i++){
//     if(nums[i]==val){
//         for(int j=i+1;j<size;j++){
//             nums[j-1]=nums[j];
//         }
//         i--;
//         size--;
//     }
//    }
//    return size;
// }
// };

// 双指针法
/*
    在一个for循环下，快指针找新数组的元素，新数组就不含val。  慢指针指向更新后的新数组下标位置。
*/
class Solution{
public:
    int removeElement(vector<int> &nums,int val){
        int size=nums.size();
        int slowIndex=0;
        for(int fastIndex=0;fastIndex<size;fastIndex++){
            if(val !=nums[fastIndex]){
                nums[slowIndex++]=nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main() {
    vector<int> nums={0,1,2,2,3,0,4,2};
    int val=2;
    Solution solution;
    int newSize=solution.removeElement(nums,val);
    cout<<"The new size is:"<<newSize<<endl;

    for(int i=0;i<newSize;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
