#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int size = nums.size();
        int prefix = 1;
        int suffix = 1;
        int result = INT_MIN;

        for(int i  = 0; i < size; i++) {
            if(nums[i] == 0) {
                prefix = 1;
                result = max(result, 0);
            } else {
                prefix = prefix * nums[i];
                result = max(result, prefix);
            }
        }

        for(int i = size - 1; i > 0; i--) {
            if(nums[i] == 0) {
                suffix = 1;
                result = max(result, 0);
            } else {
                suffix = suffix * nums[i];
                result = max(result, suffix);
            }
        }

        return result;
    }
};