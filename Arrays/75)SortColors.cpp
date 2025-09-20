#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Dutch national flag algorithm

        int size = nums.size();
        int low = 0;
        int mid = 0;
        int high = size - 1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};