// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& temp, vector<int>& candidates, int i, int target){
        if (i == candidates.size() || target < 0){ return; }
        if (target == 0){
            ans.push_back(temp);
            return;
        }

        temp.push_back(candidates[i]);
        generate(temp, candidates, i, target - candidates[i]);
        temp.pop_back();
        generate(temp, candidates, i + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        generate(temp, candidates, 0, target);
        return ans;
    }
};

// TC O(2^t * k) SC O(k * x)
// k : average len of combination , x : no. of combinations
// Approach : use a backtracking approach where first take the element and dont take the element