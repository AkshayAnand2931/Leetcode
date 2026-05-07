#include <vector>

using namespace std;

class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++) {
            nums[i] = temp.at(i - low);
        }
    }

    int mergeSort(vector<int>& nums, int low, int high) {

        int count = 0;
        if(low < high) {
            int mid = (low + high) / 2;
            count += mergeSort(nums, low, mid);
            count += mergeSort(nums, mid + 1, high);
            int j = mid + 1;
            for(int i = low; i <= mid; i++) {
                while(j <= high && nums[i] > (2LL * nums[j])) {
                    j++;
                }
                count += j - (mid + 1);
            }
            merge(nums, low, mid, high);
        }
        
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }    
};