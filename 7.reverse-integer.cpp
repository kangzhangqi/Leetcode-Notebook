/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.38%)
 * Total Accepted:    401.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */

/*
 *Author:	Zhangqi kang
 *Date:		27/04/2018
 */
class Solution {
public:
    int reverse(int x) {
	   //防止数据越界
	   if (x < (INT_MIN+1) || x >INT_MAX || x ==0){
		   return 0;
	   }

	   bool is_negtive = false;
	   int input = 0;
	   int res = 0;
	   if(x < 0){
		 is_negtive = true;
		 input = -x;
	   }
	   else{
		   input = x;
	   }
	   while(input != 0){
		   if(res > INT_MAX/10 || (res == INT_MAX/10) && (input%10 > INT_MAX%10))
			 return 0;
		   res = res*10 + input%10;
		   input /= 10;
	   }
	   if (is_negtive)
		 res = -res;

	   return res;
    }
};
