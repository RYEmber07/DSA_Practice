// 921. Minimum Add to Make Parentheses Valid
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

// Optimal

class Solution {
public:
    int minAddToMakeValid(string s) {
        int countOpen = 0, countClose = 0;
        for (int i = 0;i < s.length();i++){
            if (s[i] == '('){
                countOpen++;
            }
            else{
                if (countOpen > 0){
                    countOpen--;
                }
                else{
                    countClose++;
                }
            }
        }
        return countOpen + countClose;
    }
};

// TC O(n) SC O(1)
// Approach : traverse the string if there is ) but there already exists a ( for it dont count this pair , otherwise count it and also consider the ( for which there was never a ) .

// Brute Using Stack 

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> stk;
        int count = 0;
        for (int i = 0;i < s.length();i++){
            if (s[i] == '('){
                stk.push('(');
            }
            else{
                if (!stk.empty()){
                    stk.pop();
                }
                else{
                    count++;
                }
            }
        }
        return count + stk.size();
    }
};

// TC O(n) SC O(n)

// Other way of brute with only stack (same TC and SC as brute)

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> stk;
        for (int i = 0;i < s.length();i++){
            if (s[i] == '('){
                stk.push('(');
            }
            else{
                if (!stk.empty() && stk.top() == '('){
                    stk.pop();
                }
                else{
                    stk.push(')');
                }
            }
        }
        return stk.size();
    }
};


