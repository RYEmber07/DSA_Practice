// 1021. Remove Outermost Parentheses
// https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int level = 0;
        for (int i = 0;i < s.length();i++){
            if (s[i] == '('){ level += 1; }
            if (level > 1){
                ans += s[i];
            }
            if (s[i] == ')'){ level -= 1; }
        }
        return ans;
    }
};

// TC O(n) SC O(n){to return ans}
// Approach : we can think of depth/levels when we encouter '(' we have to increase the level immediately but when we encouter ')'
// we need level to be same for ) but for next iteration to be decreased 
// ((())()) 
// 12332221


// Alternate approach using Stack
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> stk;
        for (int i = 0;i < s.length();i++){
            if (s[i] == '('){
                if (!stk.empty()){
                    ans += '(';
                }
                stk.push('(');
            }
            else{
                stk.pop();
                if (!stk.empty()){
                    ans += ')';
                }
            }
        }
        return ans;
    }
};
// TC O(n) SC(2*n)