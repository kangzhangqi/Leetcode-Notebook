/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (29.65%)
 * Total Accepted:    300.9K
 * Total Submissions: 1M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
          return 0;
        
        if (haystack.size() < needle.size() || haystack.size() == 0){
            return -1;
        }

        //用do-while 或者 用 条件语句
        for (int i = 0; i < haystack.size() - needle.size() + 1 || i == 0; ++i){
            bool ifcontinue = true;
            for(int j = 0; j < needle.size() && ifcontinue; ++j){
                if (haystack[i + j] != needle[j])
                  ifcontinue = false;
            }
            if (ifcontinue){
                //匹配成功，返回匹配字符串位置。
                return i;
            }
        }
        //匹配失败，退出。
        return -1;
    }
};
