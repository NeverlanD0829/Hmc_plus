#include<iostream>
#include<vector>
using namespace std;

/*
    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
    请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/


class Solution{
public:
    void moveZeroes(vector<int>& nums){
        int slowIndex=0;
        for(int fastIndex=0;fastIndex<nums.size();fastIndex++){
        if(nums[fastIndex]!=0){
            nums[slowIndex++]=nums[fastIndex];
        }
    }
    for(int i=slowIndex;i<nums.size();i++){
        nums[i]=0;
    }
    }
};

int main(){
    vector<int> nums={0,1,0,3,12};
    Solution solution;
    solution.moveZeroes(nums);
    cout<<"After:";
    
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}