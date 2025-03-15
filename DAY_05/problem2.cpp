// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/description/?envType=problem-list-v2&envId=greedy

class Solution {
public:
    int longestPalindrome(string s) {
        int hash[52] = { 0 };
        for (int i = 0;i < s.length();i++){
            if (s[i] >= 'a' && s[i] <= 'z'){
                hash[s[i] - 'a']++;
            }
            else{
                hash[s[i] - 'A' + 26]++;
            }
        }
        int count = 0;
        bool got1 = 0;
        for (int i = 0;i < 52;i++){
            if (hash[i] >= 1){
                count += (hash[i] / 2) * 2;
                if (hash[i] % 2 != 0 && got1 == false){
                    got1 = true;
                    count += 1;
                }
            }
        }
        return count;
    }
};