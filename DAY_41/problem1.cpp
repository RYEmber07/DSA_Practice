// 282. Expression Add Operators
// https://leetcode.com/problems/expression-add-operators/

class Solution {
public:
    void generate(vector<string>& ans, const string& num, string currString, int target, int indx, long eval, long prev){
        if (indx == num.length()){
            if (eval == target){
                ans.push_back(currString);
            }
            return;
        }
        string temp = "";
        for (int i = indx;i < num.length();i++){
            if (i > indx && num[indx] == '0'){ break; }
            temp += num[i];
            long val = stol(temp);
            if (indx == 0){
                generate(ans, num, currString + temp, target, i + 1, val, val);
            }
            else{
                generate(ans, num, currString + '+' + temp, target, i + 1, eval + val, val);
                generate(ans, num, currString + '-' + temp, target, i + 1, eval - val, -1 * val);
                generate(ans, num, currString + '*' + temp, target, i + 1, eval - prev + prev * val, prev * val);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string currString = "";
        generate(ans, num, currString, target, 0, 0, 0);
        return ans;
    }
};

// TC O(n * 3^n) SC O(n{recursive stack space} + approx (3^n)*n to store the result)

// At each gap between digits: 3 choices: +, -, or *.
// (Merging digits — "no operator" — is already handled inside substring picking. so actually a *n not a 4^n)
// also dont use substr as it takes O(n) it using temp += num[i] , instead build the string.

// So what we were doing for indx, 3^n-1 possibilites and similarly 3^n-2 and so on. 
// Total Possibilites for all substrs(consider multi digit numbers)= 3^n-1 + 3^n-2 + ..... 3^0 = 3^n-1(1+1/3+1/9+.....) = approx 3^n
// we also do string concatenation for each possibility so final TC is n*3^n .

// In Short => TC is O((no. of path)^depth * work at each possibility)


// for eg. we have 123 now to tackle for the cases of multi digit numbers we first take the number 1 alone then 12 then 123 which is achieved using a loop , we need to eliminate numebrs starting with 0 except just 0 itself consider that . now convert this string to a number by stoi() or stol(){constraints are bigger}. if the indx was the first index simply the currString becomes the temp , now for the other indexes if we add a '+' sign between previous string and temp string the eval becomes eval + val , for '-' it becomes eval - val , the case for '*' is different since it has a higher precedence we cant do (a+b)*c if we needed ot do a+b*c , to tackle that we will always have the prev value{last number that was under operation} with us the eval is a+b as of now subtract b and now add b*c we get our result for - pass -val as prev , for * pass prev*val as prev . if eval == target when iteration ahs completed push_back the result . 