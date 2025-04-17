// 1922. Count Good Numbers
// https://leetcode.com/problems/count-good-numbers/description/

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long a, long long b){
        if (b == 0){
            return 1;
        }
        long long half = power(a, b / 2);
        long long result = (half * half) % MOD;
        if (b % 2 == 0){
            return result;
        }
        return (a * result) % MOD;
    }
    int countGoodNumbers(long long n) {
        return (power(5, (n + 1) / 2) * power(4, n / 2)) % MOD;
    }
};

// TC O(logn) SC O(logn) {recursive stack space}
// Approach : use PnC to think of how we can reach the count , now to find power of such large numbers binary exponentiation is the method we can also use the iterative version but i have used the recursive one , keep in mind whenever you multiply things it might exceed the limit so keep on taking MOD with the given number.