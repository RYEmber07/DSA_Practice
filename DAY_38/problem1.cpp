// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& temp, vector<int>& nums, int indx){
        ans.emplace_back(temp);
        for (int i = indx;i < nums.size();i++){
            if ((i > indx) && nums[i] == nums[i - 1]){
                continue;
            }
            temp.emplace_back(nums[i]);
            generate(temp, nums, i + 1);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        generate(temp, nums, 0);
        return ans;
    }
};

// TC O(2^n * n) SC O(n){recursive} + O(2^n * n) {to store the result}
// Approach : remeber that it is not necessary the next element is going to be taken it might not exist so include the subset at every call.