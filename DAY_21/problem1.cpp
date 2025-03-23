// Substrings with K Distinct
// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-substrings

class Solution {
public:
    int countAtMostK(string s, int k){
        int count = 0, left = 0, uniqueCount = 0;
        int freq[26] = { 0 };
        for (int right = 0;right < s.length();right++){
            if (freq[s[right] - 'a'] == 0){ uniqueCount++; }
            freq[s[right] - 'a']++;

            while (uniqueCount > k){
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0){
                    uniqueCount--;
                }
                left++;
            }

            count += right - left + 1;

        }

        return count;
    }
    int countSubstr(string& s, int k) {
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};

// Approach : We use a sliding window to count substrings with at most k distinct characters, expanding the right and shrinking the left when needed. A frequency array (freq[26]) tracks characters efficiently. To get exactly k distinct characters, we subtract countAtMostK(s, k-1) from countAtMostK(s, k) . 
// Cant directly count the only k distinct character substring sas that will leave some cases when in transition so subtract substrings with atmost k and atmost k-1 distinct characters . 
// right will iterate normally left is 0 and will shift accordignly . 

// TC O(n) {each character vistited twice so technically 2n}
// SC O(1) {fixed size array is used}