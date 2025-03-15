// 1560. Most Visited Sector in a Circular Track
// https://leetcode.com/problems/most-visited-sector-in-a-circular-track/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        int startSector = rounds[0];
        int endSector = rounds.back();

        if (endSector >= startSector){
            for (int i = startSector;i <= endSector;i++){
                ans.push_back(i);
            }
        }
        else{
            for (int i = startSector;i <= n;i++){
                ans.push_back(i);
            }
            for (int i = 1;i <= endSector;i++){
                ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};