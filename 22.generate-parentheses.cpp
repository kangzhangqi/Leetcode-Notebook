/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (48.28%)
 * Total Accepted:    210.1K
 * Total Submissions: 435.1K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string> res;
	   generateDFS(n,n,"",res);
	   return res;
    }

	//递归函数
	void generateDFS(int left, int right, string out, vector<string> &res){
		//1.错误条件返回
		if (left > right || left < 0 || right < 0) return;
		//2.终止条件
		if (left == 0 && right ==0){
			res.push_back(out);
			return;
		}else{
			//3.继续递归
			generateDFS(left - 1, right, out + "(", res);
			generateDFS(left, right - 1, out + ")", res);
		}
	}
};
