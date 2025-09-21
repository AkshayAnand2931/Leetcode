#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int size = nums.size();

        for(int i = 0; i < size; i++) {
            set.insert(nums[i]);
        }

        int count = 0;
        int max_count = 0;
        for(auto num: set) {
            if(set.find(num - 1) == set.end()) {
                int j= 0;
                while(set.find(num + j) != set.end()) {
                    j++;
                    count++;
                }
                max_count = max(max_count, count);
                count = 0;
            }
        }
        return max_count;
    }
};