// 214. Shortest Palindrome
// https://leetcode.com/problems/shortest-palindrome/description/

// Brute Force 
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        for (int i = 0;i < s.length();i++){
            if (!memcmp(s.c_str(), rev.c_str() + i, s.length() - i)){
                return rev.substr(0, i) + s;
            }
        }
        return rev + s;
    }
};

// TC O(n square) SC O(n)
// if we use .substr() to compare s and rev Memory Limit Exceeds , as .substr() makes the substring again and again.
// memcemp() gives 0 if two strings are same.

// Optimal 
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string str = s + '#' + rev;
        vector<int> LPS(str.length(), 0);
        for (int i = 1;i < LPS.size();i++){
            int prev_indx = LPS[i - 1];
            while (str[prev_indx] != str[i] && prev_indx > 0){
                prev_indx = LPS[prev_indx - 1];
            }
            if (str[prev_indx] == str[i]){
                LPS[i] = prev_indx + 1;
            }
        }

        return rev.substr(0, s.length() - LPS[str.length() - 1]) + s;
    }
};

// TC O(n) SC O(n)
// Using the KMP algo we have to make the PI array of string +"#"+ reverse of string . then we find the longest prefix of s that is the suffix which is basically telling us the longest palindromic part in starting of the string .