#include <vector>

using namespace std;

class Solution {
public:
    int calculateResult(vector<int>& nums, long long divisor) {
        int result = 0;
        for(const int& num: nums) {
            if(num % divisor == 0) 
                result = result + (num / divisor);
            else
                result = result + (num / divisor) + 1;
        }

        return result;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high) {
            long long mid = (low + high) / 2;

            int result = calculateResult(nums, mid);
            if(result <= threshold) 
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};