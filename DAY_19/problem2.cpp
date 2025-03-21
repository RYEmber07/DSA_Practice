// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        int valueInInt = 0;
        for (int i = 0;i < s.length();i++){
            switch (s[i]){
            case 'M':
                valueInInt += 1000;
                break;
            case 'D':
                valueInInt += 500;
                break;
            case 'C':
                if (i == s.length() - 1 || (s[i + 1] != 'D' && s[i + 1] != 'M')){
                    valueInInt += 100;
                }
                else{
                    valueInInt -= 100;
                }
                break;
            case 'L':
                valueInInt += 50;
                break;
            case 'X':
                if (i == s.length() - 1 || (s[i + 1] != 'L' && s[i + 1] != 'C')){
                    valueInInt += 10;
                }
                else{
                    valueInInt -= 10;
                }
                break;
            case 'V':
                valueInInt += 5;
                break;
            case 'I':
                if (i == s.length() - 1 || (s[i + 1] != 'V' && s[i + 1] != 'X')){
                    valueInInt += 1;
                }
                else{
                    valueInInt -= 1;
                }
            }
        }
        return valueInInt;
    }
};

// TC O(n) SC O(1)
// Approach : considered the cases in a switch statement.