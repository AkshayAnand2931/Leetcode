#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int expectedSum = size * (size + 1) / 2;
        int total = 0;
        for(auto num: nums) {
            total = total + num;
        }

        return expectedSum - total;
    }
};