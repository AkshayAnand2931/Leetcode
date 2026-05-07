#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n == 0) return;

        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int end = m + n - 1;

        while(ptr2 >= 0) {
            if(ptr1 >=0  && nums1[ptr1] > nums2[ptr2]) {
                nums1[end] = nums1[ptr1];
                end--;
                ptr1--;
            } else {
                nums1[end] = nums2[ptr2];
                end--;
                ptr2--;
            }
        }
    }
};