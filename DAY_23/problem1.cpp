// 686. Repeated String Match
// https://leetcode.com/problems/repeated-string-match/description/

class Solution {
public:
    bool check(string text, string target){
        int n = text.length();
        int m = target.length();

        // to calculate LPS / PI array
        string s = target + '#' + text;
        vector<int> LPS(s.length(), 0);
        for (int i = 1;i < LPS.size();i++){
            int prev_indx = LPS[i - 1];
            while (s[prev_indx] != s[i] && prev_indx > 0){
                prev_indx = LPS[prev_indx - 1];
            }
            if (s[prev_indx] == s[i]){
                LPS[i] = prev_indx + 1;
            }
            else{
                LPS[i] = 0;
            }
        }

        // find the LPS that is equal to pattern length
        for (int i = 0;i < LPS.size();i++){
            if (LPS[i] == m){
                return true;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string temp = a;
        while (temp.length() < b.length()){
            count++;
            temp += a;
        }
        if (check(temp, b)){
            return count;
        }
        temp += a;
        count += 1;
        if (check(temp, b)){
            return count;
        }
        return -1;
    }
};

// This soln is using the KMP algo that takes TC O(m+n) SC O(m+n) {slight modification}

// For other approaches refer : 
// https://leetcode.com/problems/repeated-string-match/submissions/
// Rabin Karp with Double Hashing
// Rabin Karp Algo TC  best case and avg case O(m+n) worst case O(m.n) SC O(1) 
// KMP Algo TC O(n+m) SC O(m) 
// Brute Without using .find() 
// Brute Using .find() TC O(n*m) SC O(m+n) . 