/*
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (22.34%)
 * Total Accepted:    103.6K
 * Total Submissions: 463.8K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodstudentgoodword",
 * ⁠ words = ["word","student"]
 * Output: []
 * 
 * 
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector <int> res;
        if (s.empty() || words.empty()) return res;
        int w_num = words.size(), w_length = words[0].size();
        unordered_map <string,int> map;
        for (auto &a : words) ++map[a];
        for (int i = 0; i <= ((int)s.size() - w_num * w_length); ++i){
            unordered_map <string,int> temp_map;
            int j = 0;
            for (; j < w_num; ++j){
                string temp = s.substr(i + j*w_length, w_length);
                //未找到
                if (map.find(temp) == map.end()) break;
                //找到
                ++temp_map[temp];
                if (temp_map[temp] > map [temp]) break;
            }
            if (j == w_num) res.push_back(i);
        }
        return res;
    }
};
