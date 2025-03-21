// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while (high >= low){
            mid = (low + high) / 2;
            if (nums[mid] == target){ return mid; }
            else if (nums[mid] >= nums[low]){
                if (target <= nums[mid] && target >= nums[low]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if (target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

// TC O(logn) SC O(1)