// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int k = 0;
        bool sign = false;
        int result = 0;
        while (s[k] == ' ' && k < s.length()){
            k++;
        }
        if (s[k] == '-'){
            sign = true;
            k++;
        }
        else if (s[k] == '+'){
            k++;
        }
        for (int i = k;i < s.length();i++){

            if (!(s[i] >= '0' && s[i] <= '9')){
                break;
            }

            if (result > (INT_MAX - (s[i] - '0')) / 10){
                if (sign == true){ return INT_MIN; }
                return INT_MAX;
            }
            else{
                result *= 10;
                result += s[i] - '0';
            }
        }

        if (sign == true){ return -1 * result; }
        return result;
    }
};