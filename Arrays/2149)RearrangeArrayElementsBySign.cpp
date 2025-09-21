#include<vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        int positive = 0;
        int negative = 0;

        for(int i = 0; i < size; i++) {
            if(i % 2 == 0) {
                while(nums[positive] < 0) {
                    positive++;
                }
                result[i] = nums[positive];
                positive++;
            } else {
                while(nums[negative] > 0) {
                    negative++;
                }
                result[i] = nums[negative];
                negative++;
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        int positive = 0;
        int negative = 1;

        for(int i = 0; i < size; i++) {
            if(nums[i] > 0) {
                result[positive] = nums[i];
                positive = positive + 2;
            } else {
                result[negative] = nums[i];
                negative = negative + 2;
            }
        }

        return result;
    }
};