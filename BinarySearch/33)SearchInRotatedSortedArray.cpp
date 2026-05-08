#include <vector>

using namespace std;

//Not good solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int size = nums.size();
        int offset = 0;
        
        for(int i = 1; i < size; i++) {
            if(nums[i] < nums[i - 1]) {
                offset = i;
                break;
            }
        }

        int low = 0;
        int high = size - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            int idx = (mid + offset) % size;
            if(nums[idx] == target) {
                return idx;
            } else if(target > nums[idx]) low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int size = nums.size();
        
        int low = 0;
        int high = size - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;

            
            if(nums[low] <= nums[mid]) {
                //Left side is sorted
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                //Right side is sorted
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};