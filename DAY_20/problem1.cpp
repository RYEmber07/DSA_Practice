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
