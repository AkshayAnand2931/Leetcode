#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's voting algorithm
        
        int size = nums.size();
        int element;
        int count = 0;

        for(int i = 0; i < size; i++) {
            if(count == 0) {
                element = nums[i];
            }

            if(nums[i] == element) {
                count++;
            } else {
                count--;
            }
        }

        return element;
    }
};