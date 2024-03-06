/*
    给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
    元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums) {
	if (nums.size() < 2) {
        return nums.size();
    }
	int slowIndex = 0;
	for (int fastIindex = 1; fastIindex < nums.size(); fastIindex++)
		if (nums[slowIndex] != nums[fastIindex]){
            nums[++slowIndex] = nums[fastIindex];           //先执行slowIndex的自相加，再进行nums的赋值
        }
	return ++slowIndex;
}
};

int main() {
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    Solution solution;
    int newSize=solution.removeDuplicates(nums);
    cout<<"The new size is:"<<newSize<<endl;

    for(int i=0;i<newSize;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
