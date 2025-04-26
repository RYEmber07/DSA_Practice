// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    bool checkPalindrome(string s){
        int l = 0;
        int r = s.length() - 1;
        while (l < r){
            if (s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void generate(vector<vector<string>>& ans, vector<string>& temp, string s, int indx){
        if (indx == s.length()){
            ans.push_back(temp);
            return;
        }
        string currString = "";
        for (int i = indx;i < s.length();i++){
            currString.push_back(s[i]);
            if (checkPalindrome(currString)){
                temp.push_back(currString);
                generate(ans, temp, s, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        generate(ans, temp, s, 0);
        return ans;
    }
};

// TC O((2^n)*n) SC O(n) (stack + temporary string list) + O(n * 2^n)
// Approach : for eg. we have abaa , first explore if a is taken as a independent string and also keep checking if this taken string is a palindrome or not then explore when ab is taken which immediately returns back as it is not a palindrome . now move to the next recursion level depth when a was taken to be independent call for baa , explore its possibilites . if any of the string reaches till the end it means all strings were palindromes so add this to the ans.