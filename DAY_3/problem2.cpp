// 1128. Number of Equivalent Domino Pairs
// https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=problem-list-v2&envId=2030iluv

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> mpp;
        int count = 0;
        for (int i = 0;i < dominoes.size();i++){
            if (dominoes[i][0] > dominoes[i][1]){
                swap(dominoes[i][0], dominoes[i][1]);
            }
        }
        for (int i = 0;i < dominoes.size();i++){
            mpp[dominoes[i]]++;
        }
        for (auto it : mpp){
            count += (it.second) * (it.second - 1) / 2;
        }
        return count;
    }
};