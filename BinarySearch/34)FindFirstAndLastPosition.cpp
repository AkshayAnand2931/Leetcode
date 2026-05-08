#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        const int size = nums.size();

        int low = 0;
        int high = size - 1;
        int lowerBound = -1;
        int upperBound = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                lowerBound = mid;
                high = mid - 1;
            } else if(target > nums[mid]) low = mid + 1;
            else high = mid - 1;;
        }

        low = 0;
        high = size - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) {
                upperBound = mid;
                low = mid + 1;
            } else if(target > nums[mid]) low = mid + 1;
            else high = mid - 1;;
        }

        result.push_back(lowerBound);
        result.push_back(upperBound);
        return result;

    }
};