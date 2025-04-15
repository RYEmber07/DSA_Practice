// 78. Subsets
// https://leetcode.com/problems/subsets/description/

class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& currSubset, vector<int>& nums, int i){
        if (i == nums.size()){
            ans.emplace_back(currSubset);
            return;
        }
        currSubset.emplace_back(nums[i]);
        generate(currSubset, nums, i + 1);
        currSubset.pop_back();
        generate(currSubset, nums, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currSubset;
        generate(currSubset, nums, 0);
        return ans;
    }
};

// TC O(n*2^n) {since we are emplacing vectors n is multiplied in TC} SC O(n+n) {recursive stack space + auxillary space to store the subset { (2^n)*n space will be used to return the ans}
// Approach : use a backtracking approach to do some work explore it then undo it then explore again whenever we hit the end emplace the result 