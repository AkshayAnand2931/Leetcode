/*
    The problems asks to check if the array is sorted or sorted and then rotated.
    Rotated means that the values in the array were shifted in a circular manner.
*/

#include <vector>

class Solution
{
public:
    bool check(std::vector<int> &nums)
    {
        int count{0};

        for (int i = 0; i < nums.size(); i++)
        {
            int next = (i + 1) % nums.size();
            if (nums[next] - nums[i] < 0)
            {
                count++;
            }
        }

        if (count <= 1)
        {
            return true;
        }
        return false;
    }
};