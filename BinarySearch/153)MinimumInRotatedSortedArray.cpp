#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        const int size = nums.size();
        int mini = INT_MAX;

        int low = 0;
        int high = size - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[low] <= nums[mid] && nums[mid] <= nums[high]) {
                //Both sides are sorted
                mini = mini < nums[low] ? mini : nums[low];
                break;
            }
            else if(nums[low] <= nums[mid]) {
                //Left side is sorted
                mini = mini < nums[low] ? mini : nums[low];
                low = mid + 1;
            } else {
                //Right side is sorted
                mini = mini < nums[mid] ? mini: nums[mid];
                high = mid - 1;
            }
        }

        return mini;
    }
};