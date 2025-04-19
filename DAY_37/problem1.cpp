// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& temp, int num, int k, int n){
        if (k == 0){
            if (n != 0){ return; }
            ans.emplace_back(temp);
            return;
        }
        if (num > 9) return;
        temp.emplace_back(num);
        generate(temp, num + 1, k - 1, n - num);
        temp.pop_back();
        generate(temp, num + 1, k, n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        generate(temp, 1, k, n);
        return ans;
    }
};

// TC O(9Ck * k) SC O(k{recursive} + 9Ck*k{store the result}) , k is the no. of valid combinations
// Approach : Standard backtracking take not take approach with the condns given in question.