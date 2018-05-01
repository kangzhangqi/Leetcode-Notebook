/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (36.65%)
 * Total Accepted:    234.4K
 * Total Submissions: 639.5K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
/*
 *Author:Zhangqi Kang
 *Date: 01/05/2018
 */

//This solution uses recursion method to fix this problem.
class Solution {
public:
    vector<string> letterCombinations(string digits) {
       vector<string> res;
	   if (digits.empty()) return res;
	   //recursion function call
	   letterREC (digits,0,"",res);
	   return res;
    }

private:
	void letterREC (string digits, int level, string out, vector<string> &res){
		if (level == digits.size())
		  res.push_back(out);
		else{
			string str = Dict[digits[level] - '2'];
			for (int i = 0; i < str.size(); ++i){
				letterREC(digits, level + 1, out + str[i],res);
			}
		}
	}

	string Dict[8]={"abc",//2
				   "def",//3
				   "ghi",//4
				   "jkl",//5
				   "mno",//6
				   "pqrs",//7
				   "tuv",//8
				   "wxyz"//9
	};
};
