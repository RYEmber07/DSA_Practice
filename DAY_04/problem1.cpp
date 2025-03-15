// 2549. Count Distinct Numbers on Board
// https://leetcode.com/problems/count-distinct-numbers-on-board/description/?envType=problem-list-v2&envId=math

class Solution {
public:
    int distinctIntegers(int n) {
        if (n == 1){ return 1; }
        return n - 1;
    }
};