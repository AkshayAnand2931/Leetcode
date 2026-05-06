#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int size = nums.size();
        vector<int> result;

        int element1 = INT_MIN;
        int count1 = 0;
        int element2 = INT_MIN;
        int count2 = 0;

        for(int i = 0; i < size; i++) {
            if(count1 == 0 and element2 != nums[i]) {
                element1 = nums[i];
            } else if(count2 == 0 && element1 != nums[i]) {
                element2 = nums[i];
            }
                
            if(nums[i] == element1) {
                count1++;
            } else if(nums[i] == element2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
                
        }
        
        int mini = size / 3;
        count1 = count2 = 0;

        for(int i = 0; i < size; i++) {
            if(nums[i] == element1)
                count1++;
            else if(nums[i] == element2)
                count2++;
        }

        if(count1 > mini)
            result.push_back(element1);
        if(count2 > mini) 
            result.push_back(element2);

        return result;
    }
};