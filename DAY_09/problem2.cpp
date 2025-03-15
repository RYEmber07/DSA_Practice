// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/

// Brute --> Merge Sort TC O(nlogn) SC O(n)
// Better --> Count the occurences of 0,1,2 then simply put them in the vector TC O(2n) SC O(1)
// Optimal --> Dutch National Flag (DNF) Algorithm

// Optimal 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high){
            if (nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// TC O(n)
// SC O(1)