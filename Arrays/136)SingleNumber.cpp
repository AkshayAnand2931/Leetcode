#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int totalXor = 0;
        for(auto num: nums) {
            totalXor = totalXor ^ num;
        }

        return totalXor;
    }
};