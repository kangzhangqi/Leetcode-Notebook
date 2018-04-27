/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (37.93%)
 * Total Accepted:    866.5K
 * Total Submissions: 2.3M
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * author:	Kang Zhangqi
 * Date:	03/04/2018
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	int size = nums.size();
        vector<int> results;
        //printf("size = %d, target = %d \n",size,target);        
        for (int i = 0; i < (size - 1); i++ ){
        	//printf("loop i = %d ,num = %d\n", i , nums[i]);
        	for (int j = i + 1; j < size; j++){
        		//printf("loop j = %d ,num = %d\n", j , nums[j]);
        		if (nums[i] + nums[j] == target){
        		//printf("find index successed!");
        		results.push_back(i);
        		results.push_back(j);
        		return results;
      			}
         	}
	}
	//printf("find index failed!\n");
	return results;
    }
};
