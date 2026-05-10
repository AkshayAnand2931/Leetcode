#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        const int size = arr.size();

        int low = 0;
        int high = size - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            int missing = arr[mid] - (mid + 1);
            if(k > missing)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low + k;
    }   
};