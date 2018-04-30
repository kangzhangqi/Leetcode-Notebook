/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.80%)
 * Total Accepted:    320.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>  res;
		sort(nums.begin(),nums.end());

		if (nums.size() < 3) return res;

		//find negtive 'a'
		for (int i = 0; i < nums.size()- 2 && nums[i] < 1; ++i){
			if (i > 0 && nums[i] == nums[i-1]) continue;
			int target = -nums[i];
			int left = i +1;
			int right = nums.size() -1;
			while(left < right && nums[right] > -1){
				if (nums[left] + nums[right] == target){
					res.push_back({nums[i],nums[left],nums[right]});
					while(left < right && nums[left] == nums[left + 1]) ++left;
					while(left < right && nums[right] == nums[right -1]) --right;
					++left;
					--right;
					continue;
				}
				if (nums[left] + nums[right] > target)
				  --right;
				else
				  ++left;
			}
		}
		return res;
    }
};
