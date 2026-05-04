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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums.at(i) != nums.at(j)) {
                j++;
                nums.at(j) = nums.at(i);
            }
        }

        return j + 1;
    }
};