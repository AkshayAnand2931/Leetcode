#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> prefix(size);
        prefix[0] = nums[0];

        for(int i = 1; i < size; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        unordered_map<int, int> mp;

        int count = 0;

        for(int i = 0; i < size; i++) {
            if(prefix[i] == k) {
                count++;
            }

            if(mp.find(prefix[i] - k) != mp.end()) {
                count = count + mp[prefix[i] - k];
            }

            mp[prefix[i]]++;
        }

        return count;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> prefix_sum;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);

            if(sum == k)
                count++;

            if(prefix_sum.find(sum - k) != prefix_sum.end())
                count += prefix_sum[sum - k];
            
            prefix_sum[sum]++;
        }

        return count;
    }
};