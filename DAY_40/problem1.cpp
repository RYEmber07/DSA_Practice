// 139. Word Break
// https://leetcode.com/problems/word-break/

class Solution {
public:
    int dp[301];
    int n;
    bool generate(const string& s, unordered_set<string>& st, int indx){
        if (indx == n){
            return true;
        }
        if (dp[indx] != -1){
            return dp[indx];
        }
        for (int i = indx;i < n;i++){
            if (st.find(s.substr(indx, i - indx + 1)) != st.end() && generate(s, st, i + 1)){
                return dp[indx] = true;
            }
        }
        return dp[indx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        memset(dp, -1, sizeof(dp));
        n = s.length();
        for (string& word : wordDict){
            st.insert(word);
        }
        return generate(s, st, 0);

    }
};

// TC O(n cube{we used memoization}) SC O(n){recursion stack space} + O(n+n){dp array+substring} +  O(m × k) {for the unordered_set , k is length of word in dict}

// Approach : for every indx select all substrings starting from that indx check if this substr exists in wordDict if it does recursively call for the next possible word . 
// if we had used only recursion the TC would be closer to n*2^n since we can split the string at any position and also since substring creation would take O(n) but since we used memoization each indx needs to be visited only once.

// Memoization : The Technique Where we store the results in an contianer so that we can use it for other recursion calls hence exploring the data only once and avoiding the same calls again and again.

