// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){ return false; }
        int hashS[26] = { 0 };

        for (int i = 0;i < s.length();i++){
            hashS[s[i] - 'a']++;
            hashS[t[i] - 'a']--;
        }

        for (int i = 0;i < 26;i++){
            if (hashS[i] != 0){
                return false;
            }
        }

        return true;
    }
};

// TC O(n) SC O(1){constant sized array}
// Just do hashing to store the characters of the string 

// Other Approach Is to Sort then compare (though worse TC)
