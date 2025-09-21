#include<vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return;
        int pivot = -1;

        for(int i = size - 2; i >= 0; i--) {
            if(nums[i] < nums[(i + 1)]) {
                pivot = i;
                break;
            }
        }

        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i = size - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};