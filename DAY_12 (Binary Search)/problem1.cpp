// 704. Binary Search
// https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (target == nums[mid]){
                return mid;
            }
            else if (target > nums[mid]){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

// TC O(logn) SC O(1)