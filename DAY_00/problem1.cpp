// 1929. Concatenation of Array
// https://leetcode.com/problems/concatenation-of-array/description/

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums.emplace_back(nums[i]);
        }
        return nums;
    }
};