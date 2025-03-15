// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/description/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            if (st.count(nums[i]) == 1)
            {
                return true;
            }
            else
            {
                st.insert(nums[i]);
            }
        }
        return false;
    }
};

// alternate approach using maps
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        for (auto it : mpp)
        {
            if (it.second >= 2)
            {
                return true;
            }
        }
        return false;
    }
};