// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string firstStr = strs[0], lastStr = strs[strs.size() - 1];
        for (int i = 0;i < min(firstStr.size(), lastStr.size());i++){
            if (firstStr[i] != lastStr[i]){
                return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

// TC O(nlogn) SC O(1)
// Approach : If the array is sorted alphabetically then you can assume that the first element of the array and the last element of the array will have most different prefixes of all comparisons that could be made between strings in the array. If this is true, you only have to compare these two strings.

// Or (Though Worse TC)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0;i < strs[0].size();i++){
            for (int j = 1;j < strs.size();j++){
                if (strs[0][i] != strs[j][i] || i >= strs[j].size()){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

// O(m.n) , m: size of string n: size of array
// Approach : for every letter of first element check all other strings 