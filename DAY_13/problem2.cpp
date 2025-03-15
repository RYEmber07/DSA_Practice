// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid, mini = INT_MAX;
        while (high >= low){
            mid = low + (high - low) / 2;
            if (nums[low] <= nums[high]){
                mini = min(mini, nums[low]);
                break;
            }
            if (nums[mid] >= nums[low]){
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            else{
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};

// TC O(logn) SC O(1)

// Another Approach 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid, mini=INT_MAX;
        while (high >= low){
            mid = low + (high - low) / 2;
            if (min({ nums[low],nums[high],nums[mid] }) == nums[mid]){
                mini = nums[mid];
                low++;
                high--;
            }
            else if (min(nums[low], nums[high]) == nums[low]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return mini;
    }
};

// TC O(logn) SC O(1)