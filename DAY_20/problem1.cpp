// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        int hash[62] = { 0 };
        for (int i = 0;i < s.length();i++){
            if (s[i] >= 'a' && s[i] <= 'z'){
                hash[s[i] - 'a']++;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z'){
                hash[s[i] - 'A' + 26]++;
            }
            else{
                hash[s[i] - '0' + 52]++;
            }
        }
        while (*max_element(hash, hash + 62) > 0){
            int maximum = max_element(hash, hash + 62) - hash;
            if (maximum < 26){
                for (int i = 0;i < hash[maximum];i++){
                    ans += (char)(maximum + 'a');
                }
                hash[maximum] = 0;
            }
            else if (maximum < 52){
                for (int i = 0;i < hash[maximum];i++){
                    ans += (char)(maximum + 'A' - 26);
                }
                hash[maximum] = 0;
            }
            else{
                for (int i = 0;i < hash[maximum];i++){
                    ans += (char)(maximum + '0' - 52);
                }
                hash[maximum] = 0;
            }
        }
        return ans;
    }
};

// TC O(n) 
// We iterate over the input string s once, Each time, max_element(hash, hash + 62) finds the character with the highest frequency.This takes O(62) ≈ O(1) time. Finding Maximum Frequency Repeatedly(O(62 * N)) . Each time, max_element(hash, hash + 62) finds the character with the highest frequency.This takes O(62) ≈ O(1) time. Since we may need to find the max frequency up to N times(in the worst case where each character appears once), this results in O(N)* O(1) = O(N). Appending Characters to the Result(O(N)) . Each character is appended to ans exactly as many times as it appears in s, contributing another O(N).
// SC O(n)
// constant array is used and for returning ans . 

// Approach: 
// The code first counts the frequency of each character using a fixed - size array(hash[62]).It then repeatedly finds the character with the highest frequency, appends it to the result, and sets its frequency to zero.This ensures characters appear in descending order of frequency.
