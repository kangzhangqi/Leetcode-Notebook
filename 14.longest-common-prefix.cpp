/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.61%)
 * Total Accepted:    269.8K
 * Total Submissions: 853.5K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string res="";
		if ( strs.size() == 0) return res;
		if ( strs.size() == 1) return strs[0];

		int min_length = strs[0].size();
		for (int i = 0; i < strs.size(); ++i){
			min_length = min_length > strs[i].size() ? strs[i].size() : min_length;
		}
		
		bool isMatch = true;
		for (int i = 0; i < min_length && isMatch; ++i){
			for (int j =1; j < strs.size() && isMatch; ++j){
				isMatch = strs[0][i] == strs[j][i] ? true : false;
			}
			if(isMatch){
				res +=strs[0][i];
			}
		}
		return res;
    }
};
