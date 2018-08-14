/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (23.57%)
 * Total Accepted:    137.9K
 * Total Submissions: 584.4K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0;
        stack <int> valid;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '(') valid.push(i);
            else if (s[i] == ')'){
                if (valid.empty()) start = i + 1;
                else {
                    valid.pop();
                    res = valid.empty() ? max(res, i - start + 1) : max(res, i - valid.top());
                }
            }
        }
        return res;
    }
};
