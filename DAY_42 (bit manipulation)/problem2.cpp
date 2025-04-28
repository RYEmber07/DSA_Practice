// 2220. Minimum Bit Flips to Convert Number
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};

// TC O(1) SC O(1)
// Approach : XOR property will make unlike elements as 1 and others as 0 . coutn the no. of 1s using STL built in function.
