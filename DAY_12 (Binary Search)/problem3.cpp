// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};

// Another Method 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = nums.size();
        int low = 0, high = nums.size() - 1, mid;
        while (high >= low){
            mid = low + (high - low) / 2;
            if (nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};


// using STL
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

// TC O(logn) SC O(1)