/*
    The problem is to find the max count of consecutive ones
    in an array of zeros and ones.
*/

#include <vector>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max_con = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            max_con = max(count, max_con);
        }
        return max_con;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums.at(i) == 1) {
                count++;
            } else {
                max_count = max_count > count ? max_count : count;
                count = 0;
            }
        }

        return max_count > count ? max_count : count;
    }
};