// 1781. Sum of Beauty of All Substrings
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for (int i = 0;i < s.length();i++){
            int freq[26] = { 0 };
            for (int j = i;j < s.length();j++){
                freq[s[j] - 'a']++;
                int maxFreq = 1, minFreq = j - i + 1;
                for (int i = 0;i < 26;i++){
                    if (freq[i] > maxFreq){
                        maxFreq = freq[i];
                    }
                    if (freq[i] < minFreq && freq[i]>0){
                        minFreq = freq[i];
                    }
                }
                sum += maxFreq - minFreq;
            }
        }
        return sum;
    }
};

// TC O(n square) SC O(1){fixed sized array is used for hashing}
// Approach : for every starting index add the element just added by j in the hashing then for that substrign find maxfreq and minFreq O(1) time as we are using a constant sized array . add the difference of the max and min freq remember min freq cant be 0. 
