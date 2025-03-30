// 763. Partition Labels
// https://leetcode.com/problems/partition-labels/description/?envType=problem-list-v2&envId=string

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int lastOccurence[26] = { 0 };
        for (int i = 0;i < s.length();i++){
            lastOccurence[s[i] - 'a'] = i;
        }
        int i = 0;
        int start = 0, end = 0;
        while (i < s.length()){
            end = max(lastOccurence[s[i] - 'a'], end);
            if (i == end){
                ans.push_back(end - start + 1);
                start = end + 1;
            }
            i++;
        }
        return ans;
    }
};

// TC O(n) SC O(1)
// Approach : Hash the last occurences of all characters . 
// iterate over the string , mark the last occurence for that charcter using the end and update this end for each iteration to the max we can get start remaisn at the start of the partition whenever i is same as end or we can say the last occurence of the farthest occuring character has been met we have reached the partition. then change start to end+1 and push_back the length of the partition.