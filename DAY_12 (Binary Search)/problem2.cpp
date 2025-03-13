// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startPos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (startPos == nums.size() || nums[startPos] != target){
            return { -1,-1 };
        }
        int endPos = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return { startPos,endPos };
    }
};

//TC O(logn) SC O(1)