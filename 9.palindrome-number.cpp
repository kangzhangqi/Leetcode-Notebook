/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (36.00%)
 * Total Accepted:    326.1K
 * Total Submissions: 905.4K
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
class Solution {
public:
    bool isPalindrome(int x) {
		if((x < 0 || x % 10 ==0) && x!=0)
		  return false;
		string num = itoa(x);
		int left = 0;
		int right = num.size() - 1;
		while (left < right){
			if (num[left] == num[right]){
				left++;
				right--;
				continue;
			}else
			  break;
		}
		if(left == right || left > right)
		  return true;
		else
		  return false;
    }

	string itoa(int x){
		string res="";
		while(x > 0){
			res += ((x%10) + 48);
			x /=10;
		}
		return res;
	}
};
