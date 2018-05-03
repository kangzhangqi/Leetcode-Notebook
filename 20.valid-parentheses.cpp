/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.06%)
 * Total Accepted:    331.5K
 * Total Submissions: 973.4K
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
       stack<char> valid;
	   for(int i = 0; i < s.size(); ++i){
		   if(s[i] == '[' || s[i] == '(' || s[i] =='{')
			 valid.push(s[i]);
		   else{
			   //要点1：验证是否少左括号
			   if(valid.empty()) return false;
			   if(s[i] == ']' && valid.top() != '[') return false;
			   if(s[i] == '}' && valid.top() != '{') return false;
			   if(s[i] == ')' && valid.top() != '(') return false;
			   valid.pop();
		   }
	   }
	   //要点2：最后返回，验证是否缺右括号
	   return valid.empty();
    }
};
