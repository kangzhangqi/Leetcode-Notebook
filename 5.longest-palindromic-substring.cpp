/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.34%)
 * Total Accepted:    311.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
       int left = 0, right = 0, start_idx = 0, len = 0;
	   for(int i = 0; i < s.size()-1; ++i){
		   if (s[i] == s[i+1]){
			   left = i;
			   right = i+1;
			   searchPalindrome(s,left,right,start_idx,len);
		   }
		   left = right = i;
		   searchPalindrome(s,left,right,start_idx,len);
	   }
	   if (len == 0)
		 len = s.size();
	   return s.substr(start_idx,len);
    }

	void searchPalindrome(string s,int left, int right, int &start_idx, int &len){
		int step = 1;
		while ((left - step ) >=0 && (right + step) < s.size()){
			if(s[left - step] != s[right + step])
			  break;
			++step;
		}
		int this_length = right - left + 1 + 2 * (step - 1);
		if(this_length > len){
			len = this_length;
			start_idx = left - step +1;
		}
	}
};
