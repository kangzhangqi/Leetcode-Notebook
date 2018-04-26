/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (23.13%)
 * Total Accepted:    254.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total_size = nums1.size() + nums2.size();
		int nums[total_size] = {0};
		int nums1_idx = 0,nums2_idx = 0;
		double result = 0.0;
		for (int i = 0; i < total_size; ++i){
			if (nums1_idx < nums1.size() && nums2_idx < nums2.size()){
				if (nums1[nums1_idx] <= nums2[nums2_idx] )
					nums[i] = nums1[nums1_idx++];
				else
					nums[i] = nums2[nums2_idx++];
			}
			else{
				if(nums1_idx >= nums1.size())
					nums[i] = nums2[nums2_idx++];
				else 
					nums[i] = nums1[nums1_idx++];
			}
		}
		if(total_size == 0){
			result = 0.0;
		}
		//偶数个，两个中位数的平均值
		else if(total_size % 2 == 0){
			int bet1 = nums[int(total_size/2)-1];
			int bet2 = nums[int(total_size/2)];
			result = (bet1 + bet2) / 2.0;
		}
		//奇数个，中间是中位数
		else{
			result = nums[((total_size-1)/2)];
		}
		return result;
    }
};
