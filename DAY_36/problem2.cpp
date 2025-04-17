// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& temp, vector<int>& candidates, int indx, int target){
        if (target == 0){
            ans.push_back(temp);
            return;
        }
        else if (target < 0){ return; }

        for (int i = indx;i < candidates.size();i++){
            if (i > indx && candidates[i] == candidates[i - 1]){
                continue;
            }
            temp.push_back(candidates[i]);
            generate(temp, candidates, i + 1, target - candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        generate(temp, candidates, 0, target);
        return ans;
    }
};

// TC O(2^n * k) SC O(k * x)
// Approach : we use a loop which starts form indx to end to find the nth element of the combination , call for the next index 
// indx represents the starting i iterates over the rest .