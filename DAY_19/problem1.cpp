// 1614. Maximum Nesting Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxDepth = 0;
        for (int i = 0;i < s.length();i++){
            if (s[i] == '('){
                depth++;
                maxDepth = max(depth, maxDepth);
            }
            else if (s[i] == ')'){
                maxDepth = max(depth, maxDepth);
                depth--;
            }
        }
        return maxDepth;
    }
};

//T C O(n) SC O(1)
// Approach : find depth for each paranthisis and keep updating maxdepth.