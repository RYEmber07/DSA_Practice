// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/description/

// Brute Force

class Solution {
public:
    vector<string> ans;
    bool isValidParentheses(string s){
        int sum = 0;
        for (char& ch : s){
            if (ch == '('){ sum++; }
            else{ sum--; }

            if (sum < 0){ return false; }
        }
        if (sum != 0){ return false; }
        return true;
    }
    void generate(string& currString, int n){
        if (currString.length() == 2 * n){
            if (isValidParentheses(currString)){
                ans.push_back(currString);
            }
            return;
        }
        currString.push_back('(');
        generate(currString, n);
        currString.pop_back();

        currString.push_back(')');
        generate(currString, n);
        currString.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string currString = "";
        generate(currString, n);
        return ans;
    }
};

// Brute Force by generating all possible combinations TC O(2n * 2^2n) SC O(2n) (recursive stack space)
// note how we can easily check valid paranthesis here

// Better

class Solution {
public:
    vector<string> ans;
    void generate(string& currString, int openCount, int closeCount, int n){
        if (currString.length() == 2 * n){
            ans.push_back(currString);
            return;
        }
        if (openCount < n){
            openCount++;
            currString.push_back('(');
            generate(currString, openCount, closeCount, n);
            openCount--;
            currString.pop_back();
        }

        if (closeCount < openCount){
            closeCount++;
            currString.push_back(')');
            generate(currString, openCount, closeCount, n);
            closeCount--;
            currString.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string currString = "";
        int openCount = 0, closeCount = 0;
        generate(currString, openCount, closeCount, n);
        return ans;
    }
};

// TC O(2^2n) SC O(2n)
// Approach : just eliminate the going to all possible strings step and use openBrackett and closeBrackett property 
// also we use a backtracking apporach where we do some work and explore then undo it 