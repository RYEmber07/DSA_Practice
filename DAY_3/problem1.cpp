// 832. Flipping an Image
// https://leetcode.com/problems/flipping-an-image/description/?envType=problem-list-v2&envId=array

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
    {
        for (int i = 0; i < image.size(); i++)
        {
            reverse(image[i].begin(), image[i].end());
            for (int j = 0; j < image[i].size(); j++)
            {
                if (image[i][j] == 1)
                {
                    image[i][j] = 0;
                }
                else
                {
                    image[i][j] = 1;
                }
            }
        }
        return image;
    }
};