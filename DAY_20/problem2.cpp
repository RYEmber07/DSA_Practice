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

// TC O(n) SC O(1)
// The time complexity of this code is O(N), where N is the length of the input string. The reason is that the code processes each character of the string at most once. It first skips leading spaces, which takes O(N) in the worst case. Then, it checks for a sign (+ or -), which is a constant-time operation. After that, it iterates through the numeric characters, converting them into an integer while checking for overflow. Since each character is processed only once, the overall time complexity remains O(N).
// The space complexity is O(1) because the algorithm only uses a few integer variables(k, sign, result), and it does not use any additional data structures that scale with input size.