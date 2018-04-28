/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (37.15%)
 * Total Accepted:    196.9K
 * Total Submissions: 530.1K
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int res = 0;
		while(left < right){
			int temp = min(height[left],height[right]) * (right - left);
			res = (temp > res) ? temp : res;
			if(height[left] < height[right]){
				left++;
			}
			else if(height[left] > height[right]){
				right--;
			}
			else {
				left++;
			}
		}
		return res;   
    }
};
