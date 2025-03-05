// 2579. Count Total Number of Colored Cells
// https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05

class Solution {
public:
    long long coloredCells(int n) {
        long long x = (long long)n;
        return 1 + 4 * (x * (x - 1) / 2);
    }
};

