// 1. Two Sum
// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mpp;
        for (int i = 0;i < nums.size();i++){
            if (mpp.find(target - nums[i]) != mpp.end()){
                return { mpp[target - nums[i]],i };
            }
            mpp[nums[i]] = i;
        }
        return { -1,-1 };
    }
};

// TC O(n) , worst case O(n square)
// SC O(n)