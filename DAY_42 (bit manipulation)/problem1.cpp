// 136. Single Number
// https://leetcode.com/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for (auto it : nums){
            n = n ^ it;
        }
        return n;
    }
};

// TC O(n) SC O(1)
// Approach : Used XOR property as any element occurs either 1 time or 2 .

// Brute Force : Check all elements for all element TC O(n square) SC O(1)
// Better : Hash the values TC O(n) SC O(n)
