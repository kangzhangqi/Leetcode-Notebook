/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.18%)
 * Total Accepted:    165.7K
 * Total Submissions: 567.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

//获取下一个排列组合
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, n = nums.size();
        for (i = n - 2; i >= 0; --i){    
            //step1:从后往前寻找第一个前一个数比后一个数小的数ni
            if (nums[i + 1] > nums[i]) {
                //step2:从后往前寻找第一个比ni大的数nj
                for (j = n - 1; j >= 0; --j){
                    if (nums[j] > nums[i]) break;
                }
                //step3:交换ni与nj
                swap(nums[i], nums[j]);
                //step4:
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        //step5:如果不符合上述if条件，不存在ni，则为全颠倒。
        reverse(nums.begin(),nums.end());
    }
};
