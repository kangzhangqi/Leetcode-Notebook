/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (31.72%)
 * Total Accepted:    174.7K
 * Total Submissions: 550.6K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
		if (nums.size() < 3) return res;
		res = nums[0] + nums[1] + nums[2];
		int res_abs = abs(target - res);

		sort(nums.begin(),nums.end());

		for (int i = 0; i < nums.size() - 2; ++i){
			int left = i + 1;
			int right = nums.size() -1;
			while(left < right){
				int sum = nums[i] + nums[left] + nums[right];
				int sum_abs = abs(target - sum);
				if ( sum_abs < res_abs ){
				  res = sum;
				  res_abs = sum_abs;
				}
				// move left index and right index
				if (sum < target)
				  ++left;
				else if (sum > target)
				  --right;
				else
				  return sum;
			}
		}
        return res;
    }
};
