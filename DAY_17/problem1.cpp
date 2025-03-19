// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (t.length() != s.length()){ return false; }

        int mapTtoS[256];
        int mapStoT[256];
        for (int i = 0; i < 256; i++) {
            mapStoT[i] = -1;
            mapTtoS[i] = -1;
        }

        for (int i = 0;i < s.length();i++){
            if (mapStoT[s[i]] == -1){
                if (mapTtoS[t[i]] != -1 && mapTtoS[t[i]] != s[i]){
                    return false;
                }
                mapStoT[s[i]] = t[i];
                mapTtoS[t[i]] = s[i];
            }
            else if (mapStoT[s[i]] == t[i]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

// TC O(n) SC O(1){fixed size arrays are used which take constant space}

// We use two arrays, mapStoT[256] and mapTtoS[256], to store character mappings from s → t and t → s. As we iterate through the strings, we ensure each character maps uniquely in both directions. If any character conflicts with a previous mapping, we return false; otherwise, we successfully form a valid one-to-one mapping and return true.

// first check if the element is already mapped to somehting or not if it is not mapped to anything yet check if the thing it is trying to map with is already mapped or not if it passes this then map both the characters if the element of S is already mapped just check if it is mapping to the same elment again or not  