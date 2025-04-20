// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> ans;
    void generate(string& temp, const string& digits, int indx, vector<char> mapping[]){
        if (indx == digits.size()){
            ans.push_back(temp);
            return;
        }
        for (int i = 0;i < mapping[digits[indx] - '2'].size();i++){
            temp.push_back(mapping[digits[indx] - '2'][i]);
            generate(temp, digits, indx + 1, mapping);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<char> mapping[] = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };
        if (digits.empty()) return {};
        string temp;
        generate(temp, digits, 0, mapping);
        return ans;
    }
};

// TC O(4^n*n){n is length of digits} SC O(n{recursive stack space} + 4^n*n{to store the ans})
// Approach : for each digit of digits we can 3/4 possibilities explore them.