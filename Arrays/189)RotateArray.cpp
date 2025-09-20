/*
    The problem is to rotate the given array to the right by k steps.
    Rotating means to shift all the elements to the right.
*/

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// Or manually do the reverse

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        int shift = k % size;

        int l = 0;
        int r = size - 1;
        while (r > l)
        {
            int temp = nums[r];
            nums[r] = nums[l];
            nums[l] = temp;
            l++;
            r--;
        }

        l = 0;
        r = shift - 1;
        while (r > l)
        {
            int temp = nums[r];
            nums[r] = nums[l];
            nums[l] = temp;
            l++;
            r--;
        }

        l = shift;
        r = size - 1;
        while (r > l)
        {
            int temp = nums[r];
            nums[r] = nums[l];
            nums[l] = temp;
            l++;
            r--;
        }
    }
};