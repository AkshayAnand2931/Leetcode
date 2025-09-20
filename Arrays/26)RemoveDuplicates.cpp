#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int actual = 0;
        int duplicate = 0;
        int count = 1;
        int size = nums.size();

        while(duplicate < size) {
            if(nums[actual] == nums[duplicate]) {
                duplicate++;
            } else {
                actual++;
                nums[actual] = nums[duplicate];
                count++;
            }
        }
        return count;
    }
};