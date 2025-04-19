// Subset Sums
// https://www.geeksforgeeks.org/problems/subset-sums2234/1

class Solution {
public:
    vector<int> ans;
    void generate(vector<int>& arr, int indx, int sum){
        if (indx == arr.size()){
            ans.emplace_back(sum);
            return;
        }
        generate(arr, indx + 1, sum + arr[indx]);
        generate(arr, indx + 1, sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        generate(arr, 0, 0);
        return ans;
    }
};

// TC O(2^n) SC O(n{recursive stack space}+2^n{store the ans})
// Approach : Take not take backtracking approach , do some work - explore it - undo it - explore.
