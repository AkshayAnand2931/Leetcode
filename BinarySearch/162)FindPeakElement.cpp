#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int size = nums.size();

        if(size == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[size - 1] > nums[size - 2]) return size - 1;

        int low = 1;
        int high = size - 2;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            
            if(nums[mid - 1] > nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};