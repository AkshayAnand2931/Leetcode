#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high) {
            long long mid = (low + high) / 2;

            int subArray = numSubArray(nums, mid);

            if(subArray <= k) 
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }

private:
    int numSubArray(vector<int>& nums, long long sumLimit) {
        int sum = 0;
        int subArray = 0;

        for(const int& num: nums) {
            sum = sum + num;
            if(sum > sumLimit) {
                subArray++;
                sum = num;
            }
        }

        subArray++;

        return subArray;
    }
};