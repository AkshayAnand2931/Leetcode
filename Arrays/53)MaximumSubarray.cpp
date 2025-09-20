#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(2, vector<int>(size));
        dp[0][0] = dp[1][0] = nums[0];

        for(int i = 1; i < size; i++) {
            dp[1][i] = max(nums[i], nums[i] + dp[1][i - 1]);
            dp[0][i] = max(dp[0][i - 1], dp[1][i]);
        }

        return dp[0][size - 1];
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size);
        dp[0] = nums[0];

        for(int i = 1; i < size; i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        int maxi = INT_MIN;

        for(int i = 0; i < size; i++) {
            sum = sum + nums[i];
            maxi = max(sum, maxi);

            if(sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};