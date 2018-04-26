/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.72%)
 * Total Accepted:    478.7K
 * Total Submissions: 1.9M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int result = 0;
	   int begin_idx = 0;
	   int map[256]={0};

	   if (s.size() <=1)
		 return s.size();

	   for (int i = 0; i< s.size(); ++i){
		   if(map[s[i]] == 0 || map[s[i]] < begin_idx){
			 result = max(result,i - begin_idx +1);
		   }
		   else{ 
			 begin_idx = map[s[i]];
		   }
		   map[s[i]]=i+1;
	   }
	   return result;
    }
};
