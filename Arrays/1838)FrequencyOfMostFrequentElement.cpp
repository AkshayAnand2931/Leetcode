#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int size = nums.size();
        int result = 0;
        long total = 0;
        while(right < size) {
            total = total + nums[right];
            long number = nums[right];
            if(number * (right - left + 1) > total + k) {
                total = total  - nums[left];
                left = left + 1;
            }
            
            result = max(result, right - left + 1);
            right = right + 1;
        }
        return result;
    }
};