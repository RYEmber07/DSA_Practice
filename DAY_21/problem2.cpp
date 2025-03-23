// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    int checkCount(string s, int i, int j){
        while (i >= 0 && j < s.length() && s[i] == s[j]){
            i--;
            j++;
        }
        return j - i - 1;
    }
    string longestPalindrome(string  s) {
        int maxCount = 1, firstIndx = 0;
        for (int i = 0;i < s.length();i++){
            int len1 = checkCount(s, i, i);
            int len2 = checkCount(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxCount){
                maxCount = len;
                firstIndx = i - (len - 1) / 2;
            }
        }
        return s.substr(firstIndx, maxCount);
    }
};

// Approach : We use the expand-around-center technique to find the longest palindromic substring. Each character (and each pair of adjacent characters) is treated as a potential center, and we expand outward while the characters match. The function checkCount() finds the longest palindrome centered at (i, i) for odd-length and (i, i+1) for even-length palindromes. We track the maximum length and starting index, then return the longest palindrome.
// keep in mind chehcing both cases is needed or it might lead to failure if you have lets say ccc or aaaa if you try if else
// TC : O(n square) 
// Each center is expanded outward until the characters mismatch. In the worst case (when the string is all the same character), each expansion runs O(N). Since we check N centers, the total complexity is O(n²).
// SC : O(1)